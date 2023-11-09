/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 

#define             ll  long long 
#define             db  double 
#define             ve  vector 
#define             vi  vector<int>
#define            vll  vector<ll>
#define            str  string
#define             pb  push_back
#define             pk  pop_back
#define             el  '\n'
#define            pii  pair<int,int>
#define            pll  pair<ll,ll>
#define             mp  make_pair 
#define             fi  first 
#define             se  second
#define         uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin()) 
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define    FORN(i,a,b)  for(int i=(int)(a);i<(int)(b);i++)
#define         all(a)  a.begin(),a.end()  
#define           btpc  __builtin_popcountll
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define          SZ(_)  (int)(_.size())
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}

#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 5e4+5 , oo = 2e9 , LO = 16 , CH = 26 ; 

int n , q; 
int a[N] ; 
vi g[N] ; 
vi pos[N]; 
void doc()
{
    cin>> n >>q ;  
    FOR(i,1,n)
    {
    	cin>>a[i] ; 
    	pos[a[i]].pb(i) ; 
    }
    FOR(i,1,n-1)
    {
    	int u,v; cin>>u>>v ;
    	g[u].pb(v) ;
    	g[v].pb(u) ; 
    }
}

namespace sub1
{
	int h[N] ; 
	int sz[N] ; 
	int P[N][LO+2] ; 
	int tt = 0 ;
	int in[N] , out[N] ; 
	int node = 0 ; 
	int H[N] ;  
	int L[2*N*(LO+2)] , R[2*N*(LO+2)] ; 
	struct DL
	{
		int val ; 
		int sum ; 
		DL  operator + (const DL&a)const
		{
			return DL{val+a.val,sum+a.sum} ; 
		}
		DL operator - (const DL&a )const
		{
			return DL{val-a.val,sum-a.sum} ; 
		}
	} ;
	DL st[2*N*(LO+2)] ; 
	void dfs(int u ,int p)
	{
		in[u]=++tt; 
		sz[u] = 1 ;
		for(auto v:g[u])if(v!=p)
		{
			h[v]=h[u]+1;
			P[v][0] = u ; 
			dfs(v,u) ; 
			sz[u]+=sz[v];
		}
		out[u]=++tt;  
	}
	int up(int old ,int l ,int r, int pos , DL val)
	{
		int cur = ++node ;
		if(l==r)
		{
			st[cur] = val ;
			return cur ; 
		}
		int mid =(l+r)/2 ;
		if(pos<=mid)
		{
			R[cur] = R[old] ; 
			L[cur] = up(L[old],l,mid,pos,val) ; 
		}
		else
		{
			L[cur] = L[old] ; 
			R[cur] = up(R[old],mid+1,r,pos,val) ; 
		}
		st[cur] = st[L[cur]]+st[R[cur]] ; 
		return cur;  
	}
	DL get(int id ,int l ,int r , int t ,int p)
	{
		if(r<t||p<l)return DL{0,0}  ; 
		if(t<=l&&r<=p)return st[id] ; 
		int mid=(l+r)/2; 
		return get(L[id],l,mid,t,p)+get(R[id],mid+1,r,t,p) ; 
	}
	int lca(int u  ,int v)
	{
		if(h[u]<h[v])swap(u,v) ;
		FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])u=P[u][i] ; 
		if(u==v)return u ; 
		FORD(i,LO,0)
		{
			int nu = P[u][i] ; 
			int nv = P[v][i] ; 
			if(nu!=nv)
			{
				u=nu ; 
				v=nv; 
			}
		}
		return P[u][0] ; 
	}
	int TMP  ; 
	void solve(int u ,int p,int root)
	{
		DL tmp  = get(H[a[u]],1,2*n,in[root],out[root]) ; 
		if(tmp.val>sz[root]/2)
		{
			TMP = a[u] ; 
			return ; 
		}
		for(auto v:g[u])if(v!=p)
		{
			solve(v,u,root) ; 
			if(TMP)return; 
		}
	}
	void cal(int u ,int p ,int root )
	{
		int tmp = SZ(pos[a[u]])-get(H[a[u]],1,2*n,in[root],out[root]).val; 
		if(tmp>(n-sz[root])/2)
		{
			TMP = a[u] ;
			return ; 
		}
		for(auto v: g[u])if(v!=p)
		{
			cal(v,u,root) ; 
			if(TMP)return ;
		}
	}
	int LCA(int u ,int v , int c ,int x )
	{
		return get(H[x],1,2*n,1,in[u]).sum+get(H[x],1,2*n,1,in[v]).sum-2*get(H[x],1,2*n,1,in[c]).sum+(a[c]==x);
	}
	int res[N] ; 
    void xuly()
    {
    	h[1]=1 ; 
        dfs(1,0) ; 
        FOR(j,1,LO)FOR(i,1,n)P[i][j]=P[P[i][j-1]][j-1] ; 
        FOR(i,1,n)
        {
        	for(auto v:pos[i])
        	{
        		H[i] = up(H[i],1,2*n,in[v],{1,1}) ;
        		H[i] = up(H[i],1,2*n,	out[v],{0,-1}) ;   
        	}
        }
        vi spec ;
        int T = 2*sqrt(n) ; 
        FOR(i,1,n)if(SZ(pos[i])>=T/2)spec.pb(i); 
        FOR(_,1,q)
        {
        	int TYPE,u,v ; cin>>TYPE;  
        	TMP = 0;
        	if(TYPE==1)
        	{
        		cin>> u ; 
        		if(sz[u]<T) 
        		{
        			solve(u,P[u][0],u) ; 
        		}
        		else
        		{
        			for(auto v : spec)
        			{
        				if(get(H[v],1,2*n,in[u],out[u]).val>sz[u]/2)
	    				{
	    					TMP = v ; 
	    					break; 
	    				}
	    			}
        		}
        	}
        	else if(TYPE==2)
        	{
        		cin>>u ;
        		if(n-sz[u]<T)
        		{
        			if(u!=1)cal(P[u][0],u,u);
        		}
        		else
        		{
        			for(auto v:spec)
        			{
        				int tmp = SZ(pos[v])-get(H[v],1,2*n,in[u],out[u]).val;
        				if(tmp>(n-sz[u])/2)
        				{
        					TMP = v ; 
        					break; 
        				}
        			}
        		}
        	}
        	else if(TYPE==3)
        	{
        		cin>> u >> v ; 
        		int c = lca(u,v) ; 
        		int sz=  h[u]+h[v]-2*h[c]+1 ;
    			// if(_==18)cout<<"YESG"<<el;

				if(sz<T)
        		{
        			for(int U = u ; h[U]>=h[c];U=P[U][0])
        			{
        				int tmp = LCA(u,v,c,a[U]) ; 
        				if(tmp>sz/2)
        				{
        					TMP= a[U] ; 
        					break ; 
        				}
        			}
        			for(int U = v ; h[U]>=h[c];U=P[U][0])
        			{
        				int tmp = LCA(u,v,c,a[U]) ; 
        				if(tmp>sz/2)
        				{
        					TMP= a[U] ; 
        					break ; 
        				}
        			}

        		}	
        		else
        		{	
        			// if(_==18)cout<<"YES"<<el;
        			for(auto x: spec)
        			{
        				int tmp = LCA(u,v,c,x); 
    					if(tmp>sz/2)
    					{
    						TMP = x ; 
    						break ; 
    					}
        			}
        		}
        	}	
        	res[_] = TMP ; 
        }
        FOR(i,1,q)
        {
        	cout<<(res[i]==0?-1:res[i])<<el;
        }
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    
    if(mtt)cin>>test;

    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}
