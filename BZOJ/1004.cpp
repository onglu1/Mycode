#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#define int long long
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
const int N = 69;
int r, g, b, n, m, p, tot;
int tr[N], f[N][N][N], len[N], vis[N];
//len[i]表示第i个循环置换的长度
void up(int &x, int y) { x = (x + y) % p; }
int cal() {
	tot = 0;
	for(int i = 0; i <= r; i++) for(int j = 0; j <= b; j++) for(int k = 0; k <= g; k++) f[i][j][k] = 0;
	for(int i = 1; i <= n; i++) vis[i] = 0;
	for(int i = 1; i <= n; i++) if(!vis[i]){
		int now = i, l = 0;
		while(!vis[now]) {
			vis[now] = 1;
			l++;
			now = tr[now];
		}
		len[++tot] = l;
	}
	f[0][0][0] = 1;
	for(int i = 1; i <= tot; i++) for(int nr = r; ~nr; nr--) for(int nb = b; ~nb; nb--) for(int ng = g; ~ng; ng--){
		if(nr >= len[i]) up(f[nr][nb][ng], f[nr - len[i]][nb][ng]);
		if(nb >= len[i]) up(f[nr][nb][ng], f[nr][nb - len[i]][ng]);
		if(ng >= len[i]) up(f[nr][nb][ng], f[nr][nb][ng - len[i]]);
	}
	return f[r][b][g];
}
int Pow(int a, int x) {
	int ans = 1;
	for( ; x; a = 1ll * a * a % p, x >>= 1)
		if(x & 1)
			ans = 1ll * ans * a % p;
	return ans % p;
}
signed main()
{
//	freopen("2.in", "r", stdin);
	int ans = 0;
	r = read(); b = read(); g = read(); n = r + b + g;
	m = read(); p = read();
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) tr[j] = read();		
		up(ans, cal());
	}
	for(int i = 1; i <= n; i++) tr[i] = i;
	up(ans, cal());
	printf("%lld\n", (1ll * ans * Pow(m + 1, p - 2) % p));
	return 0;
}
/*
有m + 1种置换方式，而且组成置换群
总的方案数 = 每个置换的不动点数量 / (m + 1)
求不动点用到背包
把整个置换拆分成一系列循环置换，每个循环置换里面的颜色都必须是一样的
*/
