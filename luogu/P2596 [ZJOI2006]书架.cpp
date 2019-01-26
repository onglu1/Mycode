#include <bits/stdc++.h>
#define fa(x) tree[x].fa
#define siz(x) tree[x].siz
#define son(x,k) tree[x].ch[k]
#define val(x) tree[x].val
#define Mid ((l+r)>>1)
using namespace std;
const int N=5e6+10009;
const int inf=(1<<31)-1;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
struct Node{
	int fa,siz,ch[2],val;
}tree[N];
int n,m,a[N],b[N],rt=1;
void update(int x){siz(x)=siz(son(x,0))+siz(son(x,1));}
void build(int l,int r,int xx){
	if(l>r)return ;
	//cout<<l<<" "<<r<<endl;
	if(l==r){
		if(l==1||l==n+2)val(xx)=((l==1)?(-1):1)*inf;
		else val(xx)=l-1;siz(xx)=1;
		son(xx,0)=son(xx,1)=0;
		return ;
	}
	if(Mid==1||Mid==n+2)val(xx)=((Mid==1)?(-1):1)*inf;
	else val(xx)=Mid-1;
	if(l<=Mid-1){
		son(xx,0)=xx<<1;fa(xx<<1)=xx;
		build(l,Mid-1,xx<<1);
	}
	if(Mid+1<=r){
		son(xx,1)=xx<<1|1;fa(xx<<1|1)=xx;
		build(Mid+1,r,xx<<1|1);
	}
	update(xx);
}
int fid(int x){
	int l=1,r=n;
	while(l<=r){
		if(b[Mid]==x)return Mid;
		if(b[Mid]>x)r=Mid-1;
		else l=Mid+1;
	}
	return -1;
}
void print(int x){
	if(son(x,0))print(x<<1);
	printf("%d ",val(x));
	if(son(x,1))print(x<<1|1);
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=b[i]=read();
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)
		a[fid(a[i])]=i+1;
	//离散化数组
	//值为x的数的离散化结果为fid(x) 
	//对应的位置为a[fid(x)] 
	build(1,n+2,1);
	//print(rt);
	for(int i=1;i<=m;i++){
		char qwq[109];
		int x,y;
		scanf("%s",qwq);
		if(qwq[0]='T'){
			x=read();
			Delete(a[fid(x)]);
			//删除排名为 a[fid(x)]的节点
			 
		}
	}
	return 0;
}

/*维护一个序列支持下面的操作
1.把序列中值为S的数移到第一个位置
2.把序列中值为S的数移到最后一个位置
3.把序列中值为S的数左右移动一个位置或者不移动
4.查询序列中值为S的数位于第几个位置
5.查询序列中第x个位置的数的值

这东西怎么用平衡树搞啊。。。
如果我们按中序维护序列排名
那么我们查找值为S的数就十分困难
但是我们可以建立一个值对应排名的映射。。
所以我们可以离散化一下编号，然后两遍映射到排名上去。。
然后查找序列中值为S的数时候就找到这个数的位置，然后去修改就好了
注意修改位置的时候要在映射的位置也修改了。 
啊还有记得离散化。。因为没有给每个数的范围 

然后发现这种思路是不行的。。崩了
因为更新排名是要整体更新的
也就是说如果一个数x改成1，那么所有位于x之前的数都要加一。
这种操作是O(n)的 
只能用平衡树维护排名了。。
开一个排名树一个编号树
编号数中每个值在树中的排名就是它在排名树中的位置
每次移动我们先在编号树中找到这个编号的排名
然后依据排名在排名树中对相应的节点进行移动
移动完之后回到编号树中进行修改。。。
哭辽。。 
*/
 
