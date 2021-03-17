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
const int N = 4e5 + 1009;
int n, m, pre[N], res, vis[N], a[N], k, ans[N];
vector<int> v[N];
int fid(int x) {return pre[x] == x ? x : (pre[x] = fid(pre[x]));}
signed main()
{
	n = read(); m = read();
	for(int i = 1; i <= n; i++) pre[i] = i;
	for(int i = 1; i <= m; i++) {
		int x, y;
		x = read() + 1; y = read() + 1;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	k = read(); res = n;
	for(int i = 1; i <= k; i++) {
		a[i] = read() + 1;
		vis[a[i]] = 1;
		res--;
	}
	for(int i = 1; i <= n; i++) if(!vis[i]){
		for(auto j : v[i]) if(!vis[j]){
			if(fid(i) != fid(j)) {
				res--;
				pre[fid(i)] = fid(j);
			}
		}
	}
	for(int i = k; i; i--) {
		ans[i] = res;
		vis[a[i]] = 0;
		res++;
		for(auto j : v[a[i]]) if(!vis[j]) {
			if(fid(a[i]) != fid(j)) {
				res--;
				pre[fid(a[i])] = fid(j);
			}
		}
	}
	ans[0] = res;
	for(int i = 0; i <= k; i++) printf("%d\n", ans[i]);
	return 0;
}
