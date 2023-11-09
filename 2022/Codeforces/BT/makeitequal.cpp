#define TASK "text"
#include<bits/stdc++.h>
using namespace std;

const bool multitest = true;

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));
#pragma GCC target("popcnt")
#define ll long long 
#define db long double  
#define pii pair<int,int>
#define vi vector<int>
#define ve vector 
#define str string 
#define pll pair<ll,ll>
#define fi first 
#define se second

#define pb push_back
#define pk pop_back
#define all(a) a.begin(),a.end() 
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++) 
#define btpc(x) __builtin_popcount(x)   

#define print(a) for(auto  v: a )cout<<v<<" ";

ll sq(ll a ){return a*a;}
ll gcd(ll a, ll b )  {return b==0 ? a:gcd(b,a%b);}
ll lcm(ll a , ll b ){ return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(TASK".INP","r")){
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout); 
    }
}
const int N =2e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

void doc()
{
    int n , m;  
    ve<tuple<int,int,int>>res; 
    vi thua , thieu ; 
    cin>> n >> m ;
    int tot =0 ; 
    ve<int>s(n+1,0);
    ve<ve<int>>a(n+1,ve<int>(m+1,0));
    FOR(i,1,n)FOR(j,1,m)cin>>a[i][j],tot+=a[i][j],s[i]+=a[i][j];
    if(tot%n!=0)
    {
        cout<<-1<<'\n';
        return ;
    }
    tot/=n ; 
    FOR(j,1,m)
    {   
        thua.clear() ; 
        thieu.clear() ;
        FOR(i,1,n)
        {
            if(a[i][j]==1)
            {
                if(s[i]>tot)
                {
                    thua.pb(i) ;
                }
            }
            else
            {
                if(s[i]<tot) 
                {
                    thieu.pb(i);
                }
            }
        }
        FORN(i,0,min(thieu.size(),thua.size()))
        {
            s[thieu[i]]++ ; 
            s[thua[i]]--;
            res.pb({j,thieu[i],thua[i]});
        }
    }
    cout<<res.size()<<'\n';
    for(auto v :res) cout<<get<1>(v)<<" "<<get<2>(v)<<" "<<get<0>(v)<<'\n';
}
void xuly()
{
    
}
signed main()
{
    IOS();
    int test= 1;
    if(multitest)cin>>test; 
    while(test--)
    {
        doc() ;  
        xuly() ;  
    }
}
