#include <bits/stdc++.h>
using namespace std;
const int N=100009*2;
int read(){
    char c;int num,f=1;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return f*num;
}
int n,m,c,maxn=0x3f3f3f3f;
int val[N],dis[N],vis[N];
int head[N],nxt[N],ver[N],edge[N],tot=1;
queue<int>q;
void add(int u,int v,int w){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;edge[tot]=w;
    ver[++tot]=u;nxt[tot]=head[v];head[v]=tot;edge[tot]=w;
}
void up(int &a,int b){(a<b)?0:(a=b);}
int spfa(int s){
    while(q.size())q.pop();q.push(s);
    memset(vis,0,sizeof(vis));vis[s]=1;
    memset(dis,0x3f,sizeof(dis));dis[s]=0;
    while(q.size()){
        int x=q.front();
        q.pop();vis[x]=0;
        for(int i=head[x];i;i=nxt[i]){
            if(dis[ver[i]]>dis[x]+edge[i]){
                dis[ver[i]]=dis[x]+edge[i];
                if(!vis[ver[i]]){
                    vis[ver[i]]=1;
                    q.push(ver[i]);
                }
            }
        }
    }
    int ans=0;
    /*if(s==4){
        for(int i=1;i<=n;i++){
            cout<<val[i]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=1;i<=n;i++)
        ans+=dis[i]*val[i];
    return ans;
}
int main()
{
    c=read();
    n=read();
    m=read();
    for(int i=1;i<=c;i++)val[read()]++;
    for(int i=1;i<=m;i++){
        int u,v,w;
        u=read();v=read();w=read();
        add(u,v,w);
    }
    for(int i=1;i<=n;i++)
        up(maxn,spfa(i));
    printf("%d\n",maxn);
    return 0;
}
