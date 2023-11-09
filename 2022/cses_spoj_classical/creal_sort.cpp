#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
#define int long long 
const int N =2e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ;
int a[N] ;  
int sl[N] ;    
vector<int>q; 
void inp()
{
    cin>> n;  
    for(int i =1 ;i<=n;i++)
    {
        cin>>a[i] ; 
        sl[a[i]]++ ; 
        if(sl[a[i]]==1)
        {
            q.pb(a[i]) ; 
        }
    }
    sort(q.begin(),q.end()) ; 
    int res=0; 
    int t=  n ; 
    for(auto v : q) 
    {
        res+=t; 
        t-=sl[v]; 
    }
    cout<<res;
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}