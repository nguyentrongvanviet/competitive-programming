#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define int long long 
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e6+5 ,  oo = 1e9 ;
const ll sm =  111539786,cs=330 ,inf = 1e17;

struct bg
{
    int u ;  
    int t;  
};
struct pt
{
    int pos ; 
    int val ; 
};
int n ; 
int res= 0 ;
bg a[N] ;   
pt dd[N] ;  
int s[N] ;
int tonum(string tmp)
{
    int ans = 0 ; 
    for(int i= 0 ;i<tmp.size();i++)
    {
        ans = (ans*10%sm+(tmp[i]-'0'))%sm; 
    }
    return ans;  
}
void submat3tienggiai()
{
    string s1; 
    cin>>s1; 
    string tmp;  
    int u =s1[0]-'a';
    int t= 0 ;   
    for(int i = 1;i<s1.size();i++)
    {
        if('a'<=s1[i]&&s1[i]<='z')
        {
            a[++t]={u,tonum(tmp)};  
            tmp="";
            u=s1[i]-'a'; 
        }
        else
        {
            tmp=tmp+s1[i];
        }
    }
    a[++t]={u,tonum(tmp)};
    for(int i= 1 ;i<=t;i++)
    {
        s[i] = 0 ; 
    }
    for(int i= 0;i<='z'-'a';i++)dd[i].pos=0,dd[i].val=0; 
    for(int i=1;i<=t;i++)
    {
        int su = 0 ; 
        int u = a[i].u; 
        int val = a[i].t; 
        if(dd[u].pos==0)
        {
            su=1+s[i-1];     
            s[i]=(s[i-1]+(su*val)%sm)%sm;
            dd[u].pos=i; 
            dd[u].val=su%sm;
        }
        else
        {
            su=(s[i-1]-s[dd[u].pos]+dd[u].val+sm)%sm;
            s[i]=(s[i-1]+(su*val)%sm)%sm; 
            dd[u].pos=i;
            dd[u].val=su%sm;  
        } 
    }
    cout<<s[t]<<"\n";
}
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int test; 
    cin>>test;  
    while(test--)submat3tienggiai();  
    return 0;
}