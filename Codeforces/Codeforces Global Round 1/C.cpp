#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll test[109]={2,3,5,7,11,61,24251,13,17,23};
ll read(){
	char c;ll num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
ll Pow(ll a,ll p,ll mod){
    ll ans=1;
    for(;p;p>>=1,a=1ll*a*a%mod)
        if(p&1)ans=1ll*ans*a%mod;
    return ans;
}
bool check(ll P){
    if(P==1)return 0;
    ll k=0,t=P-1;
    while(!(k&1))k++,t>>=1;
    for(int i=0;i<10;i++){
        if(P==test[i])return 1;
        ll a=Pow(test[i],t,P),nxt;
        for(int j=1;j<=k;j++){
            nxt=(1ll*a*a)%P;
            if(nxt==1&&a!=1&&a!=P-1)return 0;
            a=nxt;
        }
        if(a!=1)return 0;
    }
    return 1;
}
int ct(ll x){
	ll t=1;int flag=0;
	while(t<=x){
		if((x&t)==0)flag=1;
		t<<=1;
	}
	if(flag)return t;
	else return -1;
}
int main()
{
	int q=read();
	for(int i=1;i<=q;i++){
		ll a=read();
		ll b=ct(a);
		if(!(~b)){
			if(check(a))printf("1\n");
			else {
				for(ll i=2;i<a;i++){
					if(a%i==0){
						cout<<(a/i)<<endl;
						break;
					}
				}
			}
		}else cout<<(b-1)<<endl;
	}
	return 0;
}
/*
观察式子，亦或运算可能比a,b都大，与运算比a,b都小，
gcd比亦或和与都小，我们要使
首先观察，如果a的二进制拆分下有0，那么补全所有的0
如果a的二进制拆分下没有0，
*/



