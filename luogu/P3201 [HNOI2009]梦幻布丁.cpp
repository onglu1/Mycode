#include <bits/stdc++.h>
#define ll long long
#define Mid ((l+r)>>1)
#define ull unsigned long long
using namespace std;
const int N=5e6+1009;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,m,ans,f[N],c[N];
int head[N],nxt[N],siz[N],tal[N];
void Swap(int &x,int &y){x^=y;y^=x;x^=y;}
void merge(int x,int y){
	for(int i=head[x];i;i=nxt[i])ans-=(c[i-1]==y)+(c[i+1]==y);
	for(int i=head[x];i;i=nxt[i])c[i]=y;
	nxt[tal[x]]=head[y];head[y]=head[x];siz[y]+=siz[x];
	head[x]=tal[x]=siz[x]=0;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++){
		c[i]=read();f[c[i]]=c[i];
		ans+=(c[i]!=c[i-1]);
		if(!head[c[i]])tal[c[i]]=i;
		siz[c[i]]++;nxt[i]=head[c[i]],head[c[i]]=i;
	}
	for(int i=1;i<=m;i++){
		int opt=read(),x,y;
		if(opt==2)printf("%d\n",ans);
		else {
			x=read();y=read();
			if(x==y)continue;
			if(siz[f[x]]>siz[f[y]])Swap(f[x],f[y]);
			if(!siz[f[x]])continue;
			merge(f[x],f[y]);
		}
	}
	return 0;
}

