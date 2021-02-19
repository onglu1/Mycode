#include <iostream>
#include <queue>
#include <cstdio>
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
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
struct node {
	int x, y, dis;
};
bool operator <(const node &a, const node &b) {return a.dis > b.dis;}
priority_queue<node> q;
int n, m, g[309][309], xx, yy, vis[309][309];
signed main()
{
	while(1) {
		n = read(); m = read();
		if(n == 0 && m == 0) break;
		while(q.size()) q.pop();
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				char c;
				cin >> c;
				vis[i][j] = 0x3f3f3f3f;
				if(c == 'R' || c == 'S') g[i][j] = -1;
				if(c == 'B') g[i][j] = 2;
				if(c == 'E' || c == 'Y' || c == 'T') g[i][j] = 1;
				if(c == 'Y') q.push((node) {i, j, 0}), vis[i][j] = 0;
				if(c == 'T') xx = i, yy = j;
			}
		}
		int f = 0;
		while(q.size()) {
			int x = q.top().x, y = q.top().y, dis = q.top().dis; q.pop();
			if(dis != vis[x][y]) continue;
			if(x == xx && y == yy) {
				printf("%d\n", dis);
				f = 1;
				break;
			}
			for(int i = 0; i < 4; i++) {
				int nx, ny;
				nx = x + dx[i];
				ny = y + dy[i];
				if(nx > n || nx < 1 || ny > m || ny < 1 || g[nx][ny] == -1) continue;
				if(dis + g[nx][ny] >= vis[nx][ny]) continue;
				vis[nx][ny] = dis + g[nx][ny];
				q.push((node) {nx, ny, vis[nx][ny]});
			}
		}
		if(!f) printf("-1\n");
	}
	return 0;
}
