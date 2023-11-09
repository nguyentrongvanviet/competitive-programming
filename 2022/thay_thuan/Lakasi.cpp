#include<bits/stdc++.h>
using namespace std;

#define TASK "Lakasi"

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
// #define int long long   
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

struct Q
{
	int t , u , v ; 
};
struct ke 
{
    int v , w ;
};
int q , tt = 0 , node = 1 , n = 1 ;
Q query[N] ;
vector<ke> g[N] ;
int f[N] ,l[N],r[N]; 
int T[N*40][2];
set<int> s[N*40];
string t;  
void doc()
{
    cin> >q ;
    FOR(i,1,q)
    {
     	cin>>t; 
    	if(t[0]=='A')
    	{
    		int u , v ; 
            cin>>u>>v ;
    		++n; 
    		query[i] ={0,u,n} ; 
    		g[u].pb({n,v}) ; 
    	}
    	else 
    	{
    		int u , v ; 
            cin>>u>>v ;
    		query[i] ={1,u,v} ; 
    	}
    }
}
void dfs(int u ,int p )
{
	l[u]=++tt; 
	for(auto x : g[u])
	{
		int v =x.v; 
		int w =x.w; 
		f[v]=(f[u]^w);
		dfs(v,u);
	}
	r[u]=++tt; 
}
void up(int val,int pos  )
{
    int r =1 ; 
    FORD(i,30,0)
    {
        int j= (val>>i&1); 
        if(T[r][j]==0)
        {
            T[r][j]=++node; 
        }
        r=T[r][j] ;
        // cout<<r<<endl;
        s[r].insert(pos); 
    }
}
int get(int val,int t , int p  )
{
    int r = 1; 
    int ans= 0  ;
    FORD(i,30,0)
    {
        int j = (val>>i&1); 
        // cout<<j<<endl;
        int x= T[r][j^1];
        int y= T[r][j];
        auto it = s[x].lower_bound(t);
        if(s[x].size()==0)r=y;
        else if(it==s[x].end())r=y;
        else if(*it>p)r=y; 
        else
        {
            ans|=(1<<i);
            r=x;
        }
    }
    return ans ; 
}
void xuly()
{
    dfs(1,0);
    up(0,l[1]);
    FOR(i,1,q)
    {
        int t= query[i].t;
        int u= query[i].u; 
        int v = query[i].v; 
        if(t==0)
        {
            up(f[v],l[v]);
        }
        else 
        {
            cout<<get(f[u],l[v],r[v])<<"\n";
        }
    }
}
signed main()
{
    IOS();  
    doc(); 
    xuly();
}