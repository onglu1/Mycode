#include <bits/stdc++.h>
using namespace std;
const int M=5e5+1009;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,m,f[M];
int head[M],nxt[M],ver[M],tot=1;
priority_queue<int>q;
void add(int u,int v){
	ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
	ver[++tot]=u;nxt[tot]=head[v];head[v]=tot;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		if(u!=v)add(u,v);
	}
	q.push(-1);f[1]=1;
	while(!q.empty()){
		int x=-q.top();q.pop();
		for(int i=head[x];i;i=nxt[i]){
			int y=ver[i];
			if(!f[y])q.push(-y),f[y]=1;
		}
		printf("%d ",x);
	}
	printf("\n");
	return 0;
}



