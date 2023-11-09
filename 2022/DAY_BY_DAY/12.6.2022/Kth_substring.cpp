// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK ""

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


struct Suffix_automaton
{
	int sz ; 
	unordered_map<int,int>next[2*N] ; 
	int len[2*N]  , link[2*N] ; 
	Suffix_automaton()
	{
		sz= 0 ; 
		link[0] = -1 ;
		len[0] = 0 ; 
	}
	void extend(int c )
	{
		int cur = ++sz; 
		int p ; 
		for(;p!=-1&&!next[p].count(c);p=link[p]) 
		{
			
		}
	}
}sa ; 	
void doc()
{
    
}
void xuly()
{
    
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}