#include <bits/stdc++.h>
using namespace std;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,a[109],now;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=0;i<(1<<n);i++){
		now=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j))now+=a[j+1];
			else now-=a[j+1]; 
		}
		if(now%360==0){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}



