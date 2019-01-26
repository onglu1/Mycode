#include <bits/stdc++.h>
#define fa(x) tree[x].fa
#define son(x,k) tree[x].ch[k]
#define cnt(x) tree[x].cnt
#define val(x) tree[x].val
#define siz(x) tree[x].siz
using namespace std;
const int N=5e6+1009;
const int inf=(1<<31)-1;
struct Hp{
    priority_queue<int>q1,q2;
    Hp(){
        while(!q1.empty())q1.pop();
        while(!q2.empty())q2.pop();
    }
    void Insert(int x){
        q1.push(-x);
    }
    void Delete(int x){
        q2.push(-x);
    }
    int Top(){
        while(!q2.empty()&&!q1.empty()){
            if(q1.top()!=q2.top())return -q1.top();
            q1.pop();q2.pop();
        }
    }
}Heap;
int read(){
    char c;int num,f=1;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return f*num;
}
int abs(int x){return x<0?-x:x;}
int rt,tot;
int n,m,pos[N],minn=(1<<31)-1;
int ord[N][10],a[N],b[N];

struct Node{
    int fa,ch[2],siz,cnt,val;
}tree[N];
bool chk(int x){return son(fa(x),1)==x;}
void update(int x){siz(x)=siz(son(x,0))+siz(son(x,1))+cnt(x);}
int New(int x,int pre){
    tot++;
    if(pre)son(pre,x>val(pre))=tot;
    son(tot,0)=son(tot,1)=0;
    cnt(tot)=siz(tot)=1;
    val(tot)=x;fa(tot)=pre;
    return tot;
}
void rotate(int x){
    int y=fa(x),z=fa(y),k=chk(x);
    son(z,chk(y))=x;fa(x)=z;
    son(y,k)=son(x,k^1);fa(son(x,k^1))=y;
    son(x,k^1)=y;fa(y)=x;
    update(y);update(x);
}
void splay(int x,int goal=0){
    while(fa(x)!=goal){
        int y=fa(x),z=fa(y);
        if(z!=goal){
            if(chk(y)==chk(x))rotate(y);
            else rotate(x);
        }
        rotate(x);
    }
    if(!goal)rt=x;
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
    if(val(rt)<x||(val(rt)==x&&cnt(rt)>1))return rt;
    int cur=son(rt,0);
    while(son(cur,1))cur=son(cur,1);
    return cur;
}
int Succ(int x){
    Find(x);
    if(val(rt)>x||(val(rt)==x&&cnt(rt)>1))return rt;
    int cur=son(rt,1);
    while(son(cur,0))cur=son(cur,0);
    return cur;
}
int main()
{
    n=read();m=read();
    Insert(inf);Insert(-inf);
    for(int i=1;i<=n;i++){
        int x=read();
        pos[i]=x;
        b[i]++;
    }
    for(int i=1;i<=m;i++){
        char c[19];
        scanf("%s",c);
        int len=strlen(c);
        if(len==6){
            ord[i][0]=1;
            ord[i][1]=read();
            ord[i][2]=read();
            b[ord[i][1]]++;
            ord[i][3]=b[ord[i][1]];
        }else if(len==7)ord[i][0]=2;
        else ord[i][0]=3;
    }
    for(int i=1;i<=n;i++){
        if(i!=1)Heap.Insert(abs(pos[i]-pos[i-1]));
        if(minn!=0){
            Insert(pos[i]);
            int xx=val(Succ(pos[i])),yy=val(Pre(pos[i]));
            if(xx!=inf&&xx!=-inf)minn=min(minn,xx-pos[i]);
            if(yy!=inf&&yy!=-inf)minn=min(minn,pos[i]-yy);
        }
        a[b[i-1]+1]=pos[i];
        //cout<<b[i-1]+1<<endl;
        b[i]+=b[i-1];
    }
    //cout<<Heap.Top()<<endl;
    for(int i=1;i<=m;i++){
        if(ord[i][0]==1){
            if(minn!=0) Insert(ord[i][2]);
            a[b[ord[i][1]-1]+ord[i][3]]=ord[i][2];
            
            Heap.Insert(abs(a[b[ord[i][1]-1]+ord[i][3]]-a[b[ord[i][1]-1]+ord[i][3]-1]));
            Heap.Insert(abs(a[b[ord[i][1]-1]+ord[i][3]]-a[b[ord[i][1]]+1]));
            Heap.Delete(abs(a[b[ord[i][1]]+1]-a[b[ord[i][1]-1]+ord[i][3]-1]));
            if(minn!=0){
                int xx=val(Succ(ord[i][2])),yy=val(Pre(ord[i][2]));
                if(xx!=inf&&xx!=-inf)minn=min(minn,xx-ord[i][2]);
                if(yy!=inf&&yy!=-inf)minn=min(minn,ord[i][2]-yy);
            }
        }else if(ord[i][0]==2)
            printf("%d\n",Heap.Top());
        else printf("%d\n",minn);
    }
    return 0;
}
