#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
#define getc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
ll read(){
    #define num ch-'0'
    char ch;bool flag=0;ll res;
    while(!isdigit(ch=getc()))
    (ch=='-')&&(flag=true);
    for(res=num;isdigit(ch=getc());res=res*10+num);
    (flag)&&(res=-res);
    #undef num
    return res;
}
const int N=5e5+5;
int n,w;ll c[N];
inline void add(int x,ll y){
    for(;x<=n+1;x+=x&-x) cmax(c[x],y);
}
ll query(int x){
    ll res=0;for(;x;x-=x&-x) cmax(res,c[x]);return res;
}
struct node{
    int x,y;ll v;
    inline bool operator <(const node &b)const
    {return x==b.x?y<b.y:x<b.x;}
}a[N];int b[N];
int main(){
	//freopen("data.in", "r", stdin);
	//freopen("data.ans", "w", stdout);
    w=read(),n=read();
    for(int i=1;i<=n;++i){
        int t=read(),p=read();a[i].v=read();
        a[i].x=2*t+p,a[i].y=2*t-p,b[i]=a[i].y;
    }
    sort(a+1,a+1+n),sort(b+1,b+n+1);
    for(int i=1;i<=n;++i){
        ll res=0;int pos=lower_bound(b+1,b+1+n,a[i].y)-b;
        res=query(pos)+a[i].v,add(pos,res);
    }
    printf("%lld\n",query(n+1));
    return 0;
}
