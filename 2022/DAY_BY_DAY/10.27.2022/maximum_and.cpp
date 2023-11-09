// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "maximum_and"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define vi vector<int> 
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
void IOS()
{
    fast 
    srand(time(0)) ;
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ; 
int a[N] ; 
int b[N]; 
void doc()
{
    cin>>n ; 
    FOR(i,1,n)cin>>a[i] ; 
    FOR(i,1,n)cin>>b[i] ; 
    int ans=0 ; 

}
bool check(int val)
{
    map<int,int>sl;  
    FOR(i,1,n)
    {
        sl[a[i]&val]++; 
    }
    FOR(i,1,n)
    {
        sl[~b[i]&val]--;
    }
    for(auto it : sl)
    {
        if(it.second !=0)return 0 ;
    }
    return 1 ; 
}   
void xuly()
{
    int ans= 0 ;
    FORD(i,29,0)
    {
        if(check(ans|(1<<i)))
        {
            ans|=(1<<i) ;
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    IOS(); 
    int test ;cin>>test ; 
    while(test--)
    {
        doc(); 
        xuly();        
    } 

}