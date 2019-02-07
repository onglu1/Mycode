#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1009;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,a[N],b[N];
int aa[N],bb[N];
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();aa[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++)b[i]=read(),bb[i]=b[i]-b[i-1];
	sort(aa+1,aa+n+1);
	sort(bb+1,bb+n+1);
	for(int i=1;i<=n;i++)
		if(aa[i]!=bb[i]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}



