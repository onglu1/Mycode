#include <bits/stdc++.h>
#define Mid ((l + r) >> 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1)

using namespace std;

int read(){
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
	return f * num;
}
const int N = 6e6 + 1009;
const int inf = 0x3f3f3f3f;
int n, m, g[3009][3009], s, t, d[N];
int head[N], nxt[N], ver[N], edge[N], tot = 1;
void add(int x, int y, int w) {
	nxt[++tot] = head[x]; head[x] = tot; ver[tot] = y; edge[tot] = w;
}
int bfs() {
	memset(d, 0, sizeof(d)); d[s] = 1;
	queue<int> q; q.push(s);
	while(q.size()) {
		int x = q.front(); q.pop();
		for(int i = head[x]; i; i = nxt[i]) {
			if(edge[i] <= 0 || d[ver[i]]) continue;
			d[ver[i]] = d[x] + 1;
			q.push(ver[i]);
		}
	}
	if(!d[t]) return false;
	return true;
}
int dfs(int x, int flow) {
	if(x == t) return flow;
	int k, res = flow;
	for(int i = head[x]; i && res; i = nxt[i]) {
		if(edge[i] <= 0 || d[ver[i]] != d[x] + 1) continue;
		k = dfs(ver[i], min(res, edge[i]));
		if(!k) d[ver[i]] = 0;
		edge[i] -= k;
		edge[i ^ 1] += k;
		res -= k;		
	}
	return flow - res;	
}
signed main()
{
//	freopen("5.in", "r", stdin);
	n = read(); m = read();
	for(int i = 1, cnt = 0; i <= n; i++) 
		for(int j = 1; j <= m; j++) 
			g[i][j] = ++cnt;
	s = g[1][1]; t = g[n][m];		
	for(int i = 1; i <= n; i++) {
		for(int j = 2; j <= m; j++) {
			int x = read();
			add(g[i][j - 1], g[i][j], x);
			add(g[i][j], g[i][j - 1], x);
		}
	}
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int x = read();
			add(g[i - 1][j], g[i][j], x);
			add(g[i][j], g[i - 1][j], x);
		}
	}
	for(int i = 2; i <= n; i++) {
		for(int j = 2; j <= m; j++) {
			int x = read();
			add(g[i - 1][j - 1], g[i][j], x);
			add(g[i][j], g[i - 1][j - 1], x);
		}
	}
	int maxflow = 0;
	while(bfs()) 
		maxflow += dfs(s, inf);
	printf("%d\n", maxflow);
	return 0;
}
