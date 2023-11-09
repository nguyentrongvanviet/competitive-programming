// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "p9queue"

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
const int B = 331; 
const int N =2e5+3,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  
struct DL
{
    int h , pos ; 
}; 
int n , m , k; 
int a[N]; 
DL block[B+10][B+10];
int dd[N]; 
int sl[B+5] ;
int s[B+5];
void doc()
{
    cin>>n>> k; 
    FOR(i,0,n-1)
    {
        cin>>a[i] ;
    }
}
DL get()
{
    FOR(i,1,m)s[i]=s[i-1]+sl[i]; 
    DL ans={0,0} ;
    FOR(i,1,m)
    {
        int d= s[i-1]; 
        int nk = (k-d%k)%k;
        if(block[i][nk].h>ans.h&&nk<sl[i])
        {
            ans= block[i][nk]; 
        }
    }
    return ans;  
}
void update(int pos)
{
    sl[pos/B+1]--;
    FOR(i,1,m)s[i] =s[i-1]+sl[i];
    dd[pos] = 1;    
    int u =0 ;
    FOR(j,0,min(k-1,sl[pos/B+1]-1))block[pos/B+1][j]={0,0};
    FOR(i,(pos/B+1-1)*B,min(n-1,(pos/B+1-1)*B+B-1))
    {
        if(dd[i]==0)
        {
            if(dd[block[pos/B+1][u].pos]||block[pos/B+1][u].h<a[i])block[pos/B+1][u]={a[i],i};
            ++u ; 
            u%=k;
        }
    }
}
void xuly()
{
    m= 0 ;  
    int t = 0 ; 
    FOR(i,0,n-1)
    {
        if(i%B==0)++m,t=0 ;  
        sl[m]++;
        if(a[i]>block[m][t].h)
        {
            block[m][t] = {a[i],i}; 
        }
        ++t;
        t%=k;
    }
    FOR(i,0,n-1)
    {
        auto ans = get() ;
        int pos =ans.pos ; 
        cout<<ans.h<<" ";
        update(pos);
    }
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}