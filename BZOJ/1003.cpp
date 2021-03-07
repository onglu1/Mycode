#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define Mid ((l + r) >> 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int read(){
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';;
	return f * num;
}
int g[29][29], g1[29][29], n, m, d, k, e;
int vis[109][29], f[109], ok[109];
void floyd(){
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= m; j++)
			g1[i][j] = g[i][j];
	for(int k = 1; k <= m; k++)if(ok[k])
		for(int i = 1; i <= m; i++)if(g1[i][k] != 0x3f3f3f3f)
			for(int j = 1; j <= m; j++)if(g1[k][j] != 0x3f3f3f3f)
				g1[i][j] = min(g1[i][j], g1[i][k] + g1[k][j]);
}
int main()
{
	n = read(); m = read();
	k = read(); e = read();
	memset(g, 0x3f, sizeof(g));
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= m; i++)
		g[i][i] = 0;
	for(int i = 1; i <= e; i++){
		int x = read(), y = read();
		g[x][y] = g[y][x] = min(g[x][y], read());
	}
	d = read();
	for(int i = 1; i <= d; i++){
		int p = read(), l, r;
		l = read(); r = read();
		for(int j = l; j <= r; j++){
			vis[j][p] = 1;
		}
	}
	f[0] = 0;
	for(int i = 1; i <= n; i++){
		//前i天
		for(int j = 1; j <= m; j++)
			ok[j] = 1;
		for(int j = i - 1; j >= 0; j--){
			for(int k = 1; k <= m; k++)
				if(vis[j + 1][k]) 
					ok[k] = 0;		
			floyd();
			if(g1[1][m] != 0x3f3f3f3f){
				if(j != 0) f[i] = min(f[i], k + f[j] + g1[1][m] * (i - j));
				else f[i] = min(f[i], f[j] + g1[1][m] * (i - j));
			}
		}
		//cout << f[i] << endl;
	}
	printf("%d\n", f[n]);
	return 0;
}
/*
如何最小化
对于一段时间
我们可以求出这段时间哪些港口可以访问
然后我们可以在这些港口可以访问的基础上求floyd最短路
可以求出一天的最短

*/
