#include <bits/stdc++.h>
#define fa(x) tree[x].fa
#define son(x,k) tree[x].ch[k]
#define val(x) tree[x].val
#define siz(x) tree[x].siz 
#define rev(x) tree[x].rev
using namespace std;
const int N=1e6+1009;
int read(){
    char c;int num,f=1;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return f*num;
}
int rt=1,tot,n,m;
struct Node{
    int fa,ch[2],val,siz,rev;
}tree[N];
void update(int x){siz(x)=siz(son(x,0))+siz(son(x,1))+1;}
void build(int l,int r,int rt){
    if(r<l)return ;
    if(l==r){
        son(rt,0)=son(rt,1)=0;
        siz(rt)=1;val(rt)=l;
        return ;
    }
    int mid=(l+r)>>1;
    val(rt)=mid;
    if(mid-1>=l){
        son(rt,0)=rt<<1;
        fa(rt<<1)=rt;
        build(l,mid-1,rt<<1);
    }
    if(mid+1<=r){
        son(rt,1)=rt<<1|1;
        fa(rt<<1|1)=rt;
        build(mid+1,r,rt<<1|1);
    }
    update(rt);
}
void pushdown(int x){
    if(rev(x)){
        rev(x)=0;
        rev(son(x,0))^=1;
        rev(son(x,1))^=1;
        swap(son(x,0),son(x,1));
    }
}
void print(int x){
    pushdown(x);
    if(son(x,0))print(son(x,0));
    if(val(x)>1&&val(x)<n+2)printf("%d ",val(x)-1);
    if(son(x,1))print(son(x,1));
}
int chk(int x){return son(fa(x),1)==x;}
void rotate(int x){
    int y=fa(x),z=fa(y),k=chk(x);
    //pushdown(y);pushdown(x);
    son(y,k)=son(x,k^1);fa(son(x,k^1))=y;
    son(z,chk(y))=x;fa(x)=z;
    son(x,k^1)=y;fa(y)=x;
    update(y);update(x);
}
void splay(int x,int goal=0){
    while(fa(x)!=goal){
        int y=fa(x);
        if(fa(y)!=goal){
            if(chk(y)==chk(x))rotate(y);
            else rotate(x);
        }
        rotate(x);
        //cout<<x<<endl;
    }
    if(!goal)rt=x;
}
int kth(int k){
    int cur=rt;
    //cout<<k<<endl;
    while(cur){
        //cout<<cur<<" ";
        pushdown(cur);
        if(siz(son(cur,0))>=k)cur=son(cur,0);
        else if(siz(son(cur,0))+1==k)return cur;
        else k-=siz(son(cur,0))+1,cur=son(cur,1);
    }
    //cout<<endl;
}
int main()
{
    n=read(),m=read();
    build(1,n+2,1);
    //print(rt);
    for(int i=1;i<=m;i++){
        //cout<<rt<<endl;
        int l=kth(read()),r=kth(read()+2);
        //cout<<l<<" "<<r<<endl;
        splay(l);splay(r,l);
        rev(son(r,0))^=1;
        //print(rt);
    }
    print(rt);
    return 0;
}
