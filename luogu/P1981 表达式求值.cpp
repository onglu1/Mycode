#include <bits/stdc++.h>
#define ll long long
#define Mid ((l+r)>>1)
#define ull unsigned long long
using namespace std;
const int N=1e7+1009;
const int mod=10000;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int sta1[N],sta2[N],t1,t2;
char s[N];
int main()
{
	//int siz=sizeof sta1+sizeof sta2+sizeof t1+sizeof t2+sizeof s;
	//cout<<(siz/1024/1024)<<"MB"<<endl;
	int tmp=0,n;
	cin>>s;n=strlen(s);
	s[n++]='+';s[n++]='0';
	//cout<<s<<endl;
	for(int i=0;i<n;i++){
		if(isdigit(s[i]))tmp=(tmp*10+s[i]-'0')%mod;
		else {
			int k;
			k=(s[i]=='*');
			sta1[++t1]=tmp%mod;
			tmp=0;
			while(t2&&sta2[t2]>k){
				int tt=(sta1[t1]*sta1[t1-1])%mod;
				sta1[--t1]=tt;t2--;
			}
			sta2[++t2]=k;
		}
	}
	t2--;
	int ans=0;
	while(t1)ans=(ans+sta1[t1--])%mod;
	printf("%d\n",ans);
	return 0;
}







