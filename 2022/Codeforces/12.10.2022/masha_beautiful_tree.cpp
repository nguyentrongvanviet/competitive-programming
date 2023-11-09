// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "masha_beautiful_tree"

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

const int N =262144+12 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int  m  ;
pii st[4*N] ;
int res=0 ;  
int a[N] ; 
void solve(int id , int l , int r )
{
	if(l==r)
	{
		st[id].fi = a[l] ;  
		st[id].se=  a[l] ; 
		return ; 
	}
	int mid =(l+r)/2; 
	solve(id*2,l,mid) ; 
	solve(id*2+1,mid+1,r) ; 

	if(st[id*2].se+1==st[id*2+1].fi)
	{	
		st[id].fi = st[id*2].fi ; 
		st[id].se =st[id*2+1].se; 
	}
	else if(st[id*2+1].se+1==st[id*2].fi) 
	{
		st[id].fi= st[id*2+1].fi ; 
		st[id].se= st[id*2].se; 
		++res;
	}
	else res=-oo;
}
void doc()
{
    cin>>m ; 
    FOR(i,1,m)cin>>a[i] ; 
    res= 0; 
    solve(1,1,m) ; 
    cout<< (res < 0 ? -1 : res) <<'\n';
}
void xuly()
{
    
}
int main()
{
    IOS(); 
    int test;
    cin>>test; 
    while(test--)
    {
	    doc(); 
	    xuly();    	
    } 

}