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
int a[109],n,m;
void dfs(int num,int dep){
	if(dep==m){
		for(int i=1;i<=m;i++)printf("%d ",a[i]);
		printf("\n");
		return ;
	}
	for(int i=num+1;i<=n;i++){
		a[dep+1]=i;
		dfs(i,dep+1);
	}
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[1]=i;dfs(i,1);
	}
	return 0;
}

