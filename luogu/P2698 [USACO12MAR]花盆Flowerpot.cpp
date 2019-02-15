#include <bits/stdc++.h>
#define ll long long
#define Mid ((l+r)>>1)
#define ull unsigned long long
using namespace std;
const int N=3e6+10009;
struct node{
	int pos,val;
}a[N];
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int q1[N],q2[N],h1,h2,t1,t2;
int n,d,ans=-1;
bool cmp(node a,node b){return a.pos<b.pos;}
int main()
{
	n=read();d=read();
	for(int i=1;i<=n;i++){
		a[i].pos=read();
		a[i].val=read();
	}
	sort(a+1,a+1+n,cmp);
	int t=1;
	h1=h2=t1=t2=q1[1]=q2[1]=1;
	for(int i=1;i<=n;i++){
		while(a[q1[h1]].pos<a[i].pos)h1++;
		while(a[q2[h2]].pos<a[i].pos)h2++;
		//最大/小值在i左边的时候，弹掉队首 
		while(t<=n&&abs(a[q1[h1]].val-a[q2[h2]].val)<d){
			t++;
			while(h1<=t1&&a[t].val>=a[q1[t1]].val)t1--;
			while(h2<=t2&&a[t].val<=a[q2[t2]].val)t2--;
			q2[++t2]=q1[++t1]=t;
		}
		if(t>n)break;
		if(abs(a[q1[h1]].val-a[q2[h2]].val)>=d){
			if(ans==-1)ans=abs(a[t].pos-a[i].pos);
			else ans=min(ans,abs(a[t].pos-a[i].pos));
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
选定一个区间，这个区间包含的最大值-最小值大于D
求区间最小长度
排序左右端点 
*/ 
