#include <bits/stdc++.h>
using namespace std;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return f*num;
}
string s,b;
int main()
{
	cin>>s;
	while(cin>>b){
		if(s[0]==b[0]||s[1]==b[1]){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}



