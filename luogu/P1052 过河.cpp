#include <bits/stdc++.h>
using namespace std;
const int N=5e6+1009;
int read(){
    char c;int num,f=1;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return f*num;
}
int l,s,t,n,st[1009];
int vis[N],f[N];
int main()
{
    //freopen("testdata.in","r",stdin);
    memset(f,0x3f,sizeof(f));
    memset(vis,0,sizeof(vis));
    l=read();s=read();
    t=read();n=read();
    for(int i=1;i<=n;i++)st[i]=read();
    sort(st+1,st+1+n);
    for(int i=n;i>=2;i--)st[i]-=st[i-1];
    for(int i=1;i<=n;i++)
        st[i]%=2520;
    for(int i=1;i<=n;i++){
        st[i]+=st[i-1];
        vis[st[i]]=1;
    }
    l=st[n];
    int ans=0x3f3f3f3f;
    f[0]=0;
    for(int i=0;i<=l;i++)
        for(int j=s;j<=t;j++)
            f[i+j]=min(f[i+j],f[i]+vis[i+j]);
    for(int i=l;i<l+t;i++)
        ans=min(ans,f[i]);
    printf("%d\n",ans);
    return 0;
}
/*
直观的方案：
f[i]=min{f[i-k]+stone[i],s<=k<=t}
发现石头较少然后独木桥较长。
发现每次跳的距离也是很短的。
我们可以根据石头之间的间隔直接计算。
我们发现lcm(1~10)=2520，也就是说不管当前能跳是多少
我们都能跳到2520格以后。
据此我们可以缩放石头间的距离。 
*/ 
 
