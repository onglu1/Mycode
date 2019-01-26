#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define Mid ((l+r)<<1)
using namespace std;
const int N=2e6+1009;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,a[N],mid,ans;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	if(n&1)mid=a[(n+1)/2];
	else mid=a[n/2];
	for(int i=1;i<=n;i++)
		ans+=abs(mid-a[i]);
	printf("%d\n",ans);
	return 0;
}
