#include <bits/stdc++.h>
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int read() {
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
	return f * num;
}
const int N = 509;
int n, a[N], g[N][N];
signed main()
{
	memset(g, 0x3f, sizeof(g));
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) g[i][i] = 2;
	for(int len = 2; len <= n; len++) {
		for(int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			for(int k = i + 1; k <= j; k++) 
				g[i][j] = min(g[i][j], g[i][k - 1] + g[k][j]);
			int l = i, r = j;
			if(a[l] != a[r]) continue;
			while(l < j && a[l + 1] == a[l]) l++;
			while(r > i && a[r - 1] == a[r]) r--;
			if(l == j) g[i][j] = min(g[i][j], (j - i + 1) >= 2 ? 1 : (3 - (j - i + 1)));
			else {
				if((l - i + 1) + (j - r + 1) >= 3) g[i][j] = min(g[i][j], g[l + 1][r - 1]);
				else g[i][j] = min(g[i][j], g[l + 1][r - 1] + 3 - ((l - i + 1) + (j - r + 1)));
			}
		}
	}
	printf("%d\n", g[1][n]);
	return 0;
}
