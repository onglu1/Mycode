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
int n,f[109],ans[109];
void dfs(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		printf("\n");
		return ;
	}
	for(int i=1;i<=n;i++){
		if(f[i])continue;
		f[i]=1;ans[x]=i;
		dfs(x+1);
		f[i]=0;ans[x]=0;
	}
}
int main()
{
	n=read();
	dfs(1);
	return 0;
}

