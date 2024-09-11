#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+5 ;   
int n , m ,  k ; 
// vector<vector<int>>s ; 
int w ; 
int a[N] ; 

signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ; 
    }
    int test ; cin>>test ;
    while(test--)
    {
        cin >> n >> m >> k ;
        // s.resize(n+2,vector<int>(m+2,0)) ; 
        vector<vector<int>>s(n+2,vector<int>(m+2,0)) ; 
        for(int i=1;i<=n-k+1;i++)for(int j=1;j<=m-k+1;j++)
        {
            s[i][j]++ ; 
            s[i+k][j+k]++ ; 
            s[i+k][j]-- ;
            s[i][j+k]--; 
        } 
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        vector<int>consist;  
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        {
            consist.push_back(s[i][j]) ; 
        }
        sort(consist.begin(),consist.end(),greater<int>()) ; 
        cin>>w ; 
        for(int i=1;i<=w;i++)cin>>a[i] ; 
        sort(a+1,a+w+1,greater<int>()) ; 
        long long res = 0 ; 
        for(int i=1;i<=w;i++)
        {
            res+=1ll*a[i]*consist[i-1] ; 
        } 
        cout<<res<<'\n' ; 
    }
    cerr<<"OK"<<'\n';
}