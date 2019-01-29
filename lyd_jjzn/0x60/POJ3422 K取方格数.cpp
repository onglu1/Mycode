#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define Mid ((l+r)>>1)
using namespace std;
const int N=3e6+100009;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,m,g[109][109],id[109][109],cnt=2;
int head[N],nxt[N],ver[N],tot=1,s,t;
int edge[N],cost[N],vis[N];
int dis[N],pre[N],flow[N],maxflow,maxcost;
void add_edge(int u,int v,int w,int c){
	ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;edge[tot]=w;cost[tot]=c;
	ver[++tot]=u;nxt[tot]=head[v];head[v]=tot;edge[tot]=0;cost[tot]=-c;
}
bool spfa(){
	queue<int>q;
	memset(dis,0xcf,sizeof(dis));dis[s]=0;
	memset(vis,0,sizeof(vis));vis[s]=1;
	q.push(s);flow[s]=(1<<30);
	while(q.size()){
		int x=q.front();q.pop();vis[x]=0;
		for(int i=head[x];i;i=nxt[i]){
			//cout<<ver[i]<<endl;
			if(edge[i]<=0)continue;
			int y=ver[i];
			//cout<<y<<endl;
			if(dis[y]<dis[x]+cost[i]){
				dis[y]=dis[x]+cost[i];pre[y]=i;
				flow[y]=min(edge[i],flow[x]);
				if(!vis[y])q.push(y),vis[y]=1;
			}
		}
	}
	if(dis[t]==0xcfcfcfcf)return false;
	return true;
}
void update(){
	int x=t;
	while(x!=s){
		int i=pre[x];
		edge[i]-=flow[t];
		edge[i^1]+=flow[t];
		x=ver[i^1];
	}
	maxflow+=flow[t];
	maxcost+=dis[t]*flow[t];
}
void doit(){
	while(spfa())update();
	printf("%d\n",maxcost);
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			g[i][j]=read();
			id[i][j]=cnt;
			cnt+=2;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			add_edge(id[i][j],id[i][j]+1,1,g[i][j]);
			add_edge(id[i][j],id[i][j]+1,m-1,0);
			//点内连边 
			if(i+1<=n)add_edge(id[i][j]+1,id[i+1][j],m,0);
			if(j+1<=n)add_edge(id[i][j]+1,id[i][j+1],m,0);
		}
	s=1;t=cnt;
	add_edge(s,id[1][1],m,0);
	add_edge(id[n][n]+1,t,m,0);
	doit();
	return 0;
}
