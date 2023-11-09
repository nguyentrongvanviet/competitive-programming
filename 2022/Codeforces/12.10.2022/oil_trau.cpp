// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "oil"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
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
        freopen(TASK".ANS","w",stdout); 
    }
}

const int N =4e3+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ; 
ll s;  
ll a[N] ; 
ll f[N][N] ;
void doc()
{
    cin>>n>> s; 
    FOR(i,1,n)cin>>a[i]; 
    FOR(i,0,n+1)
    {
    	FOR(j,0,n+1)    	
    	{
    		f[i][j] = -inf ; 
    	}	
    }
    f[0][0] = 0 ;
    FOR(i,1,n)
    {
    	FOR(j,1,i)
    	{
    		f[i][j] = max({f[i-1][j]-j*s,f[i-1][j+1]+a[i]-j*s,f[i-1][j-1]-a[i]-j*s});  
    	}
    	f[i][0] = max(f[i-1][1]+a[i],f[i-1][0]);
    } 	
    cout<<f[n][0]<<'\n';
}
struct cmp
{
    bool operator() (int a, int b)
    {
        return a<b ;
    }
};
void xuly()
{
    FOR(i,1,n)
    {
    	a[i] -=i*s; 
    }
    // FOR(i,1,n)cout<<a[i]<<" ";
    priority_queue<int,vi,cmp>q ;
    q.push(a[n]) ;
    ll res=0 ; 
    FORD(i,n-1,1)
    {
        if(q.top()>a[i])
        {
            res+=q.top()-a[i];
            q.pop();
            q.push(a[i]);
        } 
        else 
        {
            q.push(a[i]) ;
        }
    }
    cout<<res;
}
int main()		
{
    IOS();  
    doc(); 
    // xuly();
}