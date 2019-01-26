#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define Mid ((l+r)<<1)
using namespace std;
ll read(){
	char c;ll num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int main()
{
	ll n=read(),x=read(),y,a=0,b=0;
	for(int i=2;i<=n;i++){
		y=read();
		if(y>x)a+=y-x;
		else b+=x-y;
		x=y;
	}
	printf("%lld\n%lld\n",max(a,b),max(a,b)-min(a,b)+1);
	return 0;
}

