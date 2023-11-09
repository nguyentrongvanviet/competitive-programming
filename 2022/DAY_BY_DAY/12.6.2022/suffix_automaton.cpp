// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "suffix_automaton"

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
#define gcd(a,b)  __gcd(a,b) 
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

const int N =4e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n , m ; 
int a[N]  , b[N] ;
map<pii,int>pos;  
vector<pii>value  ; 
struct Suffix_automaton
{
	unordered_map<int,int>next[N] ; 
	int link[N] , len[N] ;
	int last =0 , sz= 0; 
	// state  
	Suffix_automaton()
	{
		sz= 0 ; 
		len[0] = 0  ; 
		link[0] = -1 ;
		last  = 0 ;  
	}
	void extend(int c )
	{		
		int cur = ++sz , p ;  
		len[cur] = len[last]+1 ; 
		for( p = last;p!=-1 && !next[p].count(c);p=link[p])
		{
			next[p][c] = cur ;
		}
		if(p!=-1)
		{
			int q= next[p][c]; 
			if(len[p]+1==len[q])
			{
				link[cur] = q;
			}
			else 
			{
				int clone = ++sz; 
				len[clone] = len[p]+1 ; 
				link[clone] = link[q] ; 
				next[clone] = next[q] ; 
				for(;p!=-1&&next[p][c]==q;p=link[p])
				{
					next[p][c] = clone ; 	
				}
				link[cur]  = link[q] = clone ;
			}
		}
		last =cur ;
	}
} ;  
void doc()
{
	Suffix_automaton sa ; 
	cin>>S ; 
	
    // cin>>n>>m ; 
    // FOR(i,1,n)
    // {
    // 	cin>>a[i] ;
    // }
    // FOR(i,1,m)
    // {
    // 	cin>>b[i] ; 
    // } 
}
int LCS(int a[],int b[] , int n ,  int m )
{
	int ans= 0 ;  
	int cur =0 ;
	int len = 0 ;    
	FOR(i,1,m)
	{
		while(!sa.next[cur].count(b[i]) && cur)
		{
			cur = sa.link[cur] ; 
			len = sa.len[cur] ; 
		}
		if(sa.next[cur].count(b[i]))
		{
			cur =sa.next[cur][b[i]];  
			++len ; 
		}
		ans  =max(ans,len) ;
	}
	return ans; 
} 
void anhxa(int a[] , int n )
{
	FOR(i,1,n-1)
	{
		int uc = gcd(a[i],a[i+1]) ;
		pii tmp =  {a[i]/uc,a[i+1]/uc}; 
		auto it  = pos.find(tmp) ; 
		if(it==pos.end())
		{
			pos[tmp]= pos.size()+1 ; 
		}
		else
		{
			pos[tmp] =  it->se;  
		}
		a[i] = pos[tmp] ; 
	}	
}
void xuly()
{		

	// anhxa(a,n); 
	// anhxa(b,m);
	// FOR(i,1,n-1)sa.extend(a[i]) ; 
 	// cout<<LCS(a,b,n-1,m-1)+1<<"\n";   
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}