#include <bits/stdc++.h>
using namespace std;
const int N=4e5+1009;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return num*f;
}
int rl[N],id[N],cnt=-1;
int n,m,fa[N],dep[N],siz[N],top[N],son[N];
set<int>S[N];
void Add_Son(int u,int v){S[u].insert(v);fa[v]=u;}
void Delete_Son(int u,int v){
	set<int>::iterator it;
	it=S[u].find(v);
	if(it!=S[u].end())S[u].erase(it);
	fa[v]=0;
}
void dfs1(int x,int deep){
	set<int>::iterator it;
	dep[x]=deep;siz[x]=1;
	//cout<<"Outside:"<<x<<endl;
	for(it=S[x].begin();it!=S[x].end();it++){
		int y=*it;
		//cout<<"Inside:"<<y<<endl;
		dfs1(y,deep+1);
		siz[x]+=siz[y];
		if(siz[y]>=siz[son[x]])son[x]=y;
	}
	//cout<<x<<endl;
}
void dfs2(int x,int ltp){
	set<int>::iterator it;
	top[x]=ltp;
	id[x]=++cnt;rl[cnt]=x;
	if(son[x])dfs2(son[x],ltp);
	for(it=S[x].begin();it!=S[x].end();it++){
		int y=*it;
		if(y==son[x])continue;
		dfs2(y,y);
	}
}
void Ask(int x){
	int ans=0;
 	while(fa[x]!=0){
		ans+=id[x]-id[top[x]]+1;
		x=fa[top[x]];
	}
	printf("%d\n",ans-1);
}
void Modify(int x,int y){
	int bg=id[x];
	for(int i=id[x]+1;top[rl[i]]==top[x];i++)
		top[rl[i]]=x;
	top[x]=x;
	Delete_Son(fa[x],x);
	fa[x]=y;
	Add_Son(fa[x],x);
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		int x=read();
		Add_Son((i+x>n)?n+1:(i+x),i);
	}
	/*for(it=S[3].begin();it!=S[3].end();it++){
		int y=*it;
		cout<<y<<endl;
	}*/
	dfs1(n+1,0);dfs2(n+1,n+1);
	//cout<<dep[1]<<endl;
	m=read();
	for(int i=1;i<=m;i++){
		int opt=read(),x=read(),y;
		if(opt==1){Ask(x+1);}
		if(opt==2){y=read();Modify(x+1,(x+y+1>n)?n+1:(x+y+1));}
	}
	return 0;
}
/*
很容易想到可以理解成一棵多叉树
然后问题就变成了给定一棵树，每次指定一个节点
询问它到根节点的距离。
同时这棵树带修。
静态的树很好实现（直接dp都可以）
带修怎么搞。。
如果我们把一棵子树换了父亲，那么我们要修改整棵树的距离
好麻烦啊。。
树剖维护吗？
有点麻烦，因为一旦修改了树的结构，树剖的结构就要打破了
一次修改可能是O(n)的。
Splay？
换爹还是难啊。。。
一个不错的思路是可以把要修改的节点旋转到根节点
标记节点编号之后删除父亲关系
然后再连接到新的父亲上
不过是多叉树啊
左兄弟右儿子转二叉树还是不现实
发现很多的平衡树都是二叉结构的。。
或许不能用平衡树写。。
继续用树剖想想看。。
静态的话直接找重链跳根然后深度求和就可以了
动态的话。。
换爹会带来什么影响呢。。
首先一条重链可能被拆开
重链前半段的top不变，后半段要变成修改的节点了。
发现其实好像可以搞
修改一条链的父亲的操作是O(logn)的，但是频繁修改父亲可能导致树剖退化
这个我们先不提
具体搞法呢？
开n+1个点，最后一个点是弹飞的点
然后每个节点指向的节点向这个节点连边，跑一遍树剖。
每次询问输出深度
修改的话，在每个点开一个set存它的儿子集合
修改就挺简单了。
*/ 
