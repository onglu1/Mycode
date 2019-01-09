#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100009*5,M=200009*5;
const ll inf=(1ll<<59)-1;
int read(){
    char c;int f=1,num;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return f*num;
}
struct Node{
    int id;
    ll w;
    Node(int a,ll b){id=a;w=b;}
};
bool operator <(Node a,Node b){return a.w>b.w;}
int n,m,k,s,vis[N];
int head[N],nxt[M],ver[M],tot=0;
ll P,Q,val[N],dis[N],edge[M];
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
    ver[++tot]=u;nxt[tot]=head[v];head[v]=tot;
}
void dijkstra(){
    priority_queue<Node>q;
    for(int i=1;i<=n;i++)dis[i]=inf;
    q.push(Node(1,0));dis[1]=0;
    while(q.size()){
        Node tmp=q.top();q.pop();
        int x=tmp.id,w=tmp.w;
        if(w>dis[x])continue;
        for(int i=head[x];i;i=nxt[i]){
            if(dis[ver[i]]>dis[x]+edge[i]){
                dis[ver[i]]=dis[x]+edge[i];
                q.push(Node(ver[i],dis[ver[i]]));
            }
        }
    }
}
int main()
{
    queue <int> q,d;
    n=read();m=read();
    k=read();s=read();
    P=read();Q=read();
    for(int i=1;i<=k;i++){
        int x=read();
        q.push(x);d.push(0);
        vis[x]=-1;
    }
    for(int i=1;i<=m;i++)
        add(read(),read());
    while(q.size()){
        int x=q.front(),dd=d.front();
        q.pop();d.pop();
        for(int i=head[x];i;i=nxt[i]){
            if(vis[ver[i]]==0&&dd<s){
                vis[ver[i]]=1;
                q.push(ver[i]);
                d.push(dd+1);
            }
        }
    }
    for(int i=2;i<n;i++){
        if(vis[i]==-1)val[i]=inf;
        else if(vis[i]==1)val[i]=Q;
        else val[i]=P;
    }
    for(int i=1;i<=tot;i++)edge[i]=val[ver[i]];
    dijkstra();
    printf("%lld\n",dis[n]);
    return 0;
}
