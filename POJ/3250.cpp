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
int n, h[N], s[N], t, ans;
signed main()
{
	n = read();
	for(int i = 1; i <= n; i++) h[i] = read();
	s[0] = n + 1;
	for(int i = n; i; i--) {
		while(t && h[s[t]] < h[i]) t--;
		ans += s[t] - i - 1;
		s[++t] = i;
	}
	printf("%lld\n", ans);
	return 0;
}
