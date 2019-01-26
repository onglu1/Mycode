#include <bits/stdc++.h>
using namespace std;
const int N=5e5+1009;
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
    return (a.l/block==b.l/block)?a.r<b.r:a.l/block<b.l/block;
}
void add(int x){now+=!cnt[a[x]]++;}
void del(int x){now-=!--cnt[a[x]];}
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int j=1;j<=m;j++){
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
        while(nr<r)add(++nr);
        while(nr>r)del(nr--);
        while(nl<l)del(nl++);
        while(nl>l)add(--nl);
        ans[q[i].id]=(now==(r-l+1));
    }
    for(int i=1;i<=m;i++)
        printf("%s\n",ans[i]?"Yes":"No");
    return 0;
}
