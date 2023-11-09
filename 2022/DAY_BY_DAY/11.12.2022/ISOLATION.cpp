#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define mp make_pair 
#define fi first 
#define se second  
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const int N = 2e5+5  , oo = 2e9  ; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ; 

int n , q ;
pii a[N] ; 
pii Q[N] ; 
bool cmp(pii  a,  pii b )
{
	return a.fi>b.fi ; 
}
int dd[N] ; 
int res[N] ; 
void doc()
{	
	cin>>  n >> q ; 
	FOR(i,1,n)
	{
		int val; 
		cin>>val; 
		a[i] = mp(val,i) ; 
	}
	sort(a+1,a+n+1,cmp) ;   
	FOR(i,1,q)
	{	
		cin>>Q[i].fi ; 
		Q[i].se =  i ;
	}		
	sort(Q+1,Q+q+1,cmp) ;
	int it = 1  ;
	int cnt= 0 ; 
	FOR(i,1,q)
	{
		while(a[it].fi>Q[i].fi&&it<=n)
		{
			int pos = a[it].se ;
			dd[pos] = 1; 
			if(dd[pos-1]&&dd[pos+1])cnt-- ; 
			else if(dd[pos-1]==0&&dd[pos+1]==0)cnt++;
			it++;
		}	
		res[Q[i].se] =cnt; 
	}	
	FOR(i,1,q)cout<<res[i]<<" ";
}		


void xuly()
{

}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test =1;
    if(multitest)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Time: "<<clock()<<"ms"<<el;
}