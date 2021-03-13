#include <iostream>
#include <cstdio>
#define Mid (l + r >> 1)
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
const int N = 2e5 + 1009;
int l[N], r[N], st[N], t, h[N], n;
void work() {
	for(int i = 1; i <= n; i++) h[i] = read();
	st[0] = 0; t = 0;
	for(int i = 1; i <= n; i++) {
		while(t && h[st[t]] >= h[i]) t--;
		l[i] = st[t] + 1;
		st[++t] = i;
	}
	st[0] = n + 1; t = 0;
	for(int i = n; i; i--) {
		while(t && h[st[t]] >= h[i]) t--;
		r[i] = st[t] - 1;
		st[++t] = i;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = max(ans, h[i] * (r[i] - l[i] + 1));
	}
	printf("%lld\n", ans);
}
signed main()
{
	while(n = read()) work();
	return 0;
}
