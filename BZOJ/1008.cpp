#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 100003;
int n, m;
int Pow(int a, int x) {
	int ans = 1;
	for( ; x; x >>= 1, a = a * a % mod)
		if(x & 1)
			ans = ans * a % mod;
	return ans % mod;
}
signed main()
{
	scanf("%lld%lld", &m, &n);
	printf("%lld\n", (Pow(m, n) + mod - m * Pow(m - 1, n - 1) % mod) % mod);
	return 0;
}
