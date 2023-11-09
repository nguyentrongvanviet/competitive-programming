/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
code is just not for fun , it is for you too 
so if you have seen this please take it as a simple love I give to you so please take it as a message from my heart
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "TOUR"

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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n , m; 
int a[N ]; 
vi g[N] ; 
bool dd[N] ;
void doc()
{
 	cin>>n >> m; 
 	FOR(i,1,n)cin>>a[i] ; 
 	FOR(i,1,m)
 	{
 		int u ,v ; 
 		cin>>u>>v ; 
 		g[u].pb(v) ; 
 		g[v].pb(u) ;   
 	}   
}
bool ok ; 
void dfs(int u , int ans  )
{
	if(u==n)ok= 1; 
	dd[u] = 1 ;
	for(auto v: g[u])
	{
		if(dd[v])continue ;
		if(abs(a[u]-a[v])<=ans)
		{
			dfs(v,ans) ;
		}	
	} 
}
void xuly()
{
	int l =0 ; 
	int r= oo ;
	int ans= 0 ; 
	while(l<=r)
	{
		int mid = (l+r)>>1;
		FOR(i,1,n)dd[i] = 0 ;
		ok = 0 ; 
		dfs(1,mid) ;
		if(ok)
		{
			ans=mid  ; 
			r=mid-1 ; 
		}
		else
		{
			l=mid+1; 
		}
	}    
	cout<<ans ;
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}