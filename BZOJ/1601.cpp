#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define Mid ((l + r) >> 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int read(){
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';;
	return f * num;
}
const int N = 5e5 + 1009;
struct edge{
	int x, y, w;
}p[N];
int n, pre[N], tot = 0, ans;
int fid(int x){
	return pre[x] == x ? x : pre[x] = fid(pre[x]);
}
bool cmp(edge a, edge b){
	return a.w < b.w;
}
main()
{
	n = read();
	for(int i = 1; i <= n + 1; i++) pre[i] = i;
	for(int i = 1; i <= n; i++)
		p[++tot] = (edge){i, n + 1, read()};
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int w = read();
			if(i < j)
				p[++tot] = (edge){i, j, w};
		}
	}
	sort(p + 1, p + 1 + tot, cmp);
	for(int i = 1; i <= tot; i++){
		if(fid(p[i].x) != fid(p[i].y)){
			pre[fid(p[i].x)] = fid(p[i].y);
			ans += p[i].w;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
