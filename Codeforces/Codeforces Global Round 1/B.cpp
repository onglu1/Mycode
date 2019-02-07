#include <bits/stdc++.h>
using namespace std;
const int N=5e5+1009;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,m,k,sum;
int a[N],dis[N];
int main()
{
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)dis[i]=a[i]-a[i-1];
	sort(dis+2,dis+n+1);
	for(int i=2;i<n-k+2;i++)
		sum+=dis[i];
	printf("%d\n",sum+k);
	return 0;
}
/*
有n-1个间隔，我们要取走其中的(n-k)个间隔
*/ 
