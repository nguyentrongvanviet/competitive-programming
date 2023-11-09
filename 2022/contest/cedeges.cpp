#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
const ll N = 2e5+5 ,inf = 1e9  , INF =1e17  , cs = 330    ,mod = 1e9+7 ;

int n  , m ;

struct bg 
{
	
};
struct cmp
{

}
void dij()
{
	priority_queue<bg,vector<bg>,cmp> q ; 	
} 
void inp()
{
	cin>>n>>m ; 
	for(int i =1 ;i<=m;i++)
	{
		int u  ,v,c, w;  
		cin>>u>>v>>c>>w; 
		g[u].pb({v,c,w}) ; 
		g[v].pb({u,c,w}) ; 
	}
	dij();
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin) ;
    freopen("o.txt","w",stdout) ;
    inp();
}
