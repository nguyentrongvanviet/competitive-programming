/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "LQUERY"
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
const int N = 5e5+5 , oo = 2e9 , LO = 18 , CH = 26 ; 


int n, q; 
struct Query
{
	int type , l ,r , val; 
}Q[N] ;
int a[N] ; 
void doc()
{
    cin>> n >>q ;
    FOR(i,1,n)cin>>a[i] ; 
    FOR(i,1,q)
    {
    	int type , l, r, val; 
    	cin>>type ;
    	if(type==1)cin>>val;  
    	if(type==2){}
    	if(type==3)cin>>val; 
    	if(type>3)cin>>l>>r>>val; 
    	Q[i] = {type,l,r,val} ;
    }
}

namespace sub2
{
	const int N = 1e6+5 ; 
	struct node
	{
		node *child[2]; 
		int cnt =0 ;
	} ;
	node* H[N] ;
	int sum_xor = 0 ;
	node* up(node* old , int val)
	{
		node* cur = new node() ; 
		node* tmp = cur; 
		FORD(i,LO,0)
		{
			int j=BIT(val,i) ; 
			cur->child[j] = new node() ; 
			if(old)cur->child[j^1]=old->child[j^1];
			cur=cur->child[j] ; 
			if(old)old=old->child[j] ;
			cur->cnt = 1 +(old?old->cnt:0) ;
		}
		return tmp ; 
	}		
	int MAX(int l ,int r, int val)
	{
		int ans = 0 ; 
		node* cur = H[r] ;
		node* pre = H[l-1] ;
		FORD(i,LO,0)
		{	
			int j = BIT(val,i) ;
			int now = (cur->child[j^1]?cur->child[j^1]->cnt:0) ;
			int pas = (pre&&pre->child[j^1]?pre->child[j^1]->cnt:0) ;
			if(now-pas)
			{
				ans|=M(i) ;
				cur = cur->child[j^1] ;
				if(pre)pre = pre->child[j^1] ;
			}
			else
			{
				cur = cur->child[j] ; 
				if(pre)pre = pre->child[j] ; 
			}
		}
		return ans; 
	}
	int COUNT(int r ,int val)
	{
		int ans = 0 ; 
		node* cur = H[r];
		FORD(i,LO,0)
		{
			if(cur==0)break;
			int j = BIT(sum_xor,i) ; 
			if(BIT(val,i))
			{
				ans+=(cur->child[j]?cur->child[j]->cnt:0) ; 
				cur=cur->child[j^1];
			}	
			else
			{
				cur=cur->child[j] ;
			}
		}
		ans+=(cur?cur->cnt:0) ;
		return ans; 
	}
	int KTH(int l, int r ,int val)
	{
		int ans = 0; 
		node* cur = H[r] ;
		node* pre = H[l-1] ;
		FORD(i,LO,0)
		{
			if(!cur)break;
			int j = BIT(sum_xor,i) ;
			int now = (cur->child[j]?cur->child[j]->cnt:0) ;
			int pas = (pre && pre->child[j]?pre->child[j]->cnt:0) ; 
			if(now-pas>=val)
			{
				cur=cur->child[j] ;  
				if(pre)pre=pre->child[j] ;
			}
			else
			{
				val-=now-pas;
				ans|=M(i) ;
				cur=cur->child[j^1] ;
				if(pre)pre=pre->child[j^1] ;
			}
		}
		return ans; 
	}
	void xuly()
	{
		int cur = 0 ; 
		FOR(i,1,n)
		{
			++cur; 
			H[cur] = up(H[cur-1],a[i]) ; 
		}
		FOR(i,1,q)
		{
			int T = Q[i].type ; 
			int l= Q[i].l; 
			int r =Q[i].r ;
			int val =Q[i].val; 
			if(T==1)
			{	
				++cur; 
				val^=sum_xor ; 
				H[cur] = up(H[cur-1],val) ; 
			}
			else if(T==2)
			{
				--cur; 
			}
			else if(T==3)
			{
				sum_xor^=val; 
			}
			else if(T==4)
			{
				val^=sum_xor ;
				cout<<MAX(l,r,val)<<el;
			}
			else if(T==5)
			{
				cout<<COUNT(r,val) - COUNT(l-1,val)<<el;
			}
			else if(T==6)
			{
				cout<<KTH(l,r,val)<<el;
			}
		}
	}
}
namespace sub3
{
	const int N = 1e6+5 ; 
	int H[N] ;
	int T[N*LO][2] ;
	int cnt[N*LO] ;
	int sum_xor = 0 ;
	int node = 0 ;
	int up(int old , int val)
	{
		int cur = ++node;  
		int r= cur ;
		FORD(i,LO,0)
		{
			int j=BIT(val,i) ; 
			if(T[r][j]==0)T[r][j] = ++node; 
			T[r][j^1] = T[old][j^1];
			r=T[r][j] ; 
			old=T[old][j] ; 
			cnt[r] = cnt[old] + 1 ; 
		}
		return cur ;
	}		
	int MAX(int l ,int r, int val)
	{
		int ans = 0 ; 
		int cur = H[r] ; 
		int pre = H[l-1] ; 
		FORD(i,LO,0)
		{	
			int j = BIT(val,i) ;
			int now = cnt[T[cur][j^1]] ;
			int pas = cnt[T[pre][j^1]] ; 
			if(now-pas)
			{
				ans|=M(i) ;
				cur = T[cur][j^1] ;
				pre = T[pre][j^1] ; 
			}
			else
			{
				cur = T[cur][j] ; 
				pre = T[pre][j] ; 
			}
		}
		return ans; 
	}
	int COUNT(int r ,int val)
	{
		int ans = 0 ; 
		int cur = H[r] ;
		FORD(i,LO,0)
		{
			if(cur==0)break;
			int j = BIT(sum_xor,i) ; 
			if(BIT(val,i))
			{
				ans+=cnt[T[cur][j]]; 
				cur=T[cur][j^1];
			}	
			else
			{
				cur=T[cur][j] ;
			}
		}
		ans+=cnt[cur] ; 
		return ans; 
	}
	int KTH(int l, int r ,int val)
	{
		int ans = 0; 
		int cur = H[r] ;
		int pre = H[l-1] ; 
		FORD(i,LO,0)
		{
			int j = BIT(sum_xor,i) ;
			int now = cnt[T[cur][j]] ; 
			int pas = cnt[T[pre][j]]; 
			if(now-pas>=val)
			{
				cur=T[cur][j] ;  
				pre=T[pre][j] ; 
			}
			else
			{
				val-=now-pas;
				ans|=M(i) ;
				cur=T[cur][j^1] ;
				pre=T[pre][j^1] ; 
			}
		}
		return ans; 
	}
	void xuly()
	{
		int cur = 0 ; 
		FOR(i,1,n)
		{
			++cur; 
			H[cur] = up(H[cur-1],a[i]) ; 
		}
		FOR(i,1,q)
		{
			int T = Q[i].type ; 
			int l= Q[i].l; 
			int r =Q[i].r ;
			int val =Q[i].val; 
			if(T==1)
			{	
				++cur; 
				val^=sum_xor ; 
				H[cur] = up(H[cur-1],val) ; 
			}
			else if(T==2)
			{
				--cur; 
			}
			else if(T==3)
			{
				sum_xor^=val; 
			}
			else if(T==4)
			{
				val^=sum_xor ;
				cout<<MAX(l,r,val)<<el;
			}
			else if(T==5)
			{
				cout<<COUNT(r,val) - COUNT(l-1,val)<<el;
			}
			else if(T==6)
			{
				cout<<KTH(l,r,val)<<el;
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
        // sub1::xuly() ; 
        // sub2::xuly() ;
        sub3::xuly();
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}