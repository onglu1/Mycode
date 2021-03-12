#include <bits/stdc++.h>
#define Mid (l + r << 1)
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
int n, m[N];
double a;
signed main()
{
	n = read(); scanf("%lf", &a);
	for(int i = 1; i <= n; i++) m[i] = read() + m[i - 1];
	for(int i = 1; i <= n; i++) {
		int x = i * a + (1e-6);
		double ans = 0;
		if(x <= 100) {
			for(int j = 1; j <= x; j++) 
				ans = ans + 1.0 * (m[i] - m[i - 1]) * (m[j] - m[j - 1]) / (i - j);
			printf("%.5f ", ans);
		} else {
			int j;
			for(j = 100; j <= x; j += 100) 
				ans = ans + 1.0 * (m[i] - m[i - 1]) * (m[j] - m[j - 100]) / (i - (j + j - 100) / 2);
			j -= 100;
			for( ; j <= x; j++)
				ans = ans + 1.0 * (m[i] - m[i - 1]) * (m[j] - m[j - 1]) / (i - j);
			printf("%.5f ", ans);
		}
		
	}
	return 0;
}
