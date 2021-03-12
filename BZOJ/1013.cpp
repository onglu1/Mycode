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
const double eps = 1e-5;
int n;
double g[19][19], a[19][19];
int main()
{
	n = read();
	for(int i = 1; i <= n + 1; i++) 
		for(int j = 1; j <= n; j++) 
			cin >> a[i][j];
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			g[i][j] = a[i + 1][j] - a[i][j];
			g[i][n + 1] += a[i + 1][j] * a[i + 1][j] - a[i][j] * a[i][j];
		}
		g[i][n + 1] /= 2.0;
	}
	for(int i = 1; i <= n; i++) {
		if(fabs(g[i][i]) < eps) {
			for(int j = i + 1; j <= n; j++) if(fabs(g[j][i]) > eps){
				for(int k = i; k <= n + 1; k++) {
					double tmp = g[j][k];
					g[j][k] = g[i][k];
					g[i][k] = tmp;
				}
			}
		}
		double base = 1.0 / g[i][i];
		for(int j = i; j <= n + 1; j++)
			g[i][j] *= base;
		for(int j = 1; j <= n; j++) if(j != i && fabs(g[j][i]) > eps) {
			base = g[j][i];
			for(int k = i; k <= n + 1; k++) {
				g[j][k] -= base * g[i][k];
			}
		}
	}
	for(int i = 1; i <= n; i++)
		printf("%.3f ", g[i][n + 1]);
	return 0;
}
