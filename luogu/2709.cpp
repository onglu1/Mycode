#include <bits/stdc++.h>
#define pos(a) (a/block)
using namespace std;
const int N=5e6+1009;
struct Q{
    int l,r,id; 
}q[N];
int read(){
    char c;int num,f=1;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return f*num;
}
int n,m,k,a[N],now=0;
int cnt[N],block,ans[N];
bool cmp(Q a,Q b){
    return   (pos(a.l)^pos(b.l))?a.l<b.l:(pos(a.l)&1)?(a.r<b.r):(a.r>b.r);
}
void add(int x){
    now+=cnt[a[x]]*2+1;
    cnt[a[x]]++;
} 
void del(int x){
    now-=cnt[a[x]]*2-1;
    cnt[a[x]]--;
}
int main()
{
    n=read();m=read();k=read();
    block=n/sqrt(m*2/3);
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=m;i++){
        q[i].id=i;
        q[i].l=read();
        q[i].r=read();
    }
    sort(q+1,q+1+m,cmp);
    int nl=1,nr=1;add(1);
    for(int i=1;i<=m;i++){
        int l=q[i].l,r=q[i].r;
        while(nr>r)del(nr--);
        while(nr<r)add(++nr);
        while(nl<l)del(nl++);
        while(nl>l)add(--nl);
        ans[q[i].id]=now; 
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
