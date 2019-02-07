#include <bits/stdc++.h>
using namespace std;
const int Base=10000000;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
string s;
int n,ans,b[20000009];
int main()
{
	n=read();
	for(int i=1;i<=n;i++){
		cin>>s;
		int r=0,l=0,len=s.size(),tmp;
		for(int j=0;j<len;j++){
			if(s[j]==')'){
				if(l==0)r++;
				else l--;
			}else l++;
		}
		if(l>0&&r>0)continue;
		else tmp=l-r;
		if(b[-tmp+Base]){
			b[-tmp+Base]--;
			ans++;
		}else {
			b[tmp+Base]++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
 
/*
题意 ：给定n个括号序列
每次选择两个组合，要求组合的对数最多
每队都是合法序列。
首先发现两对能组合必须是单边序列，
也就是左右括号抵销之后，剩下的都是朝左或者朝右的
朝左为正朝右为负，丢进桶里暴力查找就可以了
难点在统计
一个左括号只能抵消出现在它左边的右括号
反之亦然
我们是从左往右统计的
一开始出现的右括号肯定没办法抵消，加入溢出的数中 
然后出现的左括号我们记录下来，左边如果出现右括号就抵消掉
如果抵消不掉就加入溢出的数中。
最后再看看有没有左（右）括号剩余，都有的话直接跳过。 
有其中一个的话记录正负就ok了。 
*/ 

