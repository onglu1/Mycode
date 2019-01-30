#include <bits/stdc++.h>
#define spf up
#define num down
using namespace std;
const int N=50009;
struct cow{
	int up,down;
}c[N];
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,m,f[1009];
bool operator<(const cow &a,const cow &b){return a.down>b.down;}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++){
		c[i].down=read();
		c[i].up=read();
	}
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		f[x]+=y;
	}
	sort(c+1,c+1+n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=c[i].up;j>=c[i].down;j--){
			if(f[j]){
				cnt++;f[j]--;
				break;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
