#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+1009;
int cnt;
ll num[N],n,b,minn=-1,nn[N];
int main()
{
	cin>>n>>b;
	for(int i=2;i<=sqrt(b);i++){
		if(b%i)continue;
		num[++cnt]=i;b/=i;
		nn[cnt]=1;
		while(b%i==0){
			nn[cnt]++;
			b/=i;
		}
	}
	if(b>1)num[++cnt]=b,nn[cnt]=1;
	for(int i=1;i<=cnt;i++){
		ll tmp=n,sum=0;
		while(tmp){
			sum+=tmp/num[i];
			tmp/=num[i];
		}
		if(minn==-1)minn=sum/nn[i];
		else minn=min(minn,sum/nn[i]);
	}
	cout<<minn<<endl;
	return 0;
}
