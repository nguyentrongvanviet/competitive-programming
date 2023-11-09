#include<bits/stdc++.h>
using namespace std;

#define TASK "REWARD"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =2e6+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n ; 
ll a[N] ;
ll f[N];
ll sl[N];
ll ma[N] ;
void doc()
{	
    cin>> n; 
    for(int i= 1;i<=N;i++)
    {
    	sl[i] = 0 ;
    }
    for(int i= 1;i<=n;i++)
    {
    	cin>>a[i] ; 
    	sl[a[i]]++ ; 
    }
    ma[1] =sl[1] ;
    f[1] =sl[1] ;  
    for(ll i= 2;i<N;i++)
    {
    	f[i] =sl[i]*i+ma[i-2];
    	ma[i] =max(ma[i-1],f[i]) ;
    }	
    cout<<ma[N-1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}