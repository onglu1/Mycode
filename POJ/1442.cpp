#include <bits/stdc++.h>
#define int long long
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
priority_queue<int> q1, q2;
int n, m, k, a[1000009];
signed main()
{
	int now = 0;
	m = read(); n = read();
	for(int i = 1; i <= m; i++) a[i] = read();
	for(int i = 1; i <= n; i++) {
		int u = read(); 
		while(now < u) {
			now++;
			if(q1.size() && a[now] < q1.top()) {
				q2.push(-q1.top());
				q1.pop();
				q1.push(a[now]);
			} else q2.push(-a[now]);
		}
		q1.push(-q2.top());
		q2.pop();
		printf("%d\n", q1.top());
	}
	return 0;
}
