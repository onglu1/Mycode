#include <bits/stdc++.h>
#define ll long long
#define Mid ((l+r)>>1)
#define ull unsigned long long
using namespace std;
const int N=1e7+100009;
struct Bead{
    int col;
    ll pos;
}a[N];
ll read(){
    char c;ll num,f=1;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return f*num;
}
int n,k,tot,f[1009],sum=0;
bool cmp(Bead a,Bead b){return a.pos<b.pos;}
int main()
{
    //freopen("6.in","r",stdin);
    n=read();k=read();
    if(k==1){
        printf("0\n");
        return 0;
    }
    for(int i=1;i<=k;i++){
        int num=read();
        for(int j=1;j<=num;j++){
            a[++tot].pos=read();
            a[tot].col=i;
        }
    }
    sort(a+1,a+1+n,cmp);
    int t=1;
    ll ans=(1ll<<60)-1;
    f[a[1].col]++;
    sum++;
    for(int i=1;i<=n-k+1;i++){
        while(sum!=k&&t<=n){
            t++;
            if(!f[a[t].col])sum++;
            f[a[t].col]++;
        }
        if(t>n)break;
        //cout<<ans<<endl;
        if(sum>=k)ans=min(ans,abs(a[t].pos-a[i].pos));
        f[a[i].col]--;
        if(!f[a[i].col])sum--;
        //左移一格之后清空 
    }
    printf("%lld\n",ans);
    return 0;
}

