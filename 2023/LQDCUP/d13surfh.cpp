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
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 3e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , q; 
ll a[N] ; 

void doc()
{
    cin>> n >> q; 
    FOR(i,1,n)cin>>a[i] ; 
}

namespace sub1
{
    void xuly()
    {
        while(q--)
       	{
       		char type ; cin>>type ;
       		if(type=='*')
       		{
       			int l ,r ; cin>> l >> r;
       			FOR(i,l,r)a[i]=-a[i] ; 
       		}
       		else if(type=='+')
       		{
       			int l ,r , v ;cin>> l >>r  >>v;
       			FOR(i,l,r)a[i]+=v; 
       		}
       		else
       		{
       			int l ,r ;cin>> l>>r; 
       			int len =1;
       			int type = 0 ;
       			ll res=1 ; 
       			FOR(i,l+1,r)
       			{	
       				if(a[i]==a[i-1])
       				{
       					res++;
       					len=1 ;
       					continue;
       				}
       				if(len==1)
       				{
   						type=(a[i-1]<a[i]); 
   						++len;
       				}
       				else if(len)
       				{
       					type^=1;
       					if(type)
       					{	
       						if(a[i-1]<a[i])len++ ;
       						else 
       						{
       							len=2;
       							type=0;
       						}
       					}	
       					else
       					{
       						if(a[i-1]>a[i])len++;
       						else 
       						{
       							len=2;
       							type=1;
       						}
       					}
       				}
   					res+=len;
          		}
          		prt(a,n);
       			cout<<res<<el;
       		}
       	}
    }
}
namespace sub2
{
	struct DL
	{
		ll L , R; 
		int L0 , L1 , R0 , R1 ;  
		ll res; 
	};
	DL merge(DL a , DL b, int l ,int r )
	{
		ll L = a.L ; 
		ll R = b.R ;
		int L0 = a.L0 ; 
		int L1 = a.L1 ; 	
		int R0 = b.R0 ; 
		int R1 = b.R1 ; 
		int dl = l&1 ;
		int dr = r&1 ;  
		if(L0==l)
		{
			if(dl&&a.R>b.L)L0+=b.L1;
			else if(!dl&&a.R<b.L)L0+=b.L0;
		}
		if(L1==l)
		{
			if(dl&&a.R<b.L)L1+=b.L0 ; 
			else if(!dl&&a.R>b.L)L1+=b.L1 ; 
		}
		if(R0==r)
		{
			if(dr&&a.R<b.L)R0+=a.R1;
			else if(!dr&&a.R>b.L)R0+=a.R0;
		}
		if(R1==r)
		{
			if(dr&&a.R>b.L)R1+=a.R0;
			else if(!dr&&a.R<b.L)R1+=a.R1 ; 
		}
		ll res=a.res+b.res ; 
		if(a.R>b.L)
		{
			res+=1ll*a.R0*b.L1 ; 
		}
		else if(a.R<b.L)
		{	
			res+=1ll*a.R1*b.L0 ; 
		}
		return {L,R,L0,L1,R0,R1,res} ;
	};
	DL st[8*N] ;
	int sign[8*N] ; 
	ll lazy[8*N] ; 
	void dolazy(int id)
	{
		st[id].L*=sign[id] ;
		st[id].R*=sign[id] ; 
		
		st[id].L+=lazy[id] ; 
		st[id].R+=lazy[id] ; 
		if(sign[id]==-1)swap(st[id].L0,st[id].L1),swap(st[id].R0,st[id].R1); 
		lazy[id*2]*=sign[id] ;
		lazy[id*2+1]*=sign[id] ; 
		sign[id*2]*=sign[id] ; 
		sign[id*2+1]*=sign[id] ; 
		lazy[id*2]+=lazy[id] ;
		lazy[id*2+1]+=lazy[id] ;  
		
		sign[id] =1; 
		lazy[id] = 0 ; 
	}
	void build(int id, int l, int r)
	{
		sign[id] = 1; 
		if(l==r)
		{
		    st[id] = {a[l],a[l],1,1,1,1,1} ;
		    return ; 
		} 
		int mid=(l+r)/2; 
		build(id*2,l,mid); 
		build(id*2+1,mid+1,r) ; 
		st[id] = merge(st[id*2],st[id*2+1],mid-l+1,r-mid) ; 
	}
	void up(int id, int l ,int r ,int t ,int p , int val)
	{
		dolazy(id) ; 
		if(t<=l&&r<=p)
	    {
	    	lazy[id] = val; 
	    	dolazy(id) ; 
		    return ; 
	    }    
	    if(r<t||p<l)return ; 
	    int mid = (l+r)/2 ;
	    up(id*2,l,mid,t,p,val) ; 
	    up(id*2+1,mid+1,r,t,p,val);
	    st[id] = merge(st[id*2],st[id*2+1],mid-l+1,r-mid) ;
	}
	void change(int id ,int l, int r, int t, int p )
	{
		dolazy(id) ;
		if(t<=l&&r<=p)
		{
			sign[id]=-1;
			dolazy(id) ;
			return ; 
		}
		if(r<t||p<l)return ; 
		int mid=(l+r)>>1; 
		change(id*2,l,mid,t,p) ; 
		change(id*2+1,mid+1,r,t,p) ; 
		st[id] =merge(st[id*2],st[id*2+1],mid-l+1,r-mid) ; 
	}
	int giao(int x,int y ,int u ,int v)
	{
		return min(y,v)-max(x,u)+1;
	}
	DL get(int id, int l, int r ,int t, int p)
	{
		dolazy(id) 	; 
	    if(t<=l&&r<=p)return st[id] ;
	    int mid = (l+r)/2 ;
	    if(mid<t)return get(id*2+1,mid+1,r,t,p) ; 
	    if(p<mid+1)return get(id*2,l,mid,t,p) ; 
	    return merge(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p),giao(l,mid,t,p),giao(mid+1,r,t,p)) ;
	} 
	 
	void xuly()
	{
		build(1,1,n) ; 
		// cout<<st[4].res<<" "<<st[4].R0<<" "<<st[4].R1<<el;
		// cout<<st[5].res<<" "<<st[5].R0<<" "<<st[5].R1<<el;
		// cout<<st[2].R0<<" "<<st[2].R1<<" "<<st[2].res<<el;
		// cout<<st[3].L0<<" "<<st[3].L1<<" "<<st[3].res<<el;
		// cout<<st[5].res<<" "<<st[5].R0<<" "<<st[5].R1<<el;
		while(q--)
		{
			char type ;
			cin>>type ;
			if(type=='+')
			{
				int l ,r ,v ;cin>>l>>r>>v ;
				up(1,1,n,l,r,v) ; 
			}
			else if(type=='*')
			{
				int l ,r ; cin>> l >>r ;
				change(1,1,n,l,r) ; 
			}
			else
			{
				int l, r; cin>> l >>r; 
				cout<<get(1,1,n,l,r).res<<el;
			}
			// FOR(i,1,n)cout<<get(1,1,n,i,i).L<<" ";
			// cout<<el;
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
        // sub1::xuly() ; 
        sub2::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}