#include <bits/stdc++.h>
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
const int N = 3e5 + 1009;
int n, mod, p, tot, a[N], t, q[N], pre[N];
int fid(int x) {return x == pre[x] ? x : (pre[x] = fid(pre[x]));}
signed main()
{
	ios :: sync_with_stdio(0);
	cin >> n >> mod;
	p = tot = t = 0;
	for(int i = 1; i <= n; i++) {
		char c; 
		int x;
		cin >> c >> x;
		if(c == 'A') {
			x = (x + p) % mod;
			a[++tot] = x; pre[tot] = tot;
			while(t && a[q[t]] <= x) pre[fid(q[t])] = tot, t--;
			q[++t] = tot;
		} else {
			p = a[fid(tot - x + 1)];
			cout << p << endl;
		}
	}
	return 0;
}
