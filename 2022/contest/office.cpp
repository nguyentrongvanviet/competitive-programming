#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
const ll N = 2e5+5 ,inf = 1e9  , INF =1e17  , cs = 330    ,mod = 1e9+7 ;

void inp()
{
	cin>> n>>k ;
	for(int i= 1 ;i<=n-1;i++)
	{
		int u , v ; 
		g[u].pb(v) ; 
		g[v].pb(u) ;
	}
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin) ;
    freopen("o.txt","w",stdout) ;
    inp();
}
