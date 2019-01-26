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
int d[109],f[109];
int main()
{
	memset(f,0x3f,sizeof f);
	d[0]=f[0]=0;f[1]=d[1]=1;
	for(int i=2;i<=12;i++)d[i]=d[i-1]*2+1;
	for(int i=2;i<=12;i++)
		for(int j=1;j<i;j++)
			f[i]=min(f[i],2*f[j]+d[i-j]);
	for(int i=1;i<=12;i++)
		printf("%d\n",f[i]);
	return 0;
}

