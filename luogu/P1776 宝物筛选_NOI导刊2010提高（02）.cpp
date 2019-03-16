#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1009;
struct Ob{int w,v;}g[N];
int read(){
    char c;int f=1,num;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return f*num;
}
int n,m,cnt,f[N];
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++){
        int a,b,c;
        a=read();b=read();c=read();
        for(int j=1;j<=c;j<<=1)g[++cnt]=(Ob){b*j,a*j},c-=j;
        if(c)g[++cnt]=(Ob){b*c,a*c};
    }
    for(int i=1;i<=cnt;i++)
        for(int j=m;j>=g[i].w;j--)
            f[j]=max(f[j],f[j-g[i].w]+g[i].v);
    printf("%d\n",f[m]);
    return 0;
}
