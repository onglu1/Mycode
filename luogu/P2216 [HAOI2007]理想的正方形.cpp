#include <bits/stdc++.h>
#define ll long long
#define Mid ((l+r)>>1)
#define ull unsigned long long
using namespace std;
const int N=1009;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int a,b,n,q1[N*100],h1,t1,q2[N*100],h2,t2;
int maxn[N][N],tmp1[N][N];
int minn[N][N],tmp2[N][N];
int main()
{
	//freopen("1.in","r",stdin);
	a=read();b=read();n=read();
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			maxn[i][j]=minn[i][j]=read();
	for(int i=1;i<=a;i++){
		h1=h2=t1=t2=q1[1]=q2[1]=1;
		//q1是维护最大值，维护单调递减的队列 
		for(int j=2;j<=b;j++){
			int x=maxn[i][j];
			while(h1<=t1&&j-q1[h1]+1>n)h1++;
			while(h2<=t2&&j-q2[h2]+1>n)h2++;
			while(h1<=t1&&x>maxn[i][q1[t1]])t1--;
			while(h2<=t2&&x<maxn[i][q2[t2]])t2--;
			q1[++t1]=j;q2[++t2]=j;
			if(j>=n)tmp1[i][j-n+1]=maxn[i][q1[h1]],
			tmp2[i][j-n+1]=maxn[i][q2[h2]];
		}
	}
	for(int j=1;j<=b-n+1;j++){
		h1=h2=t1=t2=q1[1]=q2[1]=1;
		for(int i=2;i<=a;i++){
			int X=tmp1[i][j],x=tmp2[i][j];
			while(h1<=t1&&i-q1[h1]+1>n)h1++;
			while(h2<=t2&&i-q2[h2]+1>n)h2++;
			while(h1<=t1&&X>tmp1[q1[t1]][j])t1--;
			while(h2<=t2&&x<tmp2[q2[t2]][j])t2--;
			q1[++t1]=i;q2[++t2]=i;
			if(i>=n)maxn[i-n+1][j]=tmp1[q1[h1]][j],
			minn[i-n+1][j]=tmp2[q2[h2]][j];
		}
	}
	int ans=(1<<31)-1;
	for(int i=1;i<=a-n+1;i++)
		for(int j=1;j<=b-n+1;j++)
			ans=min(ans,maxn[i][j]-minn[i][j]);
	printf("%d\n",ans);
	return 0;
}
