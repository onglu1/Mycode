#include <bits/stdc++.h>
using namespace std;
struct line{
	double s,t;
}a[100009];
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,r,tot;
void add(double x,double l){a[++tot].s=x-l;a[tot].t=x+l;}
bool operator<(const line &a,const line &b){return a.t<b.t;}
int main()
{
	int ccnt=1;
	while(n=read()){
		r=read();tot=0;
		memset(a,0,sizeof(a)); 
		int flag=0;
		for(int i=1;i<=n;i++){
			int x=read(),y=read();
			add((double)x,sqrt(r*r-y*y)); 
			if(y>r)flag=1; 
		}
		printf("Case %d: ",ccnt++);
		if(flag){
			printf("-1\n");
			continue;
		}
		sort(a+1,a+1+n);
		int cnt=1,pos=1;
		for(int i=1;i<=n;i++)
			if(a[i].s>a[pos].t)pos=i,cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
