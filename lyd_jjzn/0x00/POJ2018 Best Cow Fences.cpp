#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=1e5+1009;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int main()
{
	int n,L;
	double a[N],sum[N];
	n=read();L=read();
	for(int i=1;i<=n;i++)a[i]=read();
	double l=-1e6,r=1e6,mid;
	while(r-l>1e-6){
		mid=(l+r)/2;
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+a[i]-mid;
		double ans=-1e10,minn=1e10;
		for(int i=L;i<=n;i++){
			minn=min(minn,sum[i-L]);
			ans=max(ans,sum[i]-minn);
			//if(i==9&&mid==6.5)cout<<sum[i]-minn<<" "<<ans<<endl;
		}
		//cout<<ans<<endl;
		if(ans>=0)l=mid;else r=mid;
	}
	printf("%d\n",int(r*1000));
	return 0;
}

/*
二分转化为存在性问题：
给定一个平均数，判断是否存在一个区间
在长度大于L的情况下，平均数大于这个平均数。
由于区间的平均数等于sum(所有数)/长度，
平均数大于二分值就等于(sum(所有数)-长度*二分)/长度大于0 
我们乘以一个长度，就变成了sum(所有数)-长度*二分 大于0
我们只要把每个数减去二分值，然后就变成了判断是否存在长度大于L的区间，区间和大于0
每次判断我们固定左端点，右端点是从1到n
 
*/ 
