#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define Mid ((l+r)<<1)
using namespace std;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int main()
{
	int n=read();
	for(int i=0;i<1<<n;i++){
		for(int j=0;j<n;j++)
			if(i&(1<<j))cout<<j+1<<" ";
		cout<<endl;
	}
	return 0;
}

