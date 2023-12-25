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
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        M(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
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
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , sm , q ;
struct Query
{
	int type , l , r; 
} ; 
Query Q[N] ;
vi V ;
int mu[10] ;
void doc()
{
    cin>>n >>sm>>q ;
    mu[0] = 1; 
    FOR(i,1,9)mu[i]=mu[i-1]*10;
    FOR(i,1,q)
    {
    	cin>>Q[i].type>>Q[i].l>>Q[i].r ;
    	if(Q[i].type==1)
    	{
    		V.pb(Q[i].l),V.pb(Q[i].r) ;
    	}
    	else V.pb(Q[i].l) ;
    }
}

namespace sub1
{
	bool check(int val)
	{
		if(val%sm==0)return 1; 
		while(val)
		{
			if(val%10==sm)return 1 ;
			val/=10 ;
		}
		return 0 ;
	}
	ll bit[3*N] ;
	void up(int id, int val)
	{
		for(int i=id;i<=SZ(V);i+=i&-i)bit[i]+=val;
	}
	ll get(int id)
	{
		ll ans = 0;
		for(int i=id;i;i-=i&-i)ans+=bit[i] ; 
		return ans ;
	}
	int old[3*N] ; 
	ll get(int l, int r)
	{	
		int R = UB(all(V),r)-V.begin() ; 
		int L = UB(all(V),l)-V.begin() ;
		return get(R)-get(L-1) ; 
	}
	struct DL
	{
		ll sum ;
		int sl ;
	} ;
	int c[N] ; 

	DL f[11][9][2][2];
	DL calc(int id ,int du ,int con ,int ok)
	{
		if(id==0)
		{
			return {0,(du==0)|con};
		}
		DL &VAL = f[id][du][con][ok] ;
		if(VAL.sum!=-1)return VAL ;
		VAL = DL{0,0} ;  
		FOR(i,0,max(c[id],ok*9))
		{
			DL tmp = calc(id-1,(du*10+i)%sm,con|(i==sm),ok|(i<c[id])) ;
			VAL.sum+=tmp.sum+1ll*i*mu[id-1]*tmp.sl;
			VAL.sl+=tmp.sl;
		}
		return VAL ;
	}
	ll tinh(int R)
	{
		int digit = 0 ;
		while(R)
		{	
			c[++digit] = R%10 ; 
			R/=10 ;
		}
		FOR(id,1,digit)FOR(du,0,sm-1)FOR(con,0,1)FOR(ok,0,1)f[id][du][con][ok].sum=-1;
		return calc(digit,0,0,0).sum; 
	}
    void xuly()
    {    	
    	uni(V);
    	FOR(i,1,q)
    	{
    		if(Q[i].type==1)
    		{
    			int pos = UB(all(V),Q[i].l)-V.begin(); 
    			int val = Q[i].r ;
    			if(old[pos]==0)
    			{
    				if(check(Q[i].l))old[pos] = 2*Q[i].l;
    				else old[pos] = Q[i].l ;
    			} 
    			if(check(Q[i].l))
    			{
    				up(pos,2*val-old[pos]);
    				old[pos] = 2*val; 
    			}
    			else 
    			{
    				up(pos,val-old[pos]) ;
    				old[pos] = val ;
    			}
    		}	
    		else
    		{
    			int l =Q[i].l;
    			int r =Q[i].r;
    			cout<<1ll*(l+r)*(r-l+1)/2+get(l,r)+(tinh(r)-tinh(l-1))<<el;
    		}
    	}
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}