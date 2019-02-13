#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+1009;
struct node{int val,pos;}a[N];
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
bool cmp(node a,node b){return a.val>b.val;}
int f[N],n,m,k,tmp=0,cnt=0;
ll sum;
int main()
{
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++){
		a[i].val=read();
		a[i].pos=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m*k;i++){
		f[a[i].pos]=1;
		sum+=a[i].val;
	}
	cout<<sum<<endl;
	for(int i=1;i<=n;i++){
		tmp+=f[i];
		if(cnt==k-1)break;
		if(tmp>=m)tmp=0,cout<<i<<" ",cnt++;
	}
	cout<<endl;
	return 0;
}
