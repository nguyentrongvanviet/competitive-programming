// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "ROBOT6"

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

struct DL
{
    int x, y; 
    bool operator<(const DL&a)const
    {
        return x<a.x||(x==a.x&&y<a.y) ;
    }
};
int n ; 
int f[N] ; 
DL a[N] ; 
void doc()
{   
    cin>> n; 
    FOR(i,1,n)cin>>a[i].x>>a[i].y ;   
    sort(a+1,a+n+1);
    FOR(i,1,n)
    {
        f[i] =1 ; 
        FOR(j,1,i-1)
        {
            if(a[j].y<a[i].y)
            {
                f[i]=max(f[i],f[j]+1); 
            }   
        }
    }      
    int ans= 0; 
    FOR(i,1,n)ans=max(ans,f[i]) ;
    cout<<ans;
}
void xuly()
{
    
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}