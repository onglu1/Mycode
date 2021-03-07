#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define Mid ((l + r) >> 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int base = 2e5 + 9;
int read(){
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';;
	return f * num;
}
int n, m, p, sum, ans;
int f[2][base * 2], a[base];
int main()
{
	n = read(); m = read();
	for(int i = 1; i <= n; i++){
		int x = read();
		if(x < m) a[i] = -1;
		else if(x > m) a[i] = 1;
		else a[i] = 0, p = i;
	}
	sum = 0;
	for(int i = p - 1; i; i--){
		sum += a[i];
		f[(p - i) & 1][sum + base]++;
	}
	sum = 0; ans = 0;
	for(int i = p + 1; i <= n; i++){
		sum += a[i];
		if(!sum) ans++;
		ans += f[(i - p) & 1][base - sum];
	}
	printf("%d\n", ans + f[0][base] + 1);
	return 0;
}
/*
从这个位置向左向右出发
肯定要包含这个点
向右出发，以右边为顶点然后向左查询合法的方案数
只需要知道奇数和偶数分别的数组就行了
预处理出从这个点到左端点，和为x
*/
