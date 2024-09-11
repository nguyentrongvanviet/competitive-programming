/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "CACHE"
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
#define prt(a,n) {FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;}
#define prv(a) {for(auto _v:a)cout<<_v<<" "; cout<<el;} 

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 5e5+5 , oo = 2e9 , LO = 23 , CH = 26 ; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;} 

void add(ll& a , ll b){a+=b;if(a>=sm)a-=sm;}
void sub(ll& a , ll b){a-=b;if(a<0)a+=sm;}

int n , m , q ;
vi a[N] ; 
void doc()
{
    cin >> n >> m >> q; 
    FOR(i,1,m)
    {
    	int sl; 
    	cin>>sl;
    	a[i].resize(sl+1) ; 
    	FOR(j,1,sl)
    	{
			cin>>a[i][j] ;  
    	}
    }
}

namespace sub1
{
	vi root[N] ; 
	int st[N*(LO+2)] , L[N*(LO+2)] , R[N*(LO+2)] ; 
	int node = 0 ;  
	int up_p(int old, int l ,int r ,int pos , int val)
	{
		int cur = ++node ;
		if(l==r)
		{
			st[cur]=st[old]+val;
			return cur; 
		}
		int mid = (l+r)>>1 ;
		if(pos<=mid)
		{
			R[cur]=R[old];
			L[cur]=up_p(L[old],l,mid,pos,val) ; 
		}
		else
		{
			L[cur]=L[old] ; 
			R[cur]=up_p(R[old],mid+1,r,pos,val) ; 
		}
		st[cur] = st[L[cur]]+st[R[cur]] ; 
		return cur ;
	}
	int get_p(int id, int l ,int r ,int t , int p )
	{
		if(t<=l&&r<=p)return st[id] ;
		if(r<t||p<l)return 0 ;  
		int mid= (l+r)>>1 ;
		return get_p(L[id],l,mid,t,p) + get_p(R[id],mid+1,r,t,p) ; 
	}
	struct DL
	{
		int ID , gen , pos ; 
		DL(){ID=gen=pos=0;}
		DL(int _ID,int _gen,int _pos){ID=_ID,gen=_gen,pos=_pos;}
	};
	DL T[4*N] ; 
	void dolazy(int id,int l, int r)
	{
		if(l==r||T[id].ID==0)return ; 
		T[id<<1]=T[id] ; 
		T[id<<1|1]=T[id] ; 
		T[id<<1|1].pos+=((l+r)/2+1-l); 
		T[id] = {0,0,0} ; 
	}
	void up(int id, int l ,int r, int t, int p , DL tmp )
	{
		dolazy(id,l,r) ;
		if(t<=l&&r<=p)
		{
			T[id] = tmp ; 
			dolazy(id,l,r) ; 
			return ; 
		}
		if(r<t||p<l)return ; 
		int mid = (l+r)>>1; 
		up(id<<1,l,mid,t,p,tmp) ; 
		tmp.pos+=max(0,min(mid,p)-max(l,t)+1);
		up(id<<1|1,mid+1,r,t,p,tmp) ; 
	}
	int get(int id ,int l ,int r ,int pos)
	{
		dolazy(id,l,r) ; 
		if(l==r)
		{
			return get_p(T[id].gen,1,a[T[id].ID].size()-1,1,T[id].pos);
		}
		int mid=(l+r)>>1; 
		if(pos<=mid)return get(id<<1,l,mid,pos) ;
		return get(id<<1|1,mid+1,r,pos) ;
	}
    void xuly()
    {
    	FOR(i,1,m)
    	{
    		root[i].pb(0) ; 
    		int fi_gen = 0; 
    		FORN(j,1,a[i].size())
    		{
    			fi_gen = up_p(fi_gen,1,a[i].size()-1,j,a[i][j]-a[i][j-1]) ; 
    		}
    		root[i].pb(fi_gen) ;
    	}
    	// cout<<get_p(root[2].back(),1,a[2].size()-1,1,3)<<el;
    	while(q--)
    	{
    		int type ;
    		cin>>type ;
    		if(type==1)
    		{
    			int id , pos ; cin>>id >> pos  ;
    			int cur_gen = root[id].back() ; 
    			// cout<<id<<" "<<cur_gen<<el;
    			up(1,1,n,pos,pos+(a[id].size()-1)-1,DL{id,cur_gen,1});
    		}
    		else if(type==2)
    		{
    			int pos ; cin>>pos ;
    			cout<<get(1,1,n,pos)%256<<el;
			}
			else
			{
				int id , l , r ; cin>>id>>l>>r;
				l=max(1,l) ; 
				r=min(r,(int)a[id].size()-1) ;
				// int new_gen = node+LO ;  
				int new_gen = up_p(root[id].back(),1,a[id].size()-1,l,1); 
				if(r+1!=(int)a[id].size())new_gen = up_p(new_gen,1,a[id].size()-1,r+1,-1) ;
				root[id].pb(new_gen);
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