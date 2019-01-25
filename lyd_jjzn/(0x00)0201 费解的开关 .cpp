#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define Mid ((l+r)<<1)
using namespace std;
int read(){char c;while(c=getchar(),!isdigit(c));return c-'0';}
int f[19][19],tmp[19][19];
void modi(int x,int y){
	if(x-1>=0)tmp[x-1][y]^=1;
	if(y-1>=0)tmp[x][y-1]^=1;
	if(x+1<5)tmp[x+1][y]^=1;
	if(y+1<5)tmp[x][y+1]^=1;
	tmp[x][y]^=1;
}
void work(){
	int ans=7;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			f[i][j]=read();
	for(int i=0;i<1<<5;i++){
		int now=0;
		for(int j=0;j<5;j++)
			for(int k=0;k<5;k++)
				tmp[j][k]=f[j][k];
		for(int j=0;j<5;j++)
			if(i&(1<<j))
				modi(0,j),now++;
		/*if(i==1){
			cout<<now<<endl;
			for(int j=0;j<5;j++){
				for(int k=0;k<5;k++)
					cout<<tmp[j][k];
				cout<<endl;
			}
		}*/
		for(int j=1;j<5;j++)
			for(int k=0;k<5;k++)
				if(!tmp[j-1][k]){
					//if(i==1)cout<<j<<" "<<k<<endl;
					modi(j,k),now++;
				}
		int flag=0;
		for(int k=0;k<5;k++)
			if(!tmp[4][k])
				flag=1;
		if(flag)continue;
		ans=min(ans,now);
		//cout<<now<<endl;
	}
	printf("%d\n",(ans==7)?-1:ans);
}
int main()
{
	int Case;
	cin>>Case;
	while(Case--)work();
	return 0;
}

/*
30分做法： 
暴力枚举状态其实就可以拿到30分了。
100分做法：
n为500时，有500组数据，每组数据大概6层，大约是500*25^6=122 070 312 500
不太可以。。。
首先观察性质
因为所有的开关互相独立，所以每个开关只有操作或者不操作两种选择
同时我们发现一个位置的选取只会影响到上下两层的状态
也就是说我们枚举完四层，中间那层其实是确定了的
这样子就减少到了500*20^6=3.2e10。。
进一步
如果我们从中间开始枚举中间的三层
两边的也是可以确定的
状态数为500*15^6=5.6e9。。
…… 
再进一步发现一个巨大的结论！！！
加上上面全部都已经确定了，那我们枚举下一排的时候肯定也是固定的。
因为我们只能把上一排的0变成1,上一排是1的时候我们是不能操作的。。
然后我们只要枚举500*2^5就可以了，超级快。
这个N甚至可以达到1e5。。 
*/
