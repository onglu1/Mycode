#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
int read(){
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
	return f * num;
}
struct node {
	int i, j, v, f;
};
int n, m, a[2009], b[2009], c[2009];
bool operator<(const node &x, const node &y) {return x.v > y.v;}
priority_queue<node> q;
void work() {
	n = read(); m = read();
	for(int i = 1; i <= m; i++) a[i] = read();
	sort(a + 1, a + 1 + m);
	for(int qwq = 2; qwq <= n; qwq++) {
		for(int i = 1; i <= m; i++) b[i] = read();
		sort(b + 1, b + 1 + m);
		while(q.size()) q.pop();
		q.push((node){1, 1, a[1] + b[1], false});
		for(int i = 1; i <= m; i++) {
			int x = q.top().i, y = q.top().j, v = q.top().v, f = q.top().f;
			q.pop();
			c[i] = v;
			if(y + 1 <= m) q.push((node){x, y + 1, a[x] + b[y + 1], true});
			if(!f && x + 1 <= m) q.push((node){x + 1, y, a[x + 1] + b[y], false}); 
		}
		for(int i = 1; i <= m; i++)
			a[i] = c[i];
	}
	for(int i = 1; i <= m; i++) 
		printf("%lld ", a[i]);
	printf("\n");
}
signed main()
{
	int Case = read();
	while(Case--) work();
	return 0;
}
