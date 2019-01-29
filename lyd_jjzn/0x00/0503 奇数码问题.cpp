#include <bits/stdc++.h>
#define Mid ((l+r)>>1)
using namespace std;
const int N=509;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,a,b;
int now[N*N],pos[N*N],tmp[N*N];
void mergesort(int *a,int l,int r,int &cnt){
	if(l==r)return ;
	mergesort(a,l,Mid,cnt);
	mergesort(a,Mid+1,r,cnt);
	int t1=l,t2=Mid+1,t3=l;
	while(t1<=Mid&&t2<=r){
		if(a[t1]<=a[t2])tmp[t3++]=a[t1++];
		else tmp[t3++]=a[t2++],cnt+=Mid-t1+1;
	}
	while(t1<=Mid)tmp[t3++]=a[t1++];
	while(t2<=r)tmp[t3++]=a[t2++];
	for(int i=l;i<=r;i++)
		a[i]=tmp[i];
	return ;
}
int main()
{
	while(cin>>n){
		int f=0,p;
		a=b=0;
		for(int i=1,t=1;i<=n;i++){
			for(int j=1;j<=n;j++,t++){
				now[t]=read();
				if(!now[t])t--;
			}
		}
		f=0;
		for(int i=1,t=1;i<=n;i++){
			for(int j=1;j<=n;j++,t++){
				pos[t]=read();
				if(!pos[t])t--;
			}
		}
		if(n==1){
			printf("TAK\n");
			continue;
		}
		mergesort(now,1,n*n-1,a);
		mergesort(pos,1,n*n-1,b);
		if((a&1)==(b&1))printf("TAK\n");
		else printf("NIE\n");
	}
	return 0;
}
