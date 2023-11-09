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

void inp()
{
    cin>> n >> q; 
    for(int i= 1;i<=n;i++)
    {
        cin>>a[i] ; 
    }
    for(int i =1 ;i<=n;i++)
    {
        cin>>b[i] ; 
        v[b[i]].pb(i);  
    }
    for(int i= 1;i<=n;i++)
    {
        for(int j= 0;j<v[i].size();j++)
        {
            int u=
        }
    }
    while(q--)
    {
        int l  , r ,x ; 
        cin>>l>>r>>x; 
        up(1,1,n,l,r,x) ; 
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