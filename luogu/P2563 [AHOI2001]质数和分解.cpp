#include <bits/stdc++.h>
using namespace std;
int read(){
	char c;int f=1,num;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,f[1009],phi[1009],cnt=0;
int d[1009][1009];
int Prepare(){
	for(int i=2;i<=509;i++){
		if(!f[i])phi[++cnt]=i;
		for(int j=1;j<=cnt&&i*phi[j]<=509;j++){
			f[i*phi[j]]=1;
			if(!(i%phi[j]))break;
		}
	}
}
int main()
{
	Prepare();
	for(int i=0;i<=cnt;i++)d[0][i]=1;
	for(int i=2;i<=309;i++){
		for(int j=1;j<=cnt;j++){
			d[i][j]=d[i][j-1];
			//若不用第j个数 
			for(int k=phi[j];k<=i;k+=phi[j])
				d[i][j]+=d[i-k][j-1];
			//若用上第j个数 
		}
	}
	while(cin>>n)
		printf("%d\n",d[n][cnt]);
	return 0;
}
/*
发现普通的递推会有问题
这里必须要保证加法是从小到大的
那么d[i][j]表示组成数字i，只用前j个素数的方案数。
d[i][j]=sum{d[i-phi[j]*k][j-1]} 
*/
