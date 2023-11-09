#include<bits/stdc++.h>
using namespace std;

#define TASK "haminton_flight"

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
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ; 

int n , m ;
vector<int>g[maxN] ; 
ll f[maxN+2][1<<maxN];
vector<int>G[1<<maxN];
void doc()
{
    cin>> n >> m;  
    FOR(i,1,m)
    {
    	int u ,v ; 
    	cin>>u>>v; 
    	--u ; 
    	--v ;
    	g[u].pb(v); 
    }
    FOR(bit,1,(1<<n)-1)
    {
        FOR(i,0,n-1)
        {
            if(bit>>i&1)
            {
                G[bit].pb(i); 
            }
        }
    }
}
void xuly()
{
    f[0][1<<0] = 1;
    FOR(bit,1,(1<<n)-1)
    {
    	for(auto i:G[bit])
    	{
    		if(bit>>i&1)
    		{
    			for(auto j:g[i])
    			{ 
    				if(bit>>j&1)continue ;
    				// cout<<bitset<4>(bit)<<endl;
    				f[j][bit^(1<<j)]+=f[i][bit]; 
    				f[j][bit^(1<<j)]%=sm;
    				// cout<<bitset<4>(bit|(1<<j))<<" "<<f[j][bit|(1<<j)]<<endl;
    			}
    		}
    	}
    }
    cout<<f[n-1][(1<<n)-1];
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}