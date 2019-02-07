#include <bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,a[300009+10009];
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	int t1=1,t2=n;
	ll ans=0;
	while(t1<t2){
		ans+=(a[t1]+a[t2])*(a[t1]+a[t2]);
		t1++;t2--;
	}
	cout<<ans<<endl;
	return 0;
}



