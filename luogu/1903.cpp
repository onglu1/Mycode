#include <bits/stdc++.h>
#define pos(x) (x/block)
using namespace std;
const int N=5e6+1009;
struct Q{
    int l,r,id,t;
}q[N];
int read(){
    char c;int num,f=1;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return f*num;
}
int a[N],cg[N],p[N];
int nl=1,nr=1,nt=1;
int n,tt,cnt=1,m,block;
int num[N],now,ans[N];
bool cmp(Q a,Q b){
    if(pos(a.l)^pos(b.l))return a.l<b.l;
    if(pos(a.r)^pos(b.r))return a.r<b.r;
    return a.t<b.t;
}
void modify(int k){
    if(p[k]>=nl&&p[k]<=nr){
        now-=!--num[a[p[k]]];
        now+=!num[cg[k]]++;
    }
    swap(cg[k],a[p[k]]);
} 
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    n=read();tt=read();
    block=pow(n,0.666666);
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=tt;i++){
        char c;
        int l,r;
        scanf("%c",&c);
        l=read();r=read();
        if(c=='Q')q[++m]=(Q){l,r,m,cnt};
        else{
            p[++cnt]=l;
            cg [  cnt]=r;
        }
    }
    sort(q+1,q+1+m,cmp);
    now=1;num[a[1]]=1;
    //cout<<m<<endl;
    for(int i=1;i<=m;i++){
        int l=q[i].l,r=q[i].r,t=q[i].t;
        while(nt<(t+1))modify(nt++);
        while(nt>(t+1))modify(--nt);
        /*if(i==2){
            cout<<t<<endl;
            cout<<a[2]<<endl;
            cout<<endl;
        }*/
        while(nl<l)now-=!--num[a[nl++]];
        while(nl>l)now+=!num[a[--nl]]++;
        while(nr<r)now+=!num[a[++nr]]++;
        while(nr>r)now-=!--num[a[nr--]];
        ans[q[i].id]=now;
        //if(q[i].id==4)cout<<i<<endl;
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
