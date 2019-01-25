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
ll ksc(ll x,ll y,ll mod){
	cout<<(long double)x*y<<" "<<x*y<<endl;
    return (x*y-(ll)((long double)x*y/mod)*mod+mod)%mod;     
}
int main()
{
	ll x=read(),y=read(),z=read();
	cout<<ksc(x,y,z)<<endl;
	return 0;
}
