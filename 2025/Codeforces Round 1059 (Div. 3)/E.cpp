#include<bits/stdc++.h>
using namespace std; 


signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; 
    if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ;
        freopen("text.OUT","w",stdout) ; 
    }
    int t  ; cin >>t ; 
    while(t--)
    {
        int n , k; cin>> n >> k; 
        vector<int> a(n+1);
        vector<int>dd(n+1,0) ;
        vector<int>val;  
        for(int i=1;i<=n;i++)
        {
            cin>>a[i] ; 
        }
        for(int i=n;i>=1;i--)
        {
            if(dd[a[i]]==0)dd[a[i]] = 1 , val.push_back(a[i]) ; 
        }
        reverse(val.begin(),val.end()) ;
        for(int i=1;k&&i<=n;i++)
        {
            if(dd[i]==0)
            {
                --k ; 
                val.push_back(i) ;
                cout<<i<<' '; 
            }
        }
        for(int i=1;i<=k;i++)
        {
            cout<<val[i-1]<<' ' ; 
        }
        cout<<'\n' ; 
    }
}