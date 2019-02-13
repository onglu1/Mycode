#include <bits/stdc++.h>
using namespace std;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int a[10],b[10];
int main()
{
	for(int i=1;i<=3;i++)a[i]=read();
	for(int i=1;i<=3;i++)b[i]=read();
	if(a[1]<=b[1]){
		a[1]-=b[1];
		b[1]=0;
		if(a[1]+a[2]<=b[2]){
			int del=min(a[1],b[2]);
			a[1]-=del;b[2]-=del;
			a[2]-=b[2];b[2]=0;
			//cout<<1<<endl;
			if(a[1]+a[2]+a[3]<=b[3]){
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}
