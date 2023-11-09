#include<bits/stdc++.h>
using namespace std;

#define TASK "milktea"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".ANS","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n , m , p ; 
int a[N] ; 
int b[N] ; 
int res=oo ;
void doc()
{
    res=oo;
	cin>>n>>m>>p ;  
    FOR(i,1,n)
    {
        a[i] = 0;
        FOR(j,0,p-1)
        {
            char x;
            cin>>x ; 
            if(x=='1')a[i]|=(1<<j);
        }
    }
    FOR(i,1,m)
    {
        b[i] =0 ; 
        FOR(j,0,p-1)
        {
            char x; 
            cin>>x;
            if(x=='1')
            {
                b[i]|=(1<<j);
            }
        }
    }
    FOR(tt,0,(1<<p)-1)
    {
        bool ok = 1;
        FOR(i,1,m)
        {
            if(b[i]==tt)ok=0; 
        }
        if(ok==0)continue ;
        int ans =0  ; 
        FOR(i,1,n)  
        {   
            ans+=__builtin_popcount(tt^a[i]);
        }
        res=min(res,ans);
    }
    cout<<res<<"\n";
}
void xuly()
{
    
}
int main()
{
    IOS();  
    int test ;
    cin>>test;
    while(test--)
    {
        doc(); 
        xuly();
    }
    
}