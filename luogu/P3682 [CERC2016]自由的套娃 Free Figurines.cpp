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
һ��������
һ��Ŀ��������
ÿ�εĲ������԰���������һ���������
���߰�һ������β���Ԫ�ؽӵ����ĺ���
�����Ȱ�Ŀ����������
Ȼ���ǳ���ͬһ������һЩ����
Ȼ�����������
Ȼ�����һ������ֻ�п�ͷ��һ�ο��Ա�����������Ҫ�����
��ô���ٿ��Ա����أ�
Ҫ�����Ĳ��־��ǿ�ͷ��Ŀ����Ҳ��������һ��
�ҳ���ʼ���е�ÿ����ͷ��������չ��ͬʱĿ������ҲҪ������չ
ֱ����һ��Ϊֹ����չ�Ĳ������ܱ����Ĳ��֣������Ķ�Ҫ�����
����Ĳ�������(len-l)
�������Ĳ�������sum-1-(k-1) 
*/ 










