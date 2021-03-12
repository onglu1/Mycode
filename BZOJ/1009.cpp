#include <bits/stdc++.h>
#define Mid (l + r << 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define int long long

using namespace std;

int read() {
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
	return f * num;
}
int n, m, mod;
int a[29], nxt[29];
struct Mat {
	int g[29][29];
} A, B;
Mat operator * (const Mat &A, const Mat &B) {
	Mat C;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			C.g[i][j] = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < m; j++) {
			for(int k = 0; k < m; k++) {
				C.g[i][j] = (C.g[i][j] + A.g[i][k] * B.g[k][j] % mod) % mod;
			}
		}
	}
	return C;
}
signed main()
{
	n = read(); m = read(); mod = read();
	for(int i = 1; i <= m; i++)
		scanf("%1d", &a[i]);
	int j = 0;
	for(int i = 2; i <= m; i++) {
		while(j && a[j + 1] != a[i]) j = nxt[j];
		if(a[j + 1] == a[i]) j++;
		nxt[i] = j;
	}
	for(int i = 0; i < m; i++) {
		for(int p = 0; p <= 9; p++) {
			int j = i;
			while(j && a[j + 1] != p) j = nxt[j];
			if(a[j + 1] == p) j++;
			A.g[i][j]++;
		}
	}
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			B.g[i][j] = (i == j) ? 1 : 0;
	int x = n;
	for( ; x; x >>= 1, A = A * A)
		if(x & 1)
			B = A * B;
	int ans = 0;
	for(int i = 0; i < m; i++)
		ans = (ans + B.g[0][i]) % mod;
	printf("%lld\n", ans);
	return 0;
}
