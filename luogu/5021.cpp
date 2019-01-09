// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define mid ((l+r)>>1)
using namespace std;
const int N=5e5+1009;
int read(){
    char c;int num,f=1;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return f*num;
}
int n,m,fa[N],val[N],cnt;
int head[N],ver[N*2],nxt[N*2],edge[N*2],tot=1;
int dfs(int x,int v){
    multiset<int>S;
    multiset<int>::iterator it;
    S.clear();
    for(int i=head[x];i;i=nxt[i]){
        if(ver[i]==fa[x])continue;
        int val=dfs(ver[i],v)+edge[i];
        if(val>=v)cnt++;
        else S.insert(val);
    }
    int maxn=0;
    while(!S.empty()){
        if(S.size()==1)return max(maxn,*S.begin());
        it=S.lower_bound(v-*S.begin());
        if(it==S.begin()&&S.count(*it)==1)it++;
        if(it==S.end()){
            maxn=max(maxn,*S.begin());
            S.erase(S.find(*S.begin()));
        }else {
            cnt++;
            S.erase(S.find(*it));
            S.erase(S.find(*S.begin()));
        }
    }
    return maxn;
}
bool check(int x){
    cnt=0;dfs(1,x);
    if(cnt>=m)return 1;
    else return 0;
}
void build(int x,int pre){
    for(int i=head[x];i;i=nxt[i]){
        if(ver[i]==pre)continue;
        fa[ver[i]]=x;
        build(ver[i],x);
    }
}
void add(int u,int v,int w){
    ver[++tot]=u;nxt[tot]=head[v];head[v]=tot;edge[tot]=w;
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;edge[tot]=w;
}
int main()
{
    int l=0,r=0;
    n=read();m=read();
    for(int i=1;i<n;i++){
        int u,v,w;
        u=read();v=read();w=read();
        add(u,v,w);r+=w;
    }
    build(1,0);
    while(l<=r){
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",r);
    return 0;
}
/*
考虑二分
考虑经过一个点的贡献
由于上行边只有一条，我们只能选择一条边向上传递
其他的子节点互相匹配
显然上传的边越大越好
对于一个点的下行边
分为两种
直接大于二分值，选取就好了
如果小于二分值，我们可以对这些排序之后，双指针求出方案
发现这样是很慢的啊。。
这样就是O(n^2logn)了
好像可以multiset优化
对于一个点，我们把他所有的下行点（<x）丢进multiset
每次从multiset中取出一个最小的点，判断能否找到一个
大于等于x-val的点，有的话方案数+1
如果没有的话取出留作上行用
*/

