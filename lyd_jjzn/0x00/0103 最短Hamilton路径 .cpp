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
int n,g[39][39];
int f[1<<21][21];
int main()
{
	n=read();
	memset(f,0x3f,sizeof(f));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			g[i][j]=read();
	f[1][0]=0;
	for(int S=1;S<(1<<n);S++){
		for(int i=0;i<n;i++)if(S&(1<<i)){
			for(int j=0;j<n;j++)if(S&(1<<j)){
				f[S][i]=min(f[S][i],f[S^(1<<i)][j]+g[j][i]);
			}
		}
	}
	cout<<f[(1<<n)-1][n-1]<<endl;
	return 0;
}

