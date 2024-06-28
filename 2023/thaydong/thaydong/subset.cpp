/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "subset"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 
#define int long long 
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
#define          SZ(_)  (int)(_.size())
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n; 
ll Left , Right ; 
ll a[N] ;

void doc()
{
    cin>> n >> Left >> Right ;
    FOR(i,1,n)
    {
    	cin>>a[i] ;
    }     

}

namespace sub1
{
	void IN(int msk)
	{
		cout<<btpc(msk)<<el;
		FORN(i,0,n)if(BIT(msk,i))cout<<i+1<<" "; 
		cout<<el; 
		exit(0) ; 
	}
	struct DL
	{
		ll sum ; 
		ll msk ; 
		bool operator<(const DL&a)const
		{
			return sum<a.sum;
		}
	} ;
    void xuly()
    {
    	if(n==1)
    	{
			cout<<1<<el<<1<<el;
    		exit(0);
    	}
    	int mid = n/2 ;
    	ve<DL>L; 
    	FORN(msk,0,(1<<mid))
    	{
    		ll s = 0 ; 
    		for(int MASK = msk ;MASK ; )
    		{
    			int i = __builtin_ctz(MASK ) ; 
    			s+=a[i+1] ;
    			MASK^=(1<<i) ;
    		}
    		if(Left<=s&&s<=Right)IN(msk) ; 
    		L.pb({s,msk});
    	}
    	sort(all(L)) ; 
		
		ve<DL>R; 
    	FORN(msk,0,1<<(n-mid))
    	{
    		ll s= 0 ; 
    		for(int MASK = msk ; MASK;)
    		{
    			int i = __builtin_ctz(MASK) ; 
    			s+=a[i+mid+1] ;
    			MASK^=(1<<i) ;
    		}
    		if(Left<=s&&s<=Right)IN(msk<<mid) ; 
    		R.pb({s,msk}) ; 
    	}
    	sort(all(R)) ; 
    	int it = SZ(R)-1 ;
    	for(auto u : L)
    	{
    		int t = LB(all(R),Left-u.sum,[](DL a, ll val){return a.sum<val;})-R.begin();
    		if(t<SZ(R)&&u.sum+R[t].sum<=Right)
    		{
    			IN(u.msk|(R[t].msk<<mid));
    		}
    	}
    	for(auto u : L)
    	{
    		while(it>=0&&u.sum+R[it].sum>=Left)--it; 
    		if(it!=SZ(R)-1&&u.sum+R[it+1].sum>=Left&&u.sum+R[it+1].sum<=Right)
    		{
    			IN(u.msk|(R[it+1].msk<<mid));
    		}
    	}	
    }
}
namespace subtrau
{   	
	int f[85][200005],pre[85][20005] ; 
	void trace(int id , int sum)
	{
		vi res; 
		while(sum)
		{
			int nsum = pre[id][sum] ; 
			if(sum!=nsum)
			{
				res.pb(id-1) ; 
			}
			sum=nsum ; 
			--id ;
		}
		cout<<SZ(res)<<el; 
		reverse(all(res)) ;
		prv(res) ; 
		exit(0) ;
	}
	void tinh(int id , int sum)
	{
		if(sum>Right||id>n)return ; 
		if(Left<=sum&&sum<=Right)
		{
			trace(id,sum) ; 
		}
		if(f[id][sum]==0)return ; 
		pre[id+1][sum] = sum ; 
		tinh(id+1,sum); 
		pre[id+1][sum+a[id]] = sum ; 
		tinh(id+1,sum+a[id]) ;
		f[id][sum ] = 0 ;  
	}
    void xuly()
    {   
    	FOR(i,1,n)mini(a[i],Right+1) ;
    	memset(f,-1,sizeof(f)) ; 
    	tinh(1,0);
    }
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/
bool check()
{
	FOR(i,1,n)
	{
		if(a[i]!=i)return 0 ; 
	}
	return 1; 
}
namespace last
{
	struct DL
	{
		int val , id;  
		bool operator<(const DL&a)const
		{
			return val<a.val ; 
		}
	} ; 
	DL tmp[N] ;
	ll s[N] ; 
	void IN(int l ,int r)
	{
		cout<<r-l+1<<el;
		FOR(i,l,r)cout<<tmp[i].id<<" ";
		cout<<el;
		exit(0); 
	} 
	void solve(int idx)
	{
		FOR(i,idx+1,n)
		{
			ll sum = s[i]-s[i-idx] ; 
			if(Left<=sum&&sum<=Right)
			{
				IN(i-idx+1,i) ; 
			}
		}
	}	
	void xuly()
	{
		FOR(i,1,n)
		{	
			tmp[i]=  {a[i],i} ; 
		}
		sort(tmp+1,tmp+n+1) ; 
		FOR(i,1,n)
		{
			s[i] = s[i-1]+tmp[i].val; 
		}
		FOR(i,1,n)
		{
			if(s[i]>=Left&&s[i]<=Right)IN(1,i) ; 
			if(Left<=s[n]-s[n-i]&&s[n]-s[n-i]<=Right)IN(n-i+1,n) ; 
			if(s[i]<Left&&s[n]-s[n-i]>Right)
			{
				solve(i) ; 				
			}
		}
	}
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ;
        if(*min_element(a+1,a+n+1)==*max_element(a+1,a+n+1))
        {
        	ll sum =0;
        	vi res ; 
        	FOR(i,1,n)
        	{
        		if(sum>=Left)break;
        		res.pb(i) ;
        		sum+=a[i] ;
        	}
        	cout<<SZ(res)<<el; 
        	prv(res) ; 
        	exit(0) ; 
        }
        if(n<=40)sub1::xuly()  ;  
        else 
        if(n<=80&&Right<=(int)1e5)
        {
        	subtrau::xuly() ; 
        }
        else if(check())
        {
        	vi res ; 
        	FORD(i,n,1)
        	{
        		if(Left>=i)Left-=i,res.pb(i) ; 
        	}
        	cout<<SZ(res)<<el; 
        	reverse(all(res)) ; 
        	prv(res) ;
        }
        else
        {
        	last::xuly() ; 
        }
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}