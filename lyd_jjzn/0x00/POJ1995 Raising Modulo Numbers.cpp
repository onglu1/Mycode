#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define Mid ((l+r)<<1)
using namespace std;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int Pow(int a,int b,int mod){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans%mod;
}
void work(){
	int ans=0,mod=read(),m=read();
	for(int i=1;i<=m;i++){
		int a=read(),b=read();
		//cout<<ans<<endl;
		ans=(1ll*ans+Pow(a,b,mod))%mod;
	}
	cout<<ans<<endl;
}
int main()
{
	//cout<<Pow(2374859,3029382,36123)<<endl;
	int Case=read();
	while(Case--)work();
	return 0;
}

