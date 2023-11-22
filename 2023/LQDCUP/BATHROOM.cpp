/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "BATHROOM"
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
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N =  30000+5 , oo = 2e9 , LO = 17 , CH = 26 ; 
const int tt = M(3)-1 ;  
int n , q; 
int a[N] ; 
struct Query
{
	int TYPE , l ,r ; 
} Q[N] ;
int ok = 0 ; 
void doc()
{
	cin>> n >> q; 	
	FORN(r,0,3)
	{
		FOR(i,1,n)
		{
			char x ; cin>>x ;
			if(x=='x')
			{
				a[i]|=M(r) ;
			}
		}
	}    
	FOR(i,1,q)cin>>Q[i].TYPE>>Q[i].l>>Q[i].r,ok|=(Q[i].TYPE==1) ; 
}

namespace sub1
{
	struct node
	{
		int leaf ;  
		int f[8][8] ; 
		node()
		{
			leaf = 0; 
			FORN(i,0,8)FORN(j,0,8)f[i][j]=0; 
		}
	};
	node st[4*N] ; 
	node merge(const node& Le , const node& Ri )
	{
		node ans ; 
		FOR(L,0,tt)FOR(R,0,tt)if(Le.f[L][R])FOR(U,0,tt)FOR(V,0,tt)if(Ri.f[U][V])
		{
			int msk = tt^(U|R);
			for(int ss = msk ; ; ss=(ss-1)&msk)
			{
				int nL=L , nV = V ;
				if(Le.leaf)nL|=ss ; 
				if(Ri.leaf)nV|=ss ;
				(ans.f[nL][nV]+=1ll*Le.f[L][R]*Ri.f[U][V]%sm)%=sm;
				if(ss==0)break;
			}
		}
		return ans ; 
	}
	void build(int id ,int l ,int r)
	{
		if(l==r)
		{	
			st[id]=node() ; 
			st[id].leaf=1 ; 
			st[id].f[a[l]][a[l]]=1 ; 
			FORN(i,0,2)if(BIT(a[l],i)==0&&BIT(a[l],i+1)==0)
			{
				st[id].f[a[l]|M(i)|M(i+1)][a[l]|M(i)|M(i+1)]=1 ; 
			}
			return ; 
		}
		int mid= (l+r)>>1 ; 
		build(id<<1,l,mid) ;
		build(id<<1|1,mid+1,r) ; 
		st[id] =  merge(st[id<<1],st[id<<1|1]) ; 
	}	
	void up(int id ,int l ,int r, int pos) 
	{
		if(r<pos||pos<l)return; 
		if(l==r&&l==pos)
		{
			st[id]=node() ; 
			st[id].leaf=1 ; 
			st[id].f[a[l]][a[l]]=1 ; 
			FORN(i,0,2)if(BIT(a[l],i)==0&&BIT(a[l],i+1)==0)
			{
				st[id].f[a[l]|M(i)|M(i+1)][a[l]|M(i)|M(i+1)]=1 ; 
			}
			return ; 
		}
		int mid=(l+r)>>1; 
		up(id<<1,l,mid,pos) ; 
		up(id<<1|1,mid+1,r,pos) ; 
		st[id] = merge(st[id<<1],st[id<<1|1]) ; 
	}
	node get(int id ,int l ,int r , int t ,int p )
	{
		if(t<=l&&r<=p)return st[id] ; 
		int mid=(l+r)>>1;
		if(p<mid+1)return get(id<<1,l,mid,t,p) ; 
		if(mid<t)return get(id<<1|1,mid+1,r,t,p) ;
		return merge(get(id<<1,l,mid,t,p),get(id<<1|1,mid+1,r,t,p)) ;
	}
    void xuly()
    {
        build(1,1,n) ; 
        FOR(_,1,q)
        {
        	int TYPE =Q[_].TYPE;
        	if(TYPE==1)
        	{
        		int row=Q[_].l ;
        		int id = Q[_].r ;
        		a[id]^=M(row-1);
        		up(1,1,n,id) ;
        	}
        	else
        	{
				int l =Q[_].l ; 
				int r =Q[_].r ; 
        		node ans = get(1,1,n,l,r) ;
        		ll res =0 ;  
        		FOR(i,0,tt)FOR(j,0,tt)(res+=ans.f[i][j])%=sm; 
        		cout<<res<<el;
        	}
        }
    }
}
namespace sub2
{
	int f[N][9] ;
	void add(int &a, int b)
	{
		a+=b;
		if(a>=sm)a-=sm; 
	}
	int res[N] ;
	void xuly()
	{
		f[0][tt]= 1;
		vi L; 
		FOR(cur,0,tt)if(btpc(cur)%2==0&&cur!=5)L.pb(cur);	
		FOR(i,1,n)
		{
			for(auto cur:L)
			{
				FOR(pre,0,tt)
				{ 
					int msk = tt^(cur|pre);
					for(int ss = msk ;;ss=(ss-1)&msk)
					{
						add(f[i][cur|ss],f[i-1][pre]);
						if(ss==0)break;
					}
				}
			}
		}
		FOR(i,1,n)
		{
			FOR(msk,0,tt)add(res[i],f[i][msk]);
		}
		FOR(i,1,q)
		{
			int l =Q[i].l ;
			int r =Q[i].r ;
			cout<<res[r-l+1]<<el;
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
    else 
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        if(*max_element(a+1,a+n+1)==0&&!ok)
        {
        	sub2::xuly() ; 
        }
        else 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}