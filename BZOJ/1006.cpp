#include <bits/stdc++.h>
#define Mid ((l + r) >> 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1) 

using namespace std;

int read() {
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
	return f * num;
}
const int N = 2e6 + 1009;
vector<int> v[N];
int n, m, id[N], rnk[N], num[N], tmp[N];
int head[N], nxt[N], ver[N], tot = 1;
void add(int x, int y) {
	ver[++tot] = y; nxt[tot] = head[x]; head[x] = tot;
}

int work() {
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read();
		add(x, y); add(y, x);
	}
	for(int i = 1; i <= n + 1; i++) v[i].clear();
	for(int i = 1; i <= n; i++) v[1].push_back(i);
	int maxn = 1;
	for(int cnt = n; cnt; cnt--) {
		int f = 0, x;
		while(!f) {
			for(int i = v[maxn].size() - 1; i >= 0; i--) {
				x = v[maxn][i];
				if(rnk[x]) v[maxn].pop_back();
				else {f = 1; break;}
			}
			if(!f) maxn--;
		}
		rnk[x] = cnt; id[cnt] = x;
		for(int i = head[x]; i; i = nxt[i]) {
			if(!rnk[ver[i]]) 
				v[++num[ver[i]]].push_back(ver[i]),
				maxn = max(maxn, num[ver[i]]);
		}
	}
	int maxsiz = 1;
	for(int q = 1; q <= n; q++) {
		int x = id[q], ntot = 0;
		for(int i = head[x]; i; i = nxt[i]) {
			if(rnk[ver[i]] > rnk[x])
				ntot++;
		}
		maxsiz = max(maxsiz, ntot + 1);
	}
	return maxsiz;
}
int main()
{
	n = read(); m = read();
	printf("%d\n", work());
	return 0;
}
/*
弦图最大团
*/
