#include<bits/stdc++.h>
using namespace std;

#define TASK "picture"

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

const int N =1e3+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n  ,m ; 
int pa[N*N] ; 
int sz[N*N] ; 
int id[N][N] ; 
int a[N][N] ;
int xx[] = {1,-1,0,0};
int yy[] ={0,0,1,-1}; 
int ans= 0 ;
int in(int x , int y)
{
	return 1<=x&&x<=n&&1<=y&&y<=m;
} 
int tt= 0 ;   
int goc(int u)
{
	return pa[u]==u ? u : pa[u] = goc(pa[u]) ; 
} 
void hop(int u , int v )
{
	int chau = goc(u) ; 
	int chav = goc(v) ; 
	if(chau==chav)return ; 
	pa[chau] =chav; 
	sz[chav]+=sz[chau]; 
	ans =max(ans,sz[chav]);
}
void doc()
{
    cin>>n >> m  ;
    FOR(i,1,n)
    {
    	FOR(j,1,m)
    	{
    		char x; cin>>x ; 
    		a[i][j] = (x-'0');
    		id[i][j]=++tt;
    		pa[tt] =tt;  
    		sz[tt] = 1; 
    	}
    }
    FOR(i,1,n)
    {
    	FOR(j,1,m)
    	{
    		if(a[i][j]==0)continue;
    		if(i==1&&j==1)continue ; 
    		if(i!=1)
    		{
    			if(a[i-1][j]==1)
    			{
    				hop(id[i-1][j],id[i][j]);
    			}
    		}
    		if(j!=1)
    		{
    			if(a[i][j-1]==1)
    			{
    				hop(id[i][j-1],id[i][j]);
    			}
    		}
    	}
    }
    int q ; 
    cin>>q; 
    FOR(t,1,q)
    {
    	int i , j  ; 
    	cin>>i>>j;
    	if(a[i][j]==1)
    	{
    		cout<<ans<<"\n";
    		continue ; 
    	}
    	a[i][j]=1;
    	FOR(ii,0,3)
    	{
    		int nu= i+xx[ii] ; 
    		int nv= j+yy[ii];
    		if(in(nu,nv)&&a[nu][nv]==1)
    		{
    			hop(id[nu][nv],id[i][j]);
    		}
    	}
		cout<<ans<<"\n";
    }
}

int main()
{
    fast 
    if(fopen(TASK".inp","r"))
    {
        freopen(TASK".inp","r",stdin); 
        freopen(TASK".out","w",stdout); 
    }
    int t = 1;
    // cin>>t ; 
    while(t--)
    {
    	// cout<<"G";
        doc();
    }
}