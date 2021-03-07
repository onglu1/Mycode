#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ull unsigned long long
#define Mid ((l + r) >> 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int base = 2e5 + 9;
int read(){
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';;
	return f * num;
}
int n, h, d;
int g[5009][2009], maxn[2009], f[5009][2009];
main()
{
	n = read(); h = read(); d = read();
	for(int i = 1; i <= n; i++){
		int p = read();
		for(int j = 1; j <= p; j++)
			g[i][read()]++;
	}
	for(int i = 1; i <= n; i++)
		f[i][h] = g[i][h],
		maxn[h] = max(maxn[h], f[i][h]);
	for(int j = h - 1; j; j--){
		for(int i = 1; i <= n; i++){
			f[i][j] = f[i][j + 1] + g[i][j];
			if(j + d <= h)
				f[i][j] = max(f[i][j], g[i][j] + maxn[j + d]);
			maxn[j] = max(maxn[j], f[i][j]);
		}
	}
	printf("%lld\n", maxn[1]);
	return 0;
}
