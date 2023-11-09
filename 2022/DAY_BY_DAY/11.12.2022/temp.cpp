#include<bits/stdc++.h>
using namespace std;

#define TASK "dora"
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

ll a; 
void doc()
{
    cin>>a;
    for(ll i=0;i<=1e7;i++)
    {
        if(i*i-a>=0)
        {
            ll u = sqrt(i*i-a);
            if(u*u==i*i-a)
            {
                cout<<i ; 
                return ; 
            }
            // cout<<i*i-a<<" "<<(ll)sqrt(i*i-a)<<" "<<sqrt(i*i-a)*sqrt(i*i-a)<<" "<<a;
        }
    }   
    cout<<"none"; 
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen("TEMP.OUT","w",stdout); 
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