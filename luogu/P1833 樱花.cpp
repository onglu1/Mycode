#include <bits/stdc++.h>
using namespace std;
struct Ob{int w,v;};
int read(){
	char c;int f=1,num;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,m,t1,t2,f[1000009];
Ob g1[1000009],g2[1000009];
int main()
{
	int a,b,c,d;
	a=read();b=read();c=read();d=read();
	n=read();m=c*60+d-a*60-b;
	for(int i=1;i<=n;i++){
		a=read();b=read();c=read();
		if(c==0)g2[++t2]=(Ob){a,b};else
		for(int j=1;j<=c;j<<=1)if(c&j)
			g1[++t1]=(Ob){a*j,b*j}; 
	}
	for(int k=1;k<=t1;k++)
		for(int i=m;i>=0;i--){
			f[i]=max(f[i],f[i-1]);
			if(i-g1[k].w>0)f[i]=max(f[i],f[i-g1[k].w]+g1[k].v);
		}
	for(int k=1;k<=t2;k++)
		for(int i=0;i<=m;i++){
			f[i]=max(f[i],f[i-1]);
			if(i-g2[k].w>0)f[i]=max(f[i],f[i-g2[k].w]+g2[k].v);
		}
	printf("%d\n",f[m]);
	return 0;
}
/*
f[i]表示剩余i时间的最大收益
混合背包问题
有限背包二进制展开转化为01背包 
01背包搞完之后搞完全背包
*/ 
