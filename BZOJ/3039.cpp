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
int n, m, g[1009][1009];
int h[1009], l[1009], r[1009];
int s[1009], t, ans;
main()
{
	n = read(); m = read();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char c;
			cin >> c;
			g[i][j] = c == 'F';
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			if(g[i][j]) h[j]++;
			else h[j] = 0;
		t = 0;
		for(int j = 1; j <= m; j++){
			while(h[s[t]] >= h[j] && t) t--;
			l[j] = s[t];
			s[++t] = j;
		}
		t = 0;
		for(int j = m; j; j--){
			while(h[s[t]] >= h[j] && t) t--;
			if(t == 0) r[j] = m + 1;
			else r[j] = s[t];
			ans = max(ans, h[j] * 3 * (r[j] - l[j] - 1));
			s[++t] = j;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
