#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#define Mid ((l + r) >> 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1)

using namespace std;

int read(){
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
	return f * num;
}
const int N = 5009;
int n, d[N], cnt, res, pri[N], ans[N], len = 1;
void update(int x, int f) {
	for(int i = 2; i * i <= x; i++) while(x % i == 0) {
		pri[i] += f;
		x /= i;
	}
	if(x > 1) pri[x] += f;
}
int A(int n, int m, int f) {
	for(int i = n; i > n - m; i--)
		update(i, f);
}
void times(int x) {
	for(int i = 1; i <= len; i++) ans[i] *= x;
	for(int i = 1; i < len; i++) {
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}
	while(ans[len] >= 10) {
		ans[len + 1] = ans[len] / 10;
		ans[len] %= 10;
		len++;
	}
}
void print() {
	for(int i = len; i; i--)
		printf("%d", ans[i]);
}
signed main()
{
	n = read();
	for(int i = 1; i <= n; i++) {
		d[i] = read();
		if(d[i] == -1) cnt++;
		else {
			if(d[i] == 0) {
				if(n == 1) printf("1\n");
				else printf("0\n");
				return 0;
			}
			d[i]--;
			res += d[i];
		}
	}
	if(res > n - 2) {
		printf("0\n");
		return 0;
	}
	ans[1] = 1;
	A(n - 2, res, 1);
	for(int i = 1; i <= n; i++) 
		if(d[i] != -1) 
			A(d[i], d[i], -1);
	for(int i = 2; i <= 1000; i++)
		for(int j = 1; j <= pri[i]; j++)
			times(i);
	for(int i = 1; i <= n - 2 - res; i++)
		times(cnt);
	print();
	return 0;
}
