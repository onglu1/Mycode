#include <bits/stdc++.h>
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
int dp[20][2][20][2];
int a[1009], cnt;
int dfs(int res, int f, int lst, int limit) {
	if(dp[res][f][lst][limit] != -1) return dp[res][f][lst][limit];
	dp[res][f][lst][limit] = 0;
	if(res == 0) return dp[res][f][lst][limit] = 1;
	for(int i = 0; i < 10; i++) {
		if(i == 0) {
			if(f == 1) dp[res][f][lst][limit] += dfs(res - 1, 1, 0, 0);
			else if(lst >= 2) dp[res][f][lst][limit] += dfs(res - 1, 0, 0, limit && (i == a[res]));
		} else if(limit && i <= a[res]) {
			if(f == 1) dp[res][f][lst][limit] += dfs(res - 1, 0, i, limit && (i == a[res]));
			else if(abs(i - lst) >= 2) dp[res][f][lst][limit] += dfs(res - 1, 0, i, limit && (i == a[res]));
		} else if(!limit) {
			if(f == 1 || abs(i - lst) >= 2)
				dp[res][f][lst][limit] += dfs(res - 1, 0, i, 0);
		}
	}
	return dp[res][f][lst][limit];
}
signed main()
{

	int l = read() - 1, r = read();
	int cntl, cntr;
	cnt = 0;
	while(r > 0) a[++cnt] = r % 10, r /= 10;
	memset(dp, -1, sizeof(dp));
	cntr = dfs(cnt, 1, 0, 1);
	cnt = 0;
	while(l > 0) a[++cnt] = l % 10, l /= 10;
	memset(dp, -1, sizeof(dp));
	cntl = dfs(cnt, 1, 0, 1);
	printf("%d\n", cntr - cntl);
	return 0;
}
/*
不含前导0且相邻差为2
dfs(i, f, lst, limit)
表示第i位，是否有前导0，前面一个数是多少，是否碰到上限的方案数
*/
