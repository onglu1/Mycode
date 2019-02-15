#include <bits/stdc++.h>
#define ll long long
#define Mid ((l+r)>>1)
#define ull unsigned long long
#define son(x,k) tree[x].ch[k]
#define val(x) tree[x].val
#define siz(x) tree[x].siz
#define fa(x) tree[x].fa
#define cnt(x) tree[x].cnt
using namespace std;
const int N=4e5+1009;
const int inf=(1<<31)-1;
struct node{int fa,ch[2],siz,cnt,val;}tree[N];
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
int readc(){
	char c=getchar();
	while(c!='I'&&c!='A'&&c!='S'&&c!='F')c=getchar();
	if(c=='I')return 1;
	if(c=='A')return 2;
	if(c=='S')return 3;
	if(c=='F')return 4;
}
int rt,tot;
int chk(int x){return (son(fa(x),1)==x);}
void update(int x){siz(x)=siz(son(x,0))+siz(son(x,1))+cnt(x);}
void rotate(int x){
	int y=fa(x),z=fa(y),k=chk(x);
	if(rt==y)rt==x;
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
void fid(int x){
	//原数的前驱或者后继 
	if(!rt)return ;
	int cur=rt;
	while(son(cur,x>val(cur))&&val(cur)!=x)
		cur=son(cur,x>val(cur));
	splay(cur);
}
int Suc(int x){
	fid(x);
	if(val(rt)>x)return rt;
	int cur=son(rt,1);
	while(son(cur,0))cur=son(cur,0);
	return cur;
}
int kth(int k){
	int cur=rt;
	while(1){
		if(siz(son(cur,1))>=k)cur=son(cur,1);
		else if(siz(son(cur,1))+cnt(cur)>=k)return cur;
		else k-=siz(son(cur,1))+cnt(cur),cur=son(cur,0);
	}
}
int n,minn;
int main()
{
	//freopen("2.in","r",stdin);
	//freopen("data.out","w",stdout);
	int del=0,sum=0;
	//Insert(-inf);Insert(inf);
	n=read();minn=read()-1;
	for(int i=1;i<=n;i++){
		int opt=readc(),x=read();
		if(opt==1)
			if(x>=minn+1)Insert(x+del-minn),sum++;
		if(opt==2)del-=x;
		if(opt==3){
			del+=x;
			Insert(del);
			fid(del);
			//sum+=siz(son(rt,0))+cnt(rt)-1;
			rt=son(rt,1);
			fa(rt)=0;
		}
		
		if(opt==4)printf("%d\n",(x>siz(rt))?-1:(val(kth(x))-del+minn));
		//cout<<val(rt)<<" "<<del<<endl;
	}
	printf("%d\n",sum-siz(rt));
	return 0;
}








