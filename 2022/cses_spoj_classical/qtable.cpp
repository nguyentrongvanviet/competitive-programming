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

int n , m ;  

void inp()
{
    cin>> n>> m; 
    vector<vector<int>>a(n+1,vector<int>(m+1,0)) ;
    vector<vector<int>>f(n+1,vector<int>(m+1,0)); 
    for(int i= 1 ;i<=n;++i)
    {
        for(int j= 1;j<=m;j++)
        {
            cin>>a[i][j] ; 
        }
    }
    for(int i =1;i<=m;i++)
    {
        f[n][i] = n ;  
    }
    for(int i = n-1;i>=1;i--)
    {
        for(int j =1 ;j<=m;j++)
        {
            if(a[i][j]<=a[i+1][j])f[i][j] =f[i+1][j]; 
            else f[i][j]= i ; 
        }
    }
    vector<int>ma(n+1,0); 
    for(int i= 1;i<=n;i++)
    {
        for(int j= 1 ;j<=m;j++)
        {
            ma[i]=max(ma[i],f[i][j]) ; 
        }
    }
    int q; 
    cin>>q; 
    while(q--)
    {
        int l  ,r ; 
        cin>>l>>r ; 
        if(ma[l]>=r)
        {
            cout<<"Yes"<<"\n"; 
        }
        else 
        {
            cout<<"No"<<"\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}