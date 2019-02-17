#include <bits/stdc++.h>
#define ll long long
#define Mid ((l+r)>>1)
#define ull unsigned long long
using namespace std;
const int N=5e5+1009;;
int read(){
    char c;int num,f=1;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return f*num;
}
ll f[N];
int n,m,in[N],out[N];
int head[N],nxt[N],ver[N],tot=1;
ll dfs(int x){
    if(f[x])return f[x];
    if(!out[x]&&in[x])return (f[x]=1);
    for(int i=head[x];i;i=nxt[i])
        f[x]+=dfs(ver[i]);
    return f[x];
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=m;i++){
        int u,v;
        out[u=read()]++;in[v=read()]++;
        ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)if(!in[i])ans+=dfs(i);
    printf("%d\n",ans);
    return 0;
}
/*
给定一张图，求图中的路径有几条 
路径指的是从一个没有入度的点出发，通过某些有向边 
能到底一个没有出度的点。 
暴力记搜应该很简单 
初始所有没有入度的点记为1， 
如果有出度，那么我们把它递推后记为0。  
*/ 
