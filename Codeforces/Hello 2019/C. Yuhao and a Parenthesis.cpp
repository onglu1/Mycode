#include <bits/stdc++.h>
using namespace std;
const int Base=10000000;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
string s;
int n,ans,b[20000009];
int main()
{
	n=read();
	for(int i=1;i<=n;i++){
		cin>>s;
		int r=0,l=0,len=s.size(),tmp;
		for(int j=0;j<len;j++){
			if(s[j]==')'){
				if(l==0)r++;
				else l--;
			}else l++;
		}
		if(l>0&&r>0)continue;
		else tmp=l-r;
		if(b[-tmp+Base]){
			b[-tmp+Base]--;
			ans++;
		}else {
			b[tmp+Base]++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
 
/*
���� ������n����������
ÿ��ѡ��������ϣ�Ҫ����ϵĶ������
ÿ�Ӷ��ǺϷ����С�
���ȷ�����������ϱ����ǵ������У�
Ҳ�����������ŵ���֮��ʣ�µĶ��ǳ�����߳��ҵ�
����Ϊ������Ϊ��������Ͱ�ﱩ�����ҾͿ�����
�ѵ���ͳ��
һ��������ֻ�ܵ�������������ߵ�������
��֮��Ȼ
�����Ǵ�������ͳ�Ƶ�
һ��ʼ���ֵ������ſ϶�û�취������������������� 
Ȼ����ֵ����������Ǽ�¼���������������������ž͵�����
������������ͼ�����������С�
����ٿ�����û�����ң�����ʣ�࣬���еĻ�ֱ�������� 
������һ���Ļ���¼������ok�ˡ� 
*/ 

