#include <bits/stdc++.h>
#define ll long long 
#define son(x,k) tree[x].ch[k]
#define w(x) tree[x].w
#define val(x) tree[x].val
#define siz(x) tree[x].siz
#define fa(x) tree[x].fa
using namespace std;
const int N=1e6+1009;
const int inf=(1<<31)-1;

ll read(){
    char c;ll num,f=1;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return f*num;
}
struct Node{
    int ch[2],fa,siz;
    ll w,val;
}tree[N];
ll ans1,ans2;
int rt,tot,num;
void update(int x){siz(x)=siz(son(x,0))+siz(son(x,1))+1;}
int chk(int x){return son(fa(x),1)==x;}
void rotate(int x){
    int y=fa(x),z=fa(y),k=chk(x);
    son(y,k)=son(x,k^1);fa(son(x,k^1))=y;
    son(z,chk(y))=x;fa(x)=z;
    son(x,k^1)=y;fa(y)=x;
    update(y);update(x);
}
void splay(int x,int goal=0){
    while(fa(x)!=goal){
        int y=fa(x),z=fa(y);
        if(z!=goal){
            if(chk(x)==chk(y))rotate(y);
            else rotate(x);
        }
        rotate(x);
    }
    if(!goal)rt=x;
}
void Insert(ll a,ll b){
    int cur=rt,p=0;
    while(val(cur)!=b&&cur)
        p=cur,cur=son(cur,b>val(cur));
    if(!cur){
        cur=++tot;ans1+=a;ans2+=b;
        if(p)son(p,b>val(p))=cur;
        fa(cur)=p;siz(cur)=1;
        val(cur)=b;w(cur)=a;
        son(cur,0)=son(cur,1)=0;
        num++;
    }
    splay(cur);
}
void Find(int x){
    if(!rt)return ;
    int cur=rt;
    while(son(cur,x>val(cur))&&val(cur)!=x)
        cur=son(cur,x>val(cur));
    splay(cur);
}
int Pre(int x){
    Find(x);
    if(val(rt)<x)return rt;
    int cur=son(rt,0);
    while(son(cur,1))cur=son(cur,1);
    return cur;
}
int Succ(int x){
    Find(x);
    if(val(rt)>x)return rt;
    int cur=son(rt,1);
    while(son(cur,0))cur=son(cur,0);
    return cur;
}
void Delete(int x){
    int lst=Pre(x),nxt=Succ(x);
    splay(lst);splay(nxt,lst);
    son(nxt,0)=0;
}
int main()
{
    int opt;
    Insert(0,inf);Insert(0,-inf);
    while((opt=read())!=-1){
        if(opt==1){
            ll a=read(),b=read();
            Insert(a,b);
        }
        if(opt==2){
            int x=Pre(inf);
            if(val(x)!=-inf){
                ans1-=w(x);ans2-=val(x);
                Delete(val(x));
            }
        }
        if(opt==3){
            int x=Succ(-inf);
            if(val(x)!=inf){
                ans1-=w(x);ans2-=val(x);
                Delete(val(x));
            }
        }
        
    }
    //dfs(rt);
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
