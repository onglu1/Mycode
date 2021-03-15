#include <bits/stdc++.h>
#define Mid (l + r >> 1)
#define siz(x) tree[x].siz
#define val(x) tree[x].val
#define son(x, k) tree[x].son[k]
#define hash(x) tree[x].hash
#define fa(x) tree[x].fa
using namespace std;
int read() {
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
	return f * num;
}
const unsigned long long K = 1e9 + 7;
const int N = 2e6 + 1009;
struct node {
	int siz, fa, val, son[2];
	unsigned long long hash;
} tree[N];
char s[N];
int n, root, tot;
unsigned long long base[N];
void update(int x) {
	siz(x) = siz(son(x, 0)) + siz(son(x, 1)) + 1;
	hash(x) = hash(son(x, 1)) + base[siz(son(x, 1))] * val(x) + base[siz(son(x, 1)) + 1] * hash(son(x, 0));
}
int chk(int x) {
	return son(fa(x), 1) == x;
}
void build(int l, int r, int x) {
	if(l > r) return ;
	siz(Mid) = 1; fa(Mid) = x;
	son(x, Mid > x) = Mid;
	if(l == r) return ;
	build(l, Mid - 1, Mid);
	build(Mid + 1, r, Mid);
	update(Mid);
}
void rotate(int x){
	int y = fa(x), z = fa(y), k = chk(x), w = son(x, k ^ 1);
	son(y, k) = w; fa(w) = y;
	son(z, chk(y)) = x; fa(x) = z;
	son(x, k ^ 1) = y; fa(y) = x;
	update(y); update(x);
}
void splay(int x, int goal = 0){
	while(fa(x) != goal){
		int y = fa(x), z = fa(y);
		if(z != goal){
			if(chk(x) == chk(y))rotate(y);
			else rotate(x);
		}
		rotate(x);
	}
	update(x);
	if(!goal) root = x;
}
int Kth(int x) {
	int cur = root;
	while(1) {
		if(son(cur, 0) && siz(son(cur, 0)) >= x) cur = son(cur, 0);
		else if(siz(son(cur, 0)) + 1 == x) return cur;
		else x -= siz(son(cur, 0)) + 1, cur = son(cur, 1);
	}
}
void Insert(int x, int w) {
	int pre = Kth(x + 1), nxt = Kth(x + 2);
	splay(pre); splay(nxt, pre);
	son(nxt, 0) = ++tot;
	val(tot) = hash(tot) = w;
	fa(tot) = nxt; siz(tot) = 1;
	splay(tot);
}
void replace(int x, int w) {
	int pre = Kth(x + 1);
	splay(pre);
	val(pre) = w;
	update(pre);
}

void print(int x) {
	if(son(x, 0)) print(son(x, 0));
	 printf("%c ", val(x) - 1 + 'a');
	if(son(x, 1)) print(son(x, 1));
}
unsigned long long Hash(int l, int r) {
	int pre = Kth(l), nxt = Kth(r + 2);
	splay(pre); splay(nxt, pre);
	return hash(son(nxt, 0));
}
signed main()
{
	ios :: sync_with_stdio(0);
	base[0] = 1;
	for(int i = 1; i < N; i++) base[i] = base[i - 1] * K;
	cin >> (s + 1); n = strlen(s + 1);
	for(int i = 2; i <= n + 1; i++) val(i) = hash(i) = s[i - 1] - 'a' + 1;
	build(1, n + 2, root);
	root = n + 3 >> 1; tot = n + 2;
	int m;
	cin >> m;
	for(int i = 1; i <= m; i++) {
		char opt, p;
		int x, y;
		cin >> opt;
		if(opt == 'Q') {
			cin >> x >> y;
			if(x > y) swap(x, y);
			int l = 0, r = tot - y - 1;
			while(l <= r) {
				if(Hash(x, x + Mid - 1) == Hash(y, y + Mid - 1)) l = Mid + 1;
				else r = Mid - 1;
			}
			cout << r << endl;
		} 
		if(opt == 'R') {
			cin >> x >> p;
			replace(x, p - 'a' + 1);
		} 
		if(opt == 'I') {
			cin >> x >> p;
			Insert(x, p - 'a' + 1);
		}
	}

	return 0;
}
