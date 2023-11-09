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
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =1e6+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct DL
{
    int l  , r ; 
}; 
ll a[N] ; 
struct cmp
{
    bool operator()(DL x , DL y)
    {
        return a[x.r]>a[y.r]; 
    }
};
int n ; 
ll s;  
void doc()
{
    cin>>n>> s; 
    FOR(i,1,n)cin>>a[i];
}
int dd[N] ;
void xuly()
{
    FOR(i,1,n)
    {
    	a[i] -=i*s; 
    }
    priority_queue<DL,vector<DL>,cmp>q ;
    q.push({0,1}); 
    ll res= 0 ;
    FOR(i,2,n)
    {
        int x= q.top().l ; 
        int y= q.top().r ; 
        if(a[y]<a[i])
        {
            res+=a[i]-a[y] ;
            if(x==0)
            {
                q.pop() ; 
                q.push({y,i}) ; 
            } 
            else
            {
                q.pop() ; 
                q.push({x,i});
                q.push({0,y}); 
            }
        }
        else q.push({0,i}); 
    }
    cout<<res;
}
int main()		
{
    IOS();  
    doc(); 
    xuly();
}