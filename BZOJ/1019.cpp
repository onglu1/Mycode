#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
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
int n, f[4][39], g[4][39];
pii a[10];
void dfs(int x, int cnt) {
	if(f[x][cnt] != -1) return ;
	f[x][cnt] = 0;
	if(cnt == 1) {
		f[x][cnt] = 1;
		for(int i = 1; i <= 6; i++) {
			if(a[i].first == x) {
				g[x][cnt] = a[i].second;
				break;
			}
		}
		return ;
	}
	dfs(x, cnt - 1);
	int nowup = g[x][cnt - 1], nowdown = x;
	f[x][cnt] += f[x][cnt - 1];
	do{
		nowdown = 6 - nowdown - nowup;
		f[x][cnt] += 1;
		dfs(nowup, cnt - 1);
		f[x][cnt] += f[nowup][cnt - 1];
		nowup = g[nowup][cnt - 1];
	} while(nowup != nowdown);
	g[x][cnt] = nowdown;
	return ;
}
signed main()
{
	n = read();
	memset(f, -1, sizeof(f));
	for(int i = 1; i <= 6; i++) {
		char c[10];
		scanf("%s", c + 1);
		a[i].first = c[1] - 'A' + 1;
		a[i].second = c[2] - 'A' + 1;
	}
	dfs(1, n);
	printf("%lld\n", f[1][n]);
	return 0;
}
/*
汉诺塔问题
动的肯定是上面一群最小的
所以可以随意移动
f[i][x]表示把第i个柱子上x个盘子移动到另一个柱子需要多少步
g[i][x]表示把第i个柱子上x个盘子移动到的是哪一个柱子
显然，移动的最后一步是小盘子的最上面一个
移动完之后，只有大盘子可以动
好像也不对，在移动中，大盘子可能会移动
大盘子不可能移动！
因为只有最后一步之后，才会有一个空柱子

*/
