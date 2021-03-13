#include <bits/stdc++.h>
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
int n, h[N], f[N], st1[N], t1, st2[N], t2;
int main()
{
	n = read();
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++) h[i] = read();
	st1[++t1] = 1; st2[++t2] = 1; f[1] = 0;
	for(int i = 2; i <= n; i++) {
		f[i] = f[i - 1] + 1;
		while(t1 && h[st1[t1]] < h[i]) f[i] = min(f[i], f[st1[t1]] + 1), t1--;
		while(t2 && h[st2[t2]] > h[i]) f[i] = min(f[i], f[st2[t2]] + 1), t2--;
		f[i] = min(f[i], min(f[st1[t1]], f[st2[t2]]) + 1);
		while(h[st1[t1]] == h[i]) t1--;
		while(h[st2[t2]] == h[i]) t2--;
		st1[++t1] = i; st2[++t2] = i;
	}
	printf("%d\n", f[n]);
	return 0;
}
