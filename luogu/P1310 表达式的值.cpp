#include <bits/stdc++.h>
#define ll long long
#define Mid ((l+r)>>1)
#define ull unsigned long long
using namespace std;
const int N=19260817;
const int mod=10007;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
char sta[N],s[N];
int f0[N],f1[N],t1,t2,n;
int n0=1,n1=1;
int main()
{
	//freopen("data.in","r",stdin);
	n=read()+2;
	cin>>(s+1);
	s[0]='(';s[n-1]=')';
	for(int i=0;i<n;i++){
		if(s[i]=='*'){
			t1++;t2++;
			f0[t1]=n0;
			f1[t1]=n1;
			n0=1;n1=1;
			sta[t2]='*';
		}
		if(s[i]=='+'){
			t1++;
			f0[t1]=n0;
			f1[t1]=n1;
			n0=1;n1=1;
			while(t2&&sta[t2]=='*'){
				t1--;t2--;
				int a=(f0[t1]*f1[t1+1]%mod+f1[t1]*f0[t1+1]%mod+f0[t1]*f0[t1+1]%mod)%mod;
				int b=(f1[t1]*f1[t1+1])%mod;
				f0[t1]=a;
				f1[t1]=b;
			}
			sta[++t2]='+';
		}
		if(s[i]=='(')sta[++t2]='(';
		if(s[i]==')'){
			t1++;
			f0[t1]=n0;
			f1[t1]=n1;
			while(t2&&sta[t2]=='*'){
				//cout<<i<<" "<<endl;
				t1--;t2--;
				int a=(f0[t1]*f1[t1+1]%mod+f1[t1]*f0[t1+1]%mod+f0[t1]*f0[t1+1]%mod)%mod;
				int b=(f1[t1]*f1[t1+1])%mod;
				f0[t1]=a;
				f1[t1]=b;
			}
			while(t2&&sta[t2]=='+'){
				t1--;t2--;
				int a=(f0[t1]*f0[t1+1])%mod;
				int b=(f1[t1]*f0[t1+1]%mod+f0[t1]*f1[t1+1]%mod+f1[t1]*f1[t1+1]%mod)%mod;
				f0[t1]=a;
				f1[t1]=b;
			}
			/*for(int i=1;i<=t1;i++)
				cout<<f1[i]<<" ";
			cout<<endl;*/
			n0=f0[t1]%mod;n1=f1[t1]%mod;
			t2--;t1--;
		}
	}
	printf("%d\n",n1);
	return 0;
}
/*
����һ��ʽ��f[0]��ʾʽ��Ϊ0�ķ�����f[1]��ʾʽ��Ϊ1�ķ���
���ڵ�������f[0]=f[1]=1;
����һ���˺�f[0]=fzuo[0]*fyou[1]+fzuo[1]*fyou[0]+fzuo[0]*fyou[0]
����һ���Ӻ�f[0]=fzuo[0]*fyou[0]
����һ����׺���ʽ
����һ���Ӻţ�����һֱ����˺�ֱ���ӺŻ��������� 
����һ���˺ţ�ֱ����ջ
����һ�������ţ�ֱ����ջ
����һ�������ţ�����һֱ�������� 
 */
