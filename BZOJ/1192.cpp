#include <bits/stdc++.h>
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

int main()
{
	int cnt = 0, n = read(), now = 1;
	while(now < n){
		cnt++;
		n -= now;
		now <<= 1;
	}
	if(n) cnt++;
	cout << cnt << endl;
	return 0;
}
