#include <bits/stdc++.h>
using namespace std;
const int N=6e5+1009;
int read(){
    char c;int num,f=1;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return f*num;
}
int n,a[N],val[N],cf[N];
int fa[N],dep[N],siz[N],son[N],id[N],rl[N],cnt=0;
int head[N],nxt[N*2],ver[N*2],tot=1,top[N];
void Swap(int &x,int &y){x^=y^=x^=y;}
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
    ver[++tot]=u;nxt[tot]=head[v];head[v]=tot;
}
void dfs1(int x,int pre,int deep){
    dep[x]=deep;siz[x]=1;
    for(int i=head[x];i;i=nxt[i]){
        if(ver[i]==pre)continue;
        dfs1(ver[i],x,deep+1);
        fa[ver[i]]=x;
        siz[x]+=siz[ver[i]];
        if(siz[ver[i]]>siz[son[x]])son[x]=ver[i];
    }
}
void dfs2(int x,int ltp){
    id[x]=++cnt;
    rl[cnt]=x;
    top[x]=ltp;
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
    else return x;
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<n;i++)add(read(),read());
    dfs1(1,1,1);dfs2(1,1);val[a[1]]=1;
    for(int i=2;i<=n;i++){
        int t=lca(a[i-1],a[i]);
        cf[a[i-1]]++;
        cf[a[i]]++;
        cf[fa[t]]-=2;
        val[t]--; 
    }
    for(int i=n;i>0;i--){
        val[rl[i]]+=cf[rl[i]];
        cf[fa[rl[i]]]+=cf[rl[i]];
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",val[i]-1);
    return 0;
}
/*
树上差分+dfn序
a[1]上+1
每次查找链，在起点和终点+1，LCA的父亲上-=2。
注意起点可能会重复走，于是我们预先在起点的权值数组中-1
*/ 
