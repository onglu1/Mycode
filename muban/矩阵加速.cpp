#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#define ull unsigned long long
#define ll long long
using namespace std;
const int mod=1000000007;
struct Mat{
	int n,m,a[109][109];
	Mat(){
		n=0;m=0;
		memset(a,0,sizeof(a));	
	}
	void clear(){memset(a,0,sizeof(a));}
	void print(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}
	}
};
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
Mat operator +(Mat A,Mat B){
	if(A.n!=B.n||A.m!=B.m){cerr<<"Wrong"<<endl;return A;}
	Mat C;C.n=A.n;C.m=B.m;
	for(int i=1;i<=A.n;i++)
		for(int j=1;j<=A.m;j++){
			C.a[i][j]=A.a[i][j]+B.a[i][j];
			if(C.a[i][j]>=mod)C.a[i][j]-=mod;
		}
	return C;
}
Mat operator -(Mat A,Mat B){
	if(A.n!=B.n||A.m!=B.m){cerr<<"Wrong"<<endl;return A;}
	Mat C;C.n=A.n;C.m=B.m;
	for(int i=1;i<=A.n;i++)
		for(int j=1;j<=A.m;j++){
			C.a[i][j]=A.a[i][j]-B.a[i][j];
			if(C.a[i][j]<0)C.a[i][j]+=mod;
		}
	return C;
}
Mat operator *(Mat A,Mat B){
	if(A.m!=B.n){cerr<<"Wrong"<<endl;return A;}
	Mat C;C.n=A.n;C.m=B.m;
	for(int i=1;i<=A.n;i++)
		for(int j=1;j<=B.m;j++)
			for(int k=1;k<=A.m;k++)
				C.a[i][j]=(C.a[i][j]+(1ll*A.a[i][k]*B.a[k][j])%mod)%mod;
	return C;
}

Mat operator ^(Mat A,ll p){
	if(A.n!=A.m){cerr<<"Wrong"<<endl;return A;}
	Mat ans;
	ans.m=ans.n=A.n;
	for(int i=1;i<=ans.n;i++)ans.a[i][i]=1;
	for(;p;p>>=1,A=A*A)
		if(p&1)ans=ans*A;
	return ans;
}
void work(){
	int n=read();
	Mat fib,rec;
	fib.n=1;fib.m=3;
	rec.n=3;rec.m=3;
	fib.a[1][1]=1;fib.a[1][2]=1;fib.a[1][3]=1;
	rec.a[1][1]=0;rec.a[1][2]=0;rec.a[1][3]=1;
	rec.a[2][1]=1;rec.a[2][2]=0;rec.a[2][3]=0;
	rec.a[3][1]=0;rec.a[3][2]=1;rec.a[3][3]=1;
	fib=fib*(rec^(n-1));
	printf("%d\n",fib.a[1][1]);
}
int main()
{
	int Case=read();
	while(Case--)work();	
	return 0;
}
