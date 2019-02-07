#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+1009;
struct dish{
	ll cost;int id;
};
ll read(){
	char c;ll num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int n,m,flag;
ll num[N],c[N];
priority_queue<dish>q;
bool operator<(const dish &a,const dish &b){return a.cost>b.cost;}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)num[i]=read();
	for(int j=1;j<=n;j++){
		c[j]=read();
		q.push((dish){c[j],j});
	}
	for(int i=1;i<=m;i++){
		if(flag){
			cout<<0<<endl;
			continue;
		}
		int id=read(),nu=read();
		ll ans=0;
		if(num[id]){
			//ans+=min(num[id],1ll*nu)*c[id];
			int del=min(num[id],1ll*nu);
			num[id]-=del;
			nu-=del;
			ans+=c[id]*del;
		}
		while(nu){
            if(q.empty()){
                flag=1;
                i--;break;
            }
			dish tmp=q.top();
			while(num[tmp.id]<=0){
				q.pop();if(q.empty()){flag=1;break;}
				tmp=q.top();
			}
			if(flag){i--;break;}
			int del=min(num[tmp.id],1ll*nu);
			num[tmp.id]-=del;
			nu-=del;
			ans+=c[tmp.id]*del;
		}
		if(!flag)cout<<ans<<endl;
	}
	return 0;
}
/*
���⣺
��һ�в˵��������ڶ��в˵ļ۸�
ÿ���˿͹�����ˣ�x��y��ʾ��x�̵�y��
��������͸�������˵Ĳˣ����û���˾����0
��ô�о���ƽ����������
����һ�������˵������ɣ�
Ȼ�󶪽����ȶ���ά������

*/

