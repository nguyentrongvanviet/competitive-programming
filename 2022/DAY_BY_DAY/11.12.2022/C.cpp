#include<bits/stdc++.h>
using namespace std;

#define TASK "C"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#pragma CPP target("popcnt")
const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n ; 
ll a[N] ; 
void doc()
{   
    cin>> n; 
    FOR(i,1,n)cin>>a[i] ; 
    map<ll,ll>freq;
    bool appear0 = 0 ;   
    ll res=0 ;  
    ll s= 0 ; 
    ll mafreq = 0 ;
    FOR(i,1,n)
    {
        if(a[i]==0)
        {   
            if(appear0==0)
            {
                res+=freq[0] ;  
            }
            else 
            {
                res+=mafreq; 
            }
            appear0  = 1; 
            mafreq = 0 ; 
            freq.clear();
        }
        s+=a[i] ; 
        freq[s]++;
        mafreq = max(mafreq,freq[s]);
    }
    if(appear0)
    {
        res+=mafreq ; 
    }
    else 
    {
        res+=freq[0];
    }
    cout<<res<<"\n";
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}