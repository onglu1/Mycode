#include <bits/stdc++.h>
#define ll long long
#define Mid ((l+r)>>1)
#define ull unsigned long long
using namespace std;
const int N=59,M=1e5+1009;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int readc(){
	char c=getchar();
	while(c!='#'&&c!='*'&&c!='x')c=getchar();
	if(c=='#')return 2;
	if(c=='*')return 1;
	if(c=='x')return 0;
}
int n,m,g[N][N],cnt1,cnt2;
int L[N][N],R[N][N],dis[M],s,t;
int head[M],nxt[M],ver[M],edge[M],tot=1;
queue<int>q;
void add_edge(int u,int v,int w){
	//cout<<u<<" "<<v<<endl;
	ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;edge[tot]=w;
	ver[++tot]=u;nxt[tot]=head[v];head[v]=tot;edge[tot]=0;
}
bool bfs(){
	while(q.size())q.pop();q.push(s);
	memset(dis,0,sizeof(dis));dis[s]=1;
	while(q.size()){
		int x=q.front();q.pop();
		for(int i=head[x];i;i=nxt[i]){
			if(dis[ver[i]]||!edge[i])continue;
			dis[ver[i]]=dis[x]+1;
			q.push(ver[i]);
			if(ver[i]==t)return 1;
		}
	}
	return 0;
}
int dinic(int x,int flow){
	if(x==t)return flow;
	int res=flow,y,k;
	for(int i=head[x];i&&res;i=nxt[i]){
		y=ver[i];
		if(dis[y]!=dis[x]+1||!edge[i])continue;
		k=dinic(y,min(res,edge[i]));
		if(!t)dis[y]=0;
		edge[i]-=k;edge[i^1]+=k;
		res-=k;
	}
	return flow-res;
}
int main()
{
	//freopen("4.in","r",stdin);
	//freopen("data.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			g[i][j]=readc();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]==2||L[i][j])continue;
			cnt1++;
			for(int k=j;k<=m&&g[i][k]!=2;k++)
				L[i][k]=cnt1;
		}
	}
	int t1=cnt1;
	//编号行 
	/*
	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<L[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	*/
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(g[i][j]==2||R[i][j])continue;
			cnt1++;
			for(int k=i;k<=n&&g[k][j]!=2;k++)
				R[k][j]=cnt1;
		}
	}
	//编号列
	/*
	 cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<R[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	*/
	//重标号
	s=cnt1+11;t=cnt1+15;
	for(int i=1;i<=t1;i++)
		add_edge(s,i,1);
	for(int i=t1+1;i<=cnt1;i++)
		add_edge(i,t,1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			//横号竖向连接
			if(g[i][j]!=1)continue;
			//cout<<L[i][j]<<" "<<R[i][j]<<endl;
			add_edge(L[i][j],R[i][j],1);
		}
	//连边
	/*
	for(int i=head[7];i;i=nxt[i])
		cout<<ver[i]<<" ";
	cout<<endl;
	*/
	int maxflow=0,flow;
	while(bfs())while(flow=dinic(s,(1<<31)-1))maxflow+=flow;	
	printf("%d\n",maxflow); 
	return 0;
}
/*
由于有硬石头和软石头，就不能当做普通的二分图匹配跑了
对于一个石头分隔开的一段，我们完全可以把它当成两段匹配
可以匹配的行数和列数不一样
具体来说，可以按照硬石头的位置，把一段行和一段列拆开，重标号
软石头是不能放的
所以在连边的时候注意 
然后跑匹配就可以了。

*/ 











 
