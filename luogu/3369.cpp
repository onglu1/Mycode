#include <bits/stdc++.h>
#define fa(x) tree[x].fa
#define son(x,k) tree[x].ch[k]
#define siz(x) tree[x].siz
#define val(x) tree[x].val
#define cnt(x) tree[x].cnt
using namespace std;
const int N=1e6+1009;
const int inf=(1<<31)-1;
int read(){
    char c;int num,f=1;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return f*num;
}
struct Node{
    int fa,ch[2],siz,cnt,val;
}tree[N];
int tot,rt=0;
void update(int x){siz(x)=siz(son(x,0))+siz(son(x,1))+cnt(x);}
bool chk(int x){return son(fa(x),1)==x;}
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
int New(int x,int pre){
    tot++;
    if(pre)son(pre,x>val(pre))=tot;
    son(tot,0)=son(tot,1)=0;
    val(tot)=x;fa(tot)=pre;
    siz(tot)=cnt(tot)=1;
    return tot;	
}
void Insert(int x){
    int cur=rt,p=0;
    while(cur&&val(cur)!=x)
        p=cur,cur=son(cur,x>val(cur));
    if(cur)cnt(cur)++;
    else cur=New(x,p);
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
int Kth(int k){
    int cur=rt;
    while(1){
        if(siz(son(cur,0))>=k&&son(cur,0))cur=son(cur,0);
        else if(siz(son(cur,0))+cnt(cur)>=k)return cur;
        else k-=siz(son(cur,0))+cnt(cur),cur=son(cur,1);
    }
}
void Delete(int x){
    int lst=Pre(x),nxt=Succ(x);
    splay(lst);splay(nxt,lst);
    int del=son(nxt,0);
    if(cnt(del)>1)cnt(del)--,splay(del);
    else son(nxt,0)=0;
}
int main()
{
    int n=read();
    Insert(inf);Insert(-inf); 
    for(int i=1;i<=n;i++){
        int opt=read(),x=read();
        //if(i==1)cout<<opt<<" "<<x<<endl;
        if(opt==1)Insert(x);
        if(opt==2)Delete(x);
        if(opt==3)Find(x),printf("%d\n",siz(son(rt,0)));
        if(opt==4)printf("%d\n",val(Kth(x+1)));
        if(opt==5)printf("%d\n",val(Pre(x)));
        if(opt==6)printf("%d\n",val(Succ(x))); 
    }
    return 0;
}
