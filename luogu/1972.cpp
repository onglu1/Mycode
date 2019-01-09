// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
const int N=5e6+1009;
struct Q{
    int l,r,id;
    Q(int aa=0,int bb=0,int cc=0){l=aa;r=bb;id=cc;}
}q[N];
int read(){
    char c;int num,f=1;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return f*num;
}
int n,m,a[N],block,ans[N];
int cnt[N],now=0;
bool cmp(Q a,Q b){
    return ((a.l/block)^(b.l/block))?(a.l/block)<(b.l/block):(((a.l/block)&1)?a.r<b.r:a.r>b.r);
}
void add(int x){
    if(!cnt[a[x]])now++;
    cnt[a[x]]++;
}
void del(int x){
    --cnt[a[x]];
    if(!cnt[a[x]])now--;
}
int main()
{
    n=read();for(int i=1;i<=n;i++)a[i]=read();
    m=read();for(int j=1;j<=m;j++){
        q[j].id=j;
        q[j].l=read();
        q[j].r=read();
    }
    block=n/sqrt(m*2/3);
    sort(q+1,q+1+m,cmp);
    int nl=1,nr=1;
    add(1); 
    for(int i=1;i<=m;i++){
        int l=q[i].l,r=q[i].r;
        while(nr<r)now+=!cnt[a[++nr]]++;
        while(nr>r)now-=!--cnt[a[nr--]];
        while(nl<l)now-=!--cnt[a[nl++]];
        while(nl>l)now+=!cnt[a[--nl]]++;
        ans[q[i].id]=now;
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
