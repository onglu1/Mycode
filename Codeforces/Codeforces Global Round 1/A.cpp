#include <bits/stdc++.h>
using namespace std;
const int N=1e5+1009;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,Base,v[N];
bool f1,f2;
int main()
{
	Base=read();n=read();
	for(int i=n-1;i>=0;i--)v[i]=read();
	f1=Base&1;f2=0;
	if(!f1){
		f2=v[0]&1;
		if(f2)printf("odd\n");
		else printf("even\n");
	}else{
		for(int i=0;i<=n-1;i++)
			if(v[i]&1)
				f2=!f2;
		if(f2)printf("odd\n");
		else printf("even\n");
	}
	return 0;
}



