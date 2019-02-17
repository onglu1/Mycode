#include <bits/stdc++.h>
#define ll long long
#define Mid ((l+r)>>1)
#define ull unsigned long long
using namespace std;
const int N=19260817;
struct UF{
    int pre[509],cnt=0;
    int fid(int x){
        return pre[x]?(pre[x]=fid(pre[x])):x;
    }
    void comb(int x,int y){
        x=fid(x);y=fid(y);
        if(x!=y)pre[x]=y,cnt++;
    }
}l[10009],r[10009],tmp;
int read(){
    char c;int num,f=1;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return f*num;
}
int n,m,k,a[10009][2];
int main()
{
    n=read();m=read();
    for(int i=1;i<=m;i++){
        a[i][0]=read();
        a[i][1]=read();
        l[i]=l[i-1];
        l[i].comb(a[i][0],a[i][1]);
    }
    for(int i=m;i>0;i--){
        r[i]=r[i+1];
        r[i].comb(a[i][0],a[i][1]);
    }
    k=read();
    for(int i=1;i<=k;i++){
        int L=read(),R=read();
        tmp=l[L-1];
        for(int j=1;j<=n;j++)
            if(r[R+1].pre[j])tmp.comb(j,r[R+1].pre[j]);
        printf("%d\n",n-tmp.cnt);
    }
    return 0;
}
