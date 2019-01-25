#include <bits/stdc++.h>
using namespace std;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
} 
int Pow(int a,int b,int p){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%p)
		if(b&1)ans=1ll*ans*a%p;
	return ans%p;
}
int main()
{
	int a=read(),b=read(),c=read();
	cout<<Pow(a,b,c)<<endl;
	return 0;
}
