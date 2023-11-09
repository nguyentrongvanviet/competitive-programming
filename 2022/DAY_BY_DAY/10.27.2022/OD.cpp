// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "OD"

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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct Q
{
	int l , r ,t; 
};  	
struct ke 
{
	int v, c, t ; 
};
Q query[N] ; 
int n ,q;  
int dd[N] ;
vector<ke>g[N] ;
vector<int>value;  
unordered_map<int,int>pos ; 
void doc()
{
	cin>>n ;
	cin>>q ;
	FOR(i,1,q)
	{
		string x ;
		cin>>query[i].l>>query[i].r;
		cin>>x; 
		query[i].t=(x[0]=='o');
		--query[i].l;  
		value.pb({query[i].l}); 
		value.pb({query[i].r}) ; 
	}    
}
bool ok   ; 
void dfs(int u , int t )
{
	if(dd[u]==0)dd[u] =1;
	for(auto it: g[u])
	{
		int v= it.v; 
		int c= it.c;
		int tt= it.t;  
		if(tt<=t)
		{
			if(dd[v]!=0)
			{
				if(c==1)
				{
					if(dd[v]==dd[u])ok =0 ; 
				}
				else if(dd[u]!=dd[v])ok=0  ;
			}
			else
			{
				if(c==0)dd[v]=dd[u]; 
				else dd[v]=(dd[u]==1?2:1);
				dfs(v,t); 
			}
			
		}
	}	
	if(ok==0)return ;
}
bool check(int t)
{
	ok =1 ; 
	FOR(i,1,n)dd[i] =0 ;
	FOR(i,1,n)if(dd[i]==0)
	{
		dfs(i,t) ; 
		if(!ok)return 0 ;
	}
	return 1; 
}
void xuly()
{
	sort(all(value)) ;
	value.resize(unique(all(value))-value.begin()) ; 
	n=value.size();  
	FOR(i,0,n-1)
	{
		pos[value[i]]=i+1;
	}
	FOR(i,1,q)
	{
		query[i].l= pos[query[i].l] ; 
		query[i].r= pos[query[i].r] ;
		int u=query[i].l ; 
		int v=query[i].r; 
		int c=query[i].t;
		g[u].pb({v,c,i});
		g[v].pb({u,c,i}); 
	}
	int l =1 ; 
	int r =q ; 
	int ans= 0 ; 
	while(l<=r)
	{
		int mid=(l+r)/2 ; 
		if(check(mid))
		{
			ans=mid ; 
			l=mid+1; 
		}
		else
		{
			r=mid-1; 
		}
	}
	// cout<<check(1)<<endl;
	cout<<ans; 
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}