// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "distinct_substr"

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

const int N =1e6+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  
const int CH = 26 ; 
int n;  
int a[N] ;
struct suffix_automaton
{
	unordered_map<int,int>next[N];
	int  link[N] , sz , last ,len[N] , f[N] ;
	bool dd[N] ;  
	suffix_automaton(){}
	void init()
	{
		FOR(i,0,sz)
		{
			dd[i] = 0 ; 
			next[i].clear();
			link[i] =  len[i] = f[i] = 0 ;   
		}
		len[0] = 0  ;  
		link[0] = -1 ; 
		sz= 0 ;
		last= 0 ; 
	} 
	void extend(int c )
	{
		int cur =++sz , p ; 
		len[cur] =len[last]+1; 
		for(p=last;p!=-1&&!next[p].count(c);p=link[p]) 
		{
			next[p][c] =cur ;
		}
		if(p!=-1)
		{
			int q= next[p][c]  ;
			if(len[p]+1==len[q])
			{
				link[cur] = q; 
			}
			else 
			{
				int clone = ++sz; 
				next[clone] = next[q] ; 
				link[clone] =link[q] ; 
				len[clone] = len[p]+1; 
				for(; p!=-1&&next[p][c]==q;p=link[p])
				{
					next[p][c] = clone ; 
				}
				link[cur] = clone  ; 
				link[q] = clone;  
			}
		}
		last =cur;
	}
	int dfs(int u)
	{
		if(dd[u])return f[u] ; 
		dd[u]=1 ;
		f[u]= 1; 
		FOR(c,0,256)
		{
			if(next[u].count(c))
			{	
				int v= next[u][c] ; 
				dfs(v);
				f[u]+=f[v];
			}
		}
		return f[u] ;
	}	
	ll distinct()
	{
		int res = dfs(0) ;
		return res-1 ;  
	}
} ; 
suffix_automaton sa ,sb ; 
void doc()
{
	string s; 
	cin>>s;  
	n=  s.size(); 
 	FOR(i,1,n)
 	{
 		a[i] = s[i-1] ;  
 	}
}
void xuly()
{
	sa.init();
    // suffix_automaton sb ;
    FOR(i,1,n)
    {
    	sa.extend(a[i]) ; 
    }
    cout<<sa.distinct()<<"\n";	
}
int main()
{
    IOS(); 
    int test =1 ; 
    // cin>>test ;
    while(test--)
    {
    	doc(); 
    	xuly();
    }  
   
}