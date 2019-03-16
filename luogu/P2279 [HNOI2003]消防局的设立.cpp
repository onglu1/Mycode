#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1009;
const int inf=0x3f3f3f3f;
struct Node{int dth,id;}g[N];
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,d[N],fa[N],ans;
bool cmp(Node a,Node b){return a.dth>b.dth;}
int main()
{
	n=read();
	g[1].dth=1;g[1].id=1;
	d[1]=d[0]=inf;
	for(int i=2;i<=n;i++){
		fa[i]=read();
		g[i].id=i;d[i]=inf;
		g[i].dth=g[fa[i]].dth+1;
	}
	sort(g+1,g+1+n,cmp);
	for(int i=1;i<=n;i++){
		int a=g[i].id,b=g[i].dth;
		int u=fa[a],v=fa[u],p=fa[v],q=fa[p];
		d[a]=min(d[a],min(d[u]+1,d[v]+2));
		if(d[a]>2){
			d[v]=0;
			d[p]=min(d[p],1);
			d[q]=min(d[q],2);
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
树上贪心？
d[i]表示距离i最近的消防局到i的距离
所有的点按照深度排序
每次取出深度最深的点，进行拓展 
*/ 
