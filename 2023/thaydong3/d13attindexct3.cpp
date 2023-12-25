/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "d13attindexct3"
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

const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 
int n ,q ; 
int a[N] ; 	
ll sm ;
void doc()
{
	cin>>sm ;
	str S ;
	cin>>S ;
	n=SZ(S) ;
	FOR(i,1,n)
	{
		a[i] = S[i-1]-'0' ; 
	}    
	cin>>q; 
}

namespace sub1
{
	ll mu[N] , s[N] ; 
	ll pw(ll a, ll n)
	{
		if(n==0) return 1;   
		ll b = pw(a,n/2); 
		if(n&1)return b*b%sm*a%sm;
		return b*b%sm ;
	}
	ll get(int l ,int r )
	{
		return (s[r]-s[l-1]*mu[r-l+1]%sm)%sm;
	}	
    void xuly()
    {
    	FOR(i,1,n)s[i]=(s[i-1]*10+a[i])%sm;
		mu[0] =1 ;
		n= 1000 ;
		FOR(i,1,n)mu[i] = mu[i-1]*10%sm; 
		prt(mu,n) ;
        while(q--)
        {
        	int res = 0 ;
        	int l, r ; cin>> l >>r;
        	FOR(i,l,r)
        	{
        		FOR(j,i,r)
        		{
        			if(get(i,j)==0)res++ ; 
        		}
        	}
        	cout<<res<<el;
        }
    }
}
namespace sub2
{
	ll s[N] ; 
	ll cnt[N] ; 
	void xuly()
	{
		FOR(i,1,n)
		{	
			s[i]=s[i-1] ;
			cnt[i] = cnt[i-1];
			if(a[i]%sm==0)
			{
				s[i]+=i ;
				cnt[i]++;
			}
		}
		while(q--)
		{
			int l, r; cin>> l >>r ; 
			ll res= s[r]-s[l-1]-(cnt[r]-cnt[l-1])*(l-1) ;
			cout<<res<<el;
		}
	}
}
namespace sub3
{
	int block ; 
	struct Query
	{
		int l, r,id ;
		bool operator<(const Query&a)const
		{
			return l/block<a.l/block||(l/block==a.l/block&&r<a.r) ; 
		}
	}Q[N] ; 
	ll mu[N],s[N],res[N]; 
	int pos[N] , cnt[N] ; 
	ll tot = 0 ; 
	void xuly()
	{
		block = sqrt(n) ;
		mu[0] = 1; 
		FOR(i,1,n)mu[i]=mu[i-1]*10%sm;
		vi V ;
		FORD(i,n,1)
		{
			s[i]  = (s[i+1] + a[i]*mu[n-i]%sm)%sm;
			V.pb(s[i]) ; 
		}
		V.pb(0) ; 
		uni(V) ; 
		FOR(i,1,n+1)
		{
			pos[i] = UB(all(V),s[i])-V.begin() ; 
		}
		FOR(i,1,q)
		{
			cin>>Q[i].l>>Q[i].r ;
			Q[i].r++;
			Q[i].id = i ; 
		}
		sort(Q+1,Q+q+1) ;
		int L = 1 , R = 1 ; 
		cnt[pos[1]]=1 ;
		tot = 0; 
		FOR(i,1,q)
		{
			int id = Q[i].id ;
			while(Q[i].l<L)
			{
				--L;
				tot+=cnt[pos[L]] ; 
				cnt[pos[L]]++ ;
			}
			while(R<Q[i].r)
			{
				++R;
				tot+=cnt[pos[R]] ;
				cnt[pos[R]]++ ;
			}
			while(L<Q[i].l)
			{
				cnt[pos[L]]--;
				tot-=cnt[pos[L]] ;
				++L ;
			}
			while(Q[i].r<R)
			{
				cnt[pos[R]]--;
				tot-=cnt[pos[R]];
				--R;
			}
			res[id] = tot; 
		}
		FOR(i,1,q)cout<<res[i]<<el;
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
        // if(max(n,q)<=100)sub1::xuly() ; 
        // else 
        // 	if(sm==2)sub2::xuly() ;
        if(sm==2||sm==5)sub2::xuly();
        else 
        sub3::xuly();
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}