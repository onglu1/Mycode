#include <bits/stdc++.h>
#define ll long long
#define Mid ((l+r)>>1)
#define ull unsigned long long
using namespace std;
const int N=5e5+1009;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int rl[N],cnt=0;
int n,dep[N],siz[N],fa[N],top[N],son[N];
int head[N],nxt[N],ver[N],tot=1,ans[N];
void add_edge(int u,int v){
	ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
	ver[++tot]=u;nxt[tot]=head[v];head[v]=tot;
}
void dfs1(int x,int dth,int pre){
	siz[x]=1;dep[x]=dth;
	for(int i=head[x];i;i=nxt[i]){
		if(ver[i]==pre)continue;
		dfs1(ver[i],dth+1,x);
		fa[ver[i]]=x;siz[x]+=siz[ver[i]];
		if(siz[ver[i]]>siz[son[x]])son[x]=ver[i];
	}
}
void dfs2(int x,int ltp){
	top[x]=ltp;rl[++cnt]=x;
	if(son[x])dfs2(son[x],ltp);
	for(int i=head[x];i;i=nxt[i]){
		if(ver[i]==fa[x]||ver[i]==son[x])continue;
		dfs2(ver[i],ver[i]);
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]])x=fa[top[x]];
		else y=fa[top[y]];
	}
	if(dep[x]>dep[y])return y;
	return x;
}
int k;
int main()
{
	n=read();k=read();
	for(int i=1;i<n;i++)add_edge(read(),read());
	dfs1(1,1,0);dfs2(1,1);
	for(int i=1;i<=k;i++){
		int x=read(),y=read(),tt=lca(x,y);
		ans[x]+=1;ans[y]+=1;
		ans[tt]--;
		ans[fa[tt]]-=2;
	}
	for(int i=n;i>=1;i--){
		int t=rl[i];
		ans[fa[t]]+=ans[t];
	}
	int maxn=0;
	for(int i=1;i<=n;i++)
		maxn=max(maxn,ans[i]);
	printf("%d\n",maxn);
	return 0;
}
/*
Ê÷ÉÏ²î·Ö
*/ 
