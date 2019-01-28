#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define Mid ((l+r)>>1)
using namespace std;
const int N=5e5+1009;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,a[N],b[N];
ll ans=0;
int Memorycheck(){
	double sz=sizeof(n)+sizeof(a)+sizeof(b)+sizeof(ans);
	printf("%fMB\n",sz/1024/1024);
}
void Sort(int l,int r){
	if(l==r)return ;
	Sort(l,Mid);
	Sort(Mid+1,r);
	int t1=l,t2=Mid+1,cnt=l-1;
	while(t1<=Mid&&t2<=r){
		if(a[t1]<=a[t2])b[++cnt]=a[t1++];
		else {
			b[++cnt]=a[t2++];
			ans+=1ll*Mid-t1+1;
		}
	}
	while(t1<=Mid)b[++cnt]=a[t1++];
	while(t2<=r)b[++cnt]=a[t2++];
	for(int i=l;i<=r;i++)a[i]=b[i];
}
void work(){
	for(int i=1;i<=n;i++)a[i]=read();
	Sort(1,n);
	printf("%lld\n",ans);
	ans=0;
}
int main()
{
	//Memorycheck();
	while(n=read()){
		if(!n)return 0;
		work();
	}
}

