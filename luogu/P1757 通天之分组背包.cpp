#include <bits/stdc++.h>
using namespace std;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
struct Object{int w,v;};
vector<Object>g[109];
int f[109][1009];
int n,m,t;
int main()
{
	m=read();n=read();
	for(int i=1;i<=n;i++){
		int x,y,z;
		x=read();y=read();
		t=max(t,z=read());
		g[z].push_back((Object){x,y});
	}
	for(int i=1;i<=t;i++){
		for(int j=0;j<=m;j++){
			f[i][j]=f[i-1][j];
			for(int k=0;k<g[i].size();k++)
				if(g[i][k].w<=j)
					f[i][j]=max(f[i][j],f[i-1][j-g[i][k].w]+g[i][k].v);
		}
	}
	printf("%d\n",f[t][m]);
	return 0;
}
/*
f[i][j]表示前i组用了j个重量的最大价值
f[i][j]=max{f[i-1][j-w[k]]} 
*/
