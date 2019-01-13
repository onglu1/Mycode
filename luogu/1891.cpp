#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+1009;
int read(){
    char c;int num,f=1;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return f*num;
}
int phi[N],f[N],pri[N],tot;
int gcd(int a,int b){return (b==0)?a:gcd(b,a%b);}

void init(){
    phi[1]=1;
    for(int i=2;i<=N;i++){
        if(!f[i]){
            pri[++tot]=i;
            phi[i]=i-1;
        }
        for(int j=1;j<=tot;j++){
            if(i*pri[j]>N)break;
            f[i*pri[j]]=1;
            if(i%pri[j]==0){
                phi[i*pri[j]]=phi[i]*pri[j];break;
            }else {
                phi[i*pri[j]]=phi[i]*(pri[j]-1);
            }
        }
    }
}
void work(){
    int n=read(),tt=sqrt(n);
    ll sum=1;
    for(int i=2;i<=tt;i++){
        if(n%i==0){
            sum+=1ll*i*phi[i]/2;
            if(i*i!=n)
            sum+=1ll*(n/i)*phi[n/i]/2;
        }
    }
    sum+=1ll*n*phi[n]/2;
    sum*=n;
    printf("%lld\n",sum);
}
int main()
{
    init();
    int Case=read();
    while(Case--)work();
    return 0;
}
