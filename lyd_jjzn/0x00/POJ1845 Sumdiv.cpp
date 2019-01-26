#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define ll long long
#define ull unsigned long long
#define Mid ((l+r)<<1)
using namespace std;
const int N=2e7+1009;
const ll mod=9901;
ll read(){
	char c;ll num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
ll a,b,ans=1;
ll ksc(ll x,ll y,ll md){
    return (x*y-(ll)((long double)x/md*y)*md+md)%md;     
}
ll Pow(ll a,ll p,ll md){
	ll ans=1;
	for(;p;p>>=1,a=ksc(a,a,md))
		if(p&1)ans=ksc(a,ans,md);
	return ans;
}
int main()
{
	//cout<<ksc(111,111)<<endl;
	a=read();b=read();
	if(a==0){
		printf("0\n");
		return 0;
	}
	for(int i=2;i<=sqrt(a);i++){
		if(a%i)continue;
		int num=0;
		while(a%i==0)num++,a/=i;
		ans=ksc(ans,(Pow(i,num*b+1,mod*(i-1))+(mod*(i-1))-1)/(i-1),mod);
	}
	if(a>1)
		ans=ksc(ans,(Pow(a,b+1,mod*(a-1))+(mod*(a-1))-1)/(a-1),mod);
	printf("%lld\n",ans);
	return 0;
}




