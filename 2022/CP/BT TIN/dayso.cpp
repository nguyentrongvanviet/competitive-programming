#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
string f[N] ; 
void solve(int id , string s)
{       
    string ans="";
    int nho = 0 ;  
    for(int i= s.size()-1 ;i>=0;i--)
    {
        int u  = s[i]-'0'+s[i]-'0'+nho ; 
        if(u>9)
        {
            u-=10;
            nho=1 ; 
        }
        else 
        {
            nho= 0 ; 
        }
        // cout<<u<<endl;
        ans=char(u+'0')+ans;
    }
    // if(s=="8")cout<<ans<<"A"<<endl;
    // cout<<ans<<" "<<"A"<<endl;
    if(nho==1)
    {
        ans='1'+ans; 
    }
    int u  ;
    sort(ans.begin(),ans.end()) ; 
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]!='0')
        {
            u = i ; 
            break ; 
        }
    }
    // cout<<u<<endl;
    for(int i =u;i<ans.size();i++)
    {
        f[id]=f[id]+ans[i];
    }
}
void inp()
{
    cin>> n ; 
    f[1] ="1" ; 
    for(int i= 2 ;i<=60;i++)
    {
        solve(i,f[i-1]) ; 
    }    
    if(n<=60)
    {
        cout<<f[n]; 
    }
    else 
    {
        cout<<f[26+(n-26)%6];
    }
    // cout<<f[2]<<endl;
    // cout<<f[n];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}