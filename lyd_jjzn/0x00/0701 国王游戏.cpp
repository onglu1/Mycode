#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    long long num,l,r;
}p[10009];
long long n,a,b;
string sum,ans="0";
bool cmp(node a,node b){
    return a.l*a.r<b.l*b.r;
}
string maxn(string s1,string s2){
    int l1=s1.size(),l2=s2.size();
    if(l1>l2)return s1;
    if(l1<l2)return s2;
    for(int i=0;i<l1;i++){
        if(s1[i]>s2[i])return s1;
        if(s1[i]<s2[i])return s2;
    }
    return s1;
}
string multi(string a,int b)
{
    int na[100005],L=100005;
    string ans;
    int La=a.size();
    fill(na,na+L,0);
    for(int i=La-1;i>=0;i--) na[La-i-1]=a[i]-'0';
    int w=0;
    for(int i=0;i<La;i++) na[i]=na[i]*b+w,w=na[i]/10,na[i]=na[i]%10;
    while(w) na[La++]=w%10,w/=10;
    La--;
    while(La>=0) ans+=na[La--]+'0';
    return ans;
}
string div(string a,ll b){
    string r,ans;
    ll d=0;
    if(a=="0")return a;
    for(int i=0;i<a.size();i++){
        r+=(d*10+a[i]-'0')/b+'0';
        d=(d*10+(a[i]-'0'))%b;
    }
    ll p=0;
    for(int i=0;i<r.size();i++)
    if(r[i]!='0') {p=i;break;}
    return r.substr(p);
}
int main()
{
    //cout<<multi("128715856378430924839",12548)<<endl;
    cin>>n>>a>>b;
    while(a){
        sum=char(a%10+'0')+sum;
        a/=10;
    }
    //cout<<sum<<endl;
    for(int i=1;i<=n;i++){
        p[i].num=i;
        cin>>p[i].l>>p[i].r;
    }
    sort(p+1,p+1+n,cmp);
    for(int i=1;i<=n;i++){
        ans=maxn(ans,div(sum,p[i].r));
        sum=multi(sum,p[i].l);
    }
    //cout<<sum<<endl;
    cout<<ans<<endl;
    return 0;
}


