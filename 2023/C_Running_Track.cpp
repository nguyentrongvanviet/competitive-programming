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
#define           btpc  __builtin_popcountll
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 2100+5, oo = 2e9, LO = 17, CH = 26 ; 

int n  , m;  
str S , T ,Sr; 
void doc()
{
	cin>>S ;  
	cin>>T ; 
	n = S.size() ; 
	m = T.size() ; 
	reverse(all(S)) ; 
	Sr=S ; 
	reverse(all(S)) ; 
	S="#"+S ; 
	Sr="#"+Sr ;
	T="%"+T ; 
}
namespace sub1
{	
	
	ll hS[N] , hSr[N] ;
	ll hT[N] ;
	ll mu[N] ; 
	int sa_S[N] , sa_Sr[N] ; 
	int f[N] ; 
	pii pre[N] ; 
	ll get_hash(int l ,int r, ll ha[])
	{
		return (ha[r]-ha[l-1]*mu[r-l+1]+sm*sm)%sm;
	}
	void build(str&s, int n , int sa[] , ll ha[])
	{
		FOR(i,1,n)sa[i] = i ; 
		FOR(i,1,n)ha[i] = (ha[i-1]*cs+s[i])%sm ; 
		sort(sa+1,sa+n+1,[&](int i ,int j )
		{
			int ans = -1 ;  
			int l = 0 ; 
			int r = min(n-i,n-j) ; 
			while(l<=r)
			{
				int mid = (l+r)/2 ; 
				if(get_hash(i,i+mid,ha)!=get_hash(j,j+mid,ha))ans=mid,r=mid-1 ; 
				else l=mid+1; 
			}
			if(ans==-1)return i>j ; 
			return s[i+ans]<s[j+ans] ; 
		});
	}
	int check(int idl , int idr , int sa[N]  , ll ha[] , ll hT[],str&S )
	{
		int l =1;  
		int r = n ; 
		while(l<=r)
		{
			int mid = (l+r)/2; 
			int L = 0 ; 
			int R = min(idr-idl,n-sa[mid]) ; 
			int ANS = -1 ; 
			while(L<=R)
			{
				int MID = (L+R)/2 ;
				if(get_hash(sa[mid],sa[mid]+MID,ha)!=get_hash(idl,idl+MID,hT))
				{	
					ANS=MID ; 
					R=MID-1 ;
				}
				else L=MID+1 ;
			}	
			if(ANS==-1)
			{
				if(R==idr-idl)return sa[mid] ;
				else l=mid+1 ;
			}
			else
			{
				if(S[sa[mid]+ANS]<T[idl+ANS])l=mid+1 ; 
				else r=mid-1;
			}
		}
		return 0 ; 
	}
	void xuly()
	{
		mu[0] = 1;  
		FOR(i,1,2100)mu[i]=mu[i-1]*cs%sm; 
		build(S,n,sa_S,hS) ; 
		
		build(Sr,n,sa_Sr,hSr) ; 
		f[0] = 0 ; 
		FOR(i,1,m)
		{
			hT[i] = (hT[i-1]*cs+T[i])%sm;
			f[i] = oo ; 
			FOR(j,1,i)
			{
				int l = check(j,i,sa_S,hS,hT,S); 
				if(l)
				{
					if(mini(f[i], f[j-1]+1))pre[i] = {l,l+i-j}; 
					break;
				}
				else
				{
					int l= check(j,i,sa_Sr,hSr,hT,Sr) ; 
					if(l)
					{
						if(mini(f[i],f[j-1]+1))pre[i] = {n-l+1,n-(l+i-j)+1};
						break ; 
					}
				}
			}
		}
		if(f[m]==oo)return void(cout<<-1) ; 
		cout<<f[m]<<el ; 
		ve<pii>res ; 
		while(m)
		{
			res.pb(pre[m]) ; 
			m-=abs(pre[m].fi-pre[m].se)+1;
		}
		reverse(all(res)) ; 
		for(auto x : res)cout<<x.fi<<" "<<x.se<<el;
	}
}
namespace sub2
{
	int lcp[N][N] ;
	int lcp_r[N][N] ; 
	void xuly()
	{
		FORD(i,m,1)
		{
			FORD(j,n,1)
			{
				if(T[i]==S[j])
				{
					lcp[i][j] = lcp[i+1][j+1]+1 ;
					lcp_r[i][j] = lcp_r[i+1][j-1]+1;
				} 
			}
		}
		ve<pii>res; 
		for(int i = 1;i<=m;)                 
		{
			int u = max_element(lcp[i]+1,lcp[i]+n+1)-lcp[i];
			int v = max_element(lcp_r[i]+1,lcp_r[i]+n+1)-lcp_r[i]; 
			int len = max(lcp[i][u],lcp_r[i][v]) ; 
			if(len==0)return void(cout<<-1);
			if(len==lcp[i][u])
			{
				res.pb({u,u+len-1}); 
			}
			else
			{
				res.pb({v,v-len+1}) ; 
			}
			i+=len ;
		}
		cout<<res.size()<<el ; 
		for(auto x: res)cout<<x.fi<<" "<<x.se<<el;
	}
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ; 
        sub2::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}