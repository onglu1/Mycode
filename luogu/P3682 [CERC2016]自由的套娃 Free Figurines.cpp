#include <bits/stdc++.h>
#define ll long long
#define Mid ((l+r)>>1)
#define ull unsigned long long
using namespace std;
const int N=19260817;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int a[N],b[N],n,ans,sum=0;
int f1[N];
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++){
		if(f1[i])continue;
		int t1=i,t2=i;
		while(a[t1]==b[t2]&&a[t1]!=0&&b[t2]!=0){
			f1[t1]=1;
			t1=a[t1];
			t2=b[t2];
			if(t1==t2&&t1!=0&&t2!=0)ans-=2;
		}
		for(;t1;t1=a[t1])f1[t1]=1;
	}
	//ans*=2;
	for(int i=1;i<=n;i++)
		ans+=(a[i]!=0)+(b[i]!=0);
	printf("%d\n",ans);
	return 0;
}
/*
一个链表组
一个目标链表组
每次的操作可以把链的最大的一个分离出来
或者把一个比链尾大的元素接到链的后面
可以先把目标组分离成链
然后标记出在同一条链的一些个体
然后对于链表组
然后对于一条链，只有开头的一段可以保留，其他都要拆出来
那么多少可以保留呢？
要保留的部分就是开头在目标中也是连续的一段
找出起始组中的每个队头，往后拓展，同时目标组中也要往后拓展
直到不一样为止，拓展的部分是能保留的部分，其他的都要拆掉。
拆掉的操作数是(len-l)
接下来的操作数是sum-1-(k-1) 
*/ 










