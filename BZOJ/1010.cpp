#include <bits/stdc++.h>
#define int long long
#define Mid (l + r >> 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int read() {
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
	return f * num;
}
const int N = 5e5 + 1009;
int n, L, A[N], B[N], sum[N];
int f[N];
int q[N], h, t;
int cal(int i, int j) {
	return f[j] + (B[j] - A[i]) * (B[j] - A[i]);
}
int slope(int i, int j, int k) {
	int X1 = 2ll * B[i], Y1 = f[i] + B[i] * B[i];
	int X2 = 2ll * B[j], Y2 = f[j] + B[j] * B[j];
	int X3 = 2ll * B[k], Y3 = f[k] + B[k] * B[k];
	return (X1 - X2) * (Y2 - Y3) < (X2 - X3) * (Y1 - Y2);
}
signed main()
{
	n = read(); L = read();
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + read();
	for(int i = 0; i <= n; i++) {
		A[i] = sum[i] + i;
		B[i] = sum[i] + i + 1 + L;
	}
	f[0] = 0; 
	t = h = 1;
	q[1] = 0;
	for(int i = 1; i <= n; i++) {
		while(h < t && cal(i, q[h]) >= cal(i, q[h + 1])) h++;
		f[i] = cal(i, q[h]);
		while(h < t && slope(q[t - 1], q[t], i)) t--;
		q[++t] = i;
	}
	printf("%lld\n", f[n]);
	return 0;
}
