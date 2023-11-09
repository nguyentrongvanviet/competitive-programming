// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "SUBLEX"

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

const int N =3e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ; 
int a[N] ; 
struct suffix_automaton	
{
	unordered_map<int,int>next[N] ; 
	int dd[N],f[N],link[N],len[N] ; 
	int sz=0,la=0 , last= 0 ; 
	void init()
	{
		FOR(i,0,sz)
		{
			dd[i]=  len[i] = f[i] = 0 ;  
			next[i].clear() ;  
		}
		link[0] = -1 ; 
		last = sz= 0 ; 
	}
	void extend(int c )
	{
		int cur =++sz;
		len[cur] =len[last]+1 ;  
		int p ; 	
		for(p=last;p!=-1&&!next[p].count(c);p=link[p])
		{
			next[p][c]=cur ;
		}
		if(p!=-1)
		{
			int q= next[p][c] ; 
			if(len[p]+1==len[q])
			{
				link[cur] = q; 
			}
			else
			{
				int clone =++sz ; 
				len[clone] = len[p]+1; 
				next[clone]= next[q] ; 
				link[clone]=link[q];
				for(;p!=-1&&next[p][c]==q;p=link[p])
				{
					next[p][c]= clone ; 
				}
				link[q] =clone ; 
				link[cur] = clone ; 
			}
		}
		last =cur; 	
	}
	int dfs(int u)
	{
		if(dd[u])return f[u] ;
		f[u]=1 ;
		dd[u]=1 ; 
		FOR(i,'a','z')
		{
			if(!next[u].count(i))continue ; 
			int v= next[u][i] ; 
			f[u]+=dfs(v) ; 
		}
		return f[u] ; 
	}
	void get(int cur  , int k )
	{
		while(1)
		{
			FOR(c,'a','z')
			{
				if(!next[cur][c])continue ; 
				int v= next[cur][c] ; 
				int val = dfs(v) ;
				if(k==1)
				{	
					cout<<(char)c ; 
					return; 
				}
				if(val<k)
				{
					k-=val ; 
				}
				else 
				{
					cout<<(char)c; 
					cur= v ;
					k--;
					break ; 
				}
			}
		}
	}
}; 
suffix_automaton sa  ; 
void doc()
{
    string s ; cin>>s; 
    n=s.size() ; 
   	FOR(i,1,n)
   	{
   		a[i] = s[i-1]  ; 
   	}
}
void xuly()
{
	suffix_automaton sb ; 
	sa.init() ;
    FOR(i,1,n)sa.extend(a[i]);
    int q; 
    cin>>q; 
    while(q--)
    {
    	int k;  
    	cin>>k ; 
    	// cout<<"G";
    	sa.get(0,k);
    	cout<<"\n";
    } 	
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}	