#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define Mid ((l+r)>>1)
using namespace std;
const int N=5e6+1009;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,m,T,s[N];
int line[N],row[N];
void init(){
	n=read();m=read();T=read();
	for(int i=1;i<=T;i++){
		row[read()]++;
		line[read()]++;
	}
	for(int i=1;i<=n;i++)row[i]-=T/n;
	for(int i=1;i<=m;i++)line[i]-=T/m; 
}
int work1(){
	int ans=0;
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+row[i];
	sort(s+1,s+1+n);
	for(int i=1;i<=n;i++)
		ans+=abs(s[i]-s[(n+1)/2]); 
	return ans;
}
int work2(){
	int ans=0;
	for(int i=1;i<=m;i++)
		s[i]=s[i-1]+line[i];
	sort(s+1,s+1+m);
	for(int i=1;i<=m;i++)
		ans+=abs(s[i]-s[(m+1)/2]); 
	return ans;
}
int main()
{
	init();
	if((T%n)&&(T%m))printf("impossible\n");
	else if((T%n==0)&&(T%m==0))printf("both %lld\n",1ll*work1()+work2());
	else if(T%n==0)printf("row %d\n",work1());
	else if(T%m==0)printf("column %d\n",work2());
	return 0;
}
/*
交换相邻列的操作是不影响行的，
交换相邻行的操作是不影响列的，
这样就变成两个环状均分纸牌的问题了。
lrj的蓝书上有详解。
lyd的讲解也不错
*/




