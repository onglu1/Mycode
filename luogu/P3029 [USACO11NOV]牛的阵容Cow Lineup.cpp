#include <bits/stdc++.h>
#define ll long long
#define Mid ((l+r)>>1)
#define ull unsigned long long
using namespace std;
const int N=5e6+1009;
struct cow{int pos,id;}c[N];
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int num[N],k=0;
int fd(int x){
	int l=1,r=k;
	while(l<=r){
		if(num[Mid]==x)return Mid;
		if(num[Mid]>x)r=Mid-1;
		else l=Mid+1;
	}
	return -1;
}
int n,sum,f[N];
int cmp(cow a,cow b){return a.pos<b.pos;}
int main()
{
	freopen("data.in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++){
		int x=read(),y=read();
		num[++k]=y;
		c[i].pos=x;c[i].id=y;
	}
	sort(num+1,num+1+k);
	k=unique(num+1,num+1+k)-num-1;
	for(int i=1;i<=n;i++)
		c[i].id=fd(c[i].id);
	//离散化 
	sort(c+1,c+1+n,cmp);
	//cout<<num[c[1].pos]<<endl;
	int t=1;
	int ans=(1<<31)-1;
	f[c[1].id]++;
	sum++;
	for(int i=1;i<=n;i++){
		while(sum!=k&&t<=n){
			t++;
			if(!f[c[t].id])sum++;
			f[c[t].id]++;
		}
		if(t>n&&sum<k)break;
		//cout<<ans<<endl;
		if(sum>=k)ans=min(ans,abs(c[t].pos-c[i].pos));
		f[c[i].id]--;
		if(!f[c[i].id])sum--;
		//左移一格之后清空 
	}
	printf("%lld\n",ans);
	return 0;
}

