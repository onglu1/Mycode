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
const double eps = 1e-6;
struct Vector {int id, x, y;};
Vector a[500009];
int n, sta[500009], ans[500009], t;
int cmp(Vector a, Vector b) {
	if(a.x == b.x) return a.y > b.y;
	else return a.x > b.x;
}
double cal(Vector a, Vector b) {
	return 1.0 * (b.y - a.y) / (a.x - b.x);
}
signed main()
{
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i].x = read();
		a[i].y = read();
		a[i].id = i;
	}
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; i++) {
		if(a[i].x == a[sta[t]].x && i > 1) continue;
		while(t > 1 && cal(a[i], a[sta[t]]) >= cal(a[sta[t]], a[sta[t - 1]])) t--;
		sta[++t] = i;
		ans[t] = a[i].id;
	}
	sort(ans + 1, ans + 1 + t);
//	printf("%d\n", t);
	for(int i = 1; i <= t; i++) 
		printf("%d ", ans[i]);
	return 0;
}
