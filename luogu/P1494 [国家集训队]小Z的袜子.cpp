#include <bits/stdc++.h>
#define ll long long
#define pos(x) (x/block)
using namespace std;
const int N=5e6+1009;
struct Q{
    int l,r,id;
}q[N];
ll read(){
    char c;ll num,f=1;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return f*num;
}
int n,m,block,cnt[N],a[N];
ll now,ans[N][2];
bool cmp(Q a,Q b){
    return (pos(a.l)^pos(b.l))?a.l<b.l:(pos(a.l)&1)?(a.r<b.r):(a.r>b.r);
}
ll gcd(ll a,ll b){return (b==0)?a:gcd(b,a%b);}
void del(int x){
    if(cnt[a[x]]>=2)now-=2ll*cnt[a[x]]-2;
    cnt[a[x]]--;
}
void add(int x){
    if(cnt[a[x]]>0)now+=2ll*cnt[a[x]];
    cnt[a[x]]++;	
}
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    n=read();m=read();block=n/sqrt(m*2/3);
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=m;i++){
        q[i].id=i;
        q[i].l=read();
        q[i].r=read();
    }
    sort(q+1,q+1+m,cmp);
    int nl=1,nr=1;
    add(1);
    for(int i=1;i<=m;i++){
        int l=q[i].l,r=q[i].r,id=q[i].id;
        if(l==r){
            ans[id][0]=0;
            ans[id][1]=1;
            continue;
        }
        while(nr>r)del(nr--);
        while(nr<r)add(++nr);
        while(nl>l)add(--nl);
        while(nl<l)del(nl++);
        ll tmp=now,d=gcd(now,1ll*(r-l+1)*(r-l));
        //for(int i=1;i<=3;i++)cout<<cnt[i]<<" ";
        //cout<<endl;
        //cout<<tmp<<" "<<l<<" "<<r<<" "<<id<<endl;
        ans[id][0]=tmp/d;
        ans[id][1]=1ll*(r-l+1)*(r-l)/d;
    }
    for(int i=1;i<=m;i++)
        printf("%lld/%lld\n",ans[i][0],ans[i][1]);
    return 0;
}
