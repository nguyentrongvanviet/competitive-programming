#include<bits/stdc++.h>
using namespace std;

#define TASK "PFTREE"

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
#define int long long 
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

const int N =1e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ; 

struct DL
{
	int h ; 
	int sl ; 
};
int n  ,q ;
ll res=0 , t =0  ;
int h[N]; 
vector<int>g[N] ; 
vector<DL>s[N] ;
void doc()
{
    cin>> n >>q ; 
    FOR(i,1,n-1)
    {
    	int u ,v ; 
    	cin>>u>>v ; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
}
void merge(vector<DL>&x,vector<DL>&y )
{
	vector<DL>ans;
	int n = x.size() ; 
	int m = y.size() ; 
	int i = 0  , j = 0 ; 
	int node =0  ;
	int lai = 0 ; 
	int laj =0  ; 
	while(i<n&&j<m)
	{
		int a= x[i].h  ; 
		int sl1= x[i].sl ; 
		int b =y[j].h ; 
		int sl2= y[j].sl ; 
		if(a==b)
		{
			if(ans.empty())
			{
				ans.pb({a,sl1+sl2}); 
				++i; 
				++j;
				lai = sl1; 
				laj = sl2;
			}	
			else if(ans.back().sl<sl1+sl2)
			{
				ans.pb({a,sl1+sl2}); 
				++i; 
				++j;
				lai = sl1; 
				laj = sl2;
			}
		}	
		else if(a<b)
		{
			if(ans.empty())
			{
				ans.pb({a,laj+sl1});
				lai =sl1 ; 
				++i;
			}
			else if(laj+sl1>ans.back().sl)
			{
				ans.pb({a,laj+sl1});
				lai =sl1 ; 
				++i;
			}
		}
		else if(a>b)
		{	
			if(ans.empty())
			{
				ans.pb({b,lai+sl2});
				laj = sl2;  
				++j;
			}
			else if(lai+sl2>ans.back().sl)
			{
				ans.pb({b,lai+sl2});
				laj = sl2;  
				++j;
			}
		}
	}
	if(i!=n-1)
	{
		FOR(jj,j,m-1)
		{
			ans.pb({y[jj].h,y[jj].sl+lai});
		}	
	}
	if(j!=m-1)
	{
		FOR(ii,i,n-1)
		{
			ans.pb({x[ii].h,x[ii].sl+laj});
		}
	}	
	x=ans;  
}
void dfs(int u , int p)
{
	s[u].pb({0,1});
	vector<DL>tmp;
	for(int i= 0  ;i<(int)g[u].size();i++)
	{
		int v= g[u][i] ; 
		if(v==p)continue ; 
		dfs(v,u);
		h[u]=h[v]+1;
		merge(tmp,s[v]); 
	}
	if(!tmp.empty())
	{
		int st=(tmp[0].sl==1);
		FOR(i,st,(int)tmp.size()-1)
		{
			s[u].pb({tmp[i].h+1,tmp[i].sl});
		}
	}
}
ll pw(ll a, ll n)
{
	if(n==0)return 1;  
	ll b= pw(a,n/2) ; 
	if(n&1)
	{
		return b*b%sm*a%sm;  
	}
	else
	{
		return b*b%sm; 
	}
}
ll value(ll l , ll r , ll a , ll b , ll sl)
{
	ll res= 0 ;
	--a;
	--b;
	if(l==0)++l,a+=sl;
	if(t==1)
	{
		return (l+r)*(r-l+1)/2%sm*sl%sm;
	}
	// ll x= 0 ;
	// if(pw(t,sl)==1)
	// {
	// 	while(1);
	// }
	ll x=  pw(t,a)*(pw(t,sl*(r-l+1))-pw(t,sl)+sm)%sm*pw((pw(t,sl)-1+sm)%sm,sm-2)%sm;
	// cout<<pw(t,a)*(pw(t,sl*(r-l+1))-pw(t,sl)+sm)%sm<<endl;
	if(l<=r&&a<=b)res=((r*pw(t,b+1)%sm-l*pw(t,a)%sm-x)%sm+sm)%sm*pw(t-1,sm-2)%sm;
	return res%sm; 
}
ll query(int u , int t)
{
	ll ans= 0 ; 
	int tmp= 0 ;
	FOR(i,0,(int)s[u].size()-2)
	{
		int a = s[u][i].h; 
		int b = s[u][i+1].h-1;
		int node = (b-a+1)*s[u][i].sl; 
		int l = tmp+1;
		ans+=value(a,b,l,l+node-1,s[u][i].sl);
		ans%=sm;
		tmp+=node; 
	}
	int sz= s[u].size();
	int node= (h[u]-s[u][sz-1].h+1)*s[u][sz-1].sl;
	ans+=value(s[u][sz-1].h,h[u],tmp+1,tmp+node,s[u][sz-1].sl);
	ans%=sm;
	return ans ; 
}
void xuly()
{
    dfs(1,0) ;
    ll s= 0 ;
    FOR(i,1,q)
    {
    	int a , b ;
    	cin>>a>>b;  
    	int u=1+(a+s)%n; 
    	t=1+(b+s)%(ll)1e9;
    	// cout<<u<<" "<<t<<endl; 
    	res=query(u,t) ;
    	s+=res;
    	cout<<res<<"\n";
    }
    // cout<<8<<"\n"<<9<<"\n"<<0<<endl;
}
signed main()
{
    IOS();  
    doc(); 
    xuly();
}