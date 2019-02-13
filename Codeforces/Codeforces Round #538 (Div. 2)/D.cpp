#include <bits/stdc++.h>
#define ll long long 
#define Mid ((l+r)>>1)
#define ull unsigned long long
using namespace std;
const int N=5005;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,a[N],f[N][N][2];
void memorycheck(){
	double x=sizeof n+sizeof a+sizeof f;
	cout<<(x/1024/1024)<<"MB"<<endl;
}
int dp(int l,int r,int p){
	if(l>=r)return 0;
	if(f[l][r][p])return f[l][r][p];
	int res=0;
	if(!p){
		res=dp(l+1,r,0)+(a[l]!=a[l+1]);
		res=min(res,dp(l+1,r,1)+(a[l]!=a[r]));
	}else {
		res=dp(l,r-1,0)+(a[r]!=a[l]);
		res=min(res,dp(l,r-1,1)+(a[r]!=a[r-1]));
	}
	return f[l][r][p]=res;
	
}
int main()
{
	//memorycheck();
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]==a[i-1])i--,n--;
	}
	cout<<min(dp(1,n,0),dp(1,n,1))<<endl;
	return 0;
}

[close]

