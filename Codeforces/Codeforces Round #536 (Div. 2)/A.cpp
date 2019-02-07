#include <bits/stdc++.h>
using namespace std;
const int N=509;
int read(){
	char c='1';
	while(c!='.'&&c!='X')c=getchar();
	return c=='X';
}
int n,g[N][N],cnt;
int check(int x,int y){
	if(x<=0||y<=0)return 0;
	if(x+2>n||y+2>n)return 0;
	if(g[x][y]&&g[x][y+2]&&g[x+1][y+1]&&g[x+2][y]&&g[x+2][y+2])return 1;
	return 0;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			g[i][j]=read();
	for(int i=1;i<n-1;i++)
		for(int j=1;j<n-1;j++)
			cnt+=check(i,j);
	cout<<cnt<<endl;
	return 0;
}



