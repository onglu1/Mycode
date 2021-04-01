#include <bits/stdc++.h>
#define int long long
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
const int N = 2e5 + 1009;
int n, m, opt[N], t[N], ans;
signed main()
{
	n = read(); m = read();
	for(int i = 1; i <= n; i++) {
		char c[5];
		scanf("%s", c);
		if(c[0] == 'A') opt[i] = 0;
		else if(c[0] == 'O') opt[i] = 1;
		else if(c[0] == 'X') opt[i] = 2;
		t[i] = read();
	}
	for(int i = 30; i >= 0; i--) {
		int p = 0, q = 1;
		for(int j = 1; j <= n; j++) 
			if(opt[j] == 0) p = p & ((t[j] >> i) & 1), q = q & ((t[j] >> i) & 1);
			else if(opt[j] == 1) p = p | ((t[j] >> i) & 1), q = q | ((t[j] >> i) & 1);
			else if(opt[j] == 2) p = p ^ ((t[j] >> i) & 1), q = q ^ ((t[j] >> i) & 1);
		if(p == 1) 
			ans += (1 << i);
		else if(q == 1 && m >= (1 << i)) {
			m -= (1 << i);
			ans += (1 << i);
		}
	} 
	printf("%d\n", ans);
	return 0;
}
/*
依次确定每一位上的数字即可。
显然大的尽可能大
对于每一位我们判断他是0或者1，最终能造成0或者1的伤害

*/
