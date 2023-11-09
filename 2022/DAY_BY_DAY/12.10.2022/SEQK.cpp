/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
code is just not for fun , it is for you too 
so if you have seen this please take it as a simple love I give to you so please take it as a message from my heart
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "SEQK"

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

const int N =1e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct DL
{
	int val ; 
	int pos ;  
	bool operator <(const DL &a)const
	{
		return val<a.val ;
	}
};
struct Q
{
	int val;  
	int id;  
	bool operator<(const Q&a )const
	{
		return val<a.val;
	}
}; 
struct DSU
{
	int pa[N] , len[N] ; 
	bool dd[N] ;
	int maxlen ; 
	void init(int n )
	{
		maxlen =0  ;
		FOR(i,1,n)pa[i] = i ,len[i] =1; 
	}
	void up(int pos )
	{
		dd[pos]=1 ; 
		maxlen=max(maxlen,1) ;
		if(dd[pos-1])hop(pos-1,pos) ; 
		if(dd[pos+1])hop(pos,pos+1) ;
	}
	int goc(int u)
	{
		return pa[u] == u ? u : pa[u]=goc(pa[u]) ; 
	}
	void hop(int u ,int v  )
	{	
		int chau= goc(u) ; 
		int chav= goc(v) ; 
		
		if(chau==chav) return ; 
		
		pa[chau] =chav ; 
		len[chav]+=len[chau] ; 
		
		maxlen=max(maxlen,len[chav]);
	}
}dsu ; 

int n  , q; 
DL a[N] ;  
Q query[N] ;
int ans[N] ;
// declare variable 

void doc()
{
    cin>> n  >>q;  
    FOR(i,1,n)cin>>a[i].val,a[i].pos= i ;
    FOR(i,1,q)cin>>query[i].val ,query[i].id= i ; 		 
}
void xuly()
{
    sort(a+1,a+n+1) ; 
    sort(query+1,query+q+1) ;

    int it =1 ; 
    dsu.init(n);
    FOR(i,1,q)
    {
    	int val =query[i].val;

    	while(it<=n&&a[it].val<=val)
    	{
    		dsu.up(a[it].pos);
    		++it;
    	} 

    	ans[query[i].id]= dsu.maxlen; 
    }

    FOR(i,1,q)cout<<ans[i]<<'\n';
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}