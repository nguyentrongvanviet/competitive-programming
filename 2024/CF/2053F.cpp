/*
Name   :   Nguyen Trong Van Viet
Age    :   18                              
School :   VNUHCM - University Of Science                                 
*/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

#include<bits/stdc++.h>
using namespace std; 

typedef long long ll ;
typedef double db ; 
typedef string str ; 
typedef vector<int> vi ;
typedef vector<ll> vll ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ; 
#define ve vector 
#define pb push_back
#define pk pop_back
#define el '\n'
#define mp make_pair 
#define fi first 
#define se second
#define uni(a) a.resize(unique(all(a))-a.begin()) 
#define FOR(i,a,b) for(int i=(int  )(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end()  
#define btpc __builtin_popcountll
#define LB lower_bound
#define UB upper_bound 
#define BIT(msk,i) ((msk)>>(i)&1)
#define MSK(i) (1ll<<(i))
#define tct template<class T>
tct T sq(T a){return a*a;}  
ll lg(ll a){return __lg(a);}
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
tct void prt(T a[],int n){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a){for(auto v:a)cout<<v<<" "; cout<<el;} 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}


int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};


const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m ,  color ; 
map<int,ll>sl[N] ;
ll cnt[N] ;
ll st[int(24e5)] ;
ll lazy_ma[int(24e5)] , lazy_inc[int(24e5)] ;
void dolazy_inc(int id , ll inc)
{		
	lazy_ma[id]+=inc ; 
	lazy_inc[id]+=inc ; 
}
void dolazy_ma(int id ,ll ma)
{
	maxi(lazy_ma[id],ma) ; 
}
void dolazy(int id, int l ,int r)
{
	st[id]+=lazy_inc[id] ; 

	if(l<r)
	{
		dolazy_inc(id<<1,lazy_inc[id]) ;
		dolazy_ma(id<<1,lazy_ma[id]) ;  		
		dolazy_inc(id<<1|1,lazy_inc[id]) ; 
		dolazy_ma(id<<1|1,lazy_ma[id]) ; 
	}
	maxi(st[id],lazy_ma[id]) ; 
	lazy_inc[id] = lazy_ma[id] = 0 ; 

}
void inc(int id ,int l ,int r ,int t ,int p, ll val )
{
	dolazy(id,l,r); 
	if(t<=l&&r<=p)
	{
		lazy_inc[id] = val;  
		dolazy(id,l,r) ; 
		return ; 
	}
	if(r<t||p<l)return ; 
	int mid = (l+r)>>1 ; 
	inc(id<<1,l,mid,t,p,val) ; 
	inc(id<<1|1,mid+1,r,t,p,val) ; 
	st[id] =  max(st[id<<1],st[id<<1|1]) ; 
}
void up_ma(int id, int l ,int r , int t , int p , ll val )
{
	dolazy(id,l,r) ; 
	if(t<=l&&r<=p)
	{
		lazy_ma[id] = val; 
		dolazy(id,l,r) ; 
		return ; 
	}
	if(r<t||p<l)return ;  
	int mid = (l+r)>>1 ; 
	up_ma(id<<1,l,mid,t,p,val) ; 
	up_ma(id<<1|1,mid+1,r,t,p,val) ; 
	st[id] = max(st[id<<1],st[id<<1|1]) ; 
}
ll get(int id ,int l ,int r ,int pos )
{ 
	dolazy(id,l,r) ; 
	if(l==r&&l==pos)return st[id]  ; 
	if(r<pos||pos<l)return 0 ; 
	int mid = (l+r)>>1 ; 
	return max(get(id<<1,l,mid,pos),get(id<<1|1,mid+1,r,pos)) ; 
}
ll get(int pos)
{
	return get(1,1,color,pos); 
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    
    if(fopen(INPUT,"r")){
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ; 
    }
    int test ; cin>>test ; 
    while(test--)
    {
    	cin>> n >> m >> color ; 
    	FOR(i,1,n)
    	{
    		FOR(j,1,m)
    		{
    			int num ; cin>>num ; 
    			if(num==-1)
    			{
    				cnt[i]++ ; 
    			}
    			else
    			{
    				sl[i][num]++;
    			}
    		}
    	}
    	ll beg = 0 ; 
    	FOR(i,1,n)
    	{
    		for(auto [x,y]:sl[i])
    		{
    			beg += y*(sl[i-1].count(x)?sl[i-1][x]:0); 
    		}
    	}
    	FOR(i,2,n)
    	{
    		//j==k ; 

    		map<int,ll>f ;
    		for(auto [j,x]:sl[i-1])
    		{
    			ll d = (sl[i].count(j)?sl[i][j]:0) ; 
    			ll val = get(j)+(x+cnt[i-1])*(d+cnt[i])-x*d;
    			maxi(f[j],val) ; 
    		}
    		for(auto [j,x]:sl[i])
    		{
    			int d = (sl[i-1].count(j)?sl[i-1][j]:0) ; 
    			ll val = get(j)+(x+cnt[i])*(d+cnt[i-1])-x*d ;
    			maxi(f[j],val) ; 
    		}
    		// j!=k 
    		ll D = st[1] ; 
			// k in i 
			for(auto [k,x]:sl[i])
			{	
				ll val = get(k)+x*cnt[i-1] ; 
				maxi(D,val) ; 
			}
    		// j in i-1  
			for(auto [j,x]:sl[i-1])
			{
				ll val = x*cnt[i]+D ; 
				maxi(f[j],val) ; 
			}
			//j not in i-1 
			inc(1,1,color,1,color,cnt[i]*cnt[i-1]) ; 
    		up_ma(1,1,color,1,color,D) ; 
			for(auto [x,y] : f)
			{
				up_ma(1,1,color,x,x,y) ; 
			}
    	}
    	cout<<beg+st[1]<<el;
    	FOR(i,1,4*color)
    	{
    		st[i] = lazy_inc[i]=lazy_ma[i] =  0 ; 
    	}
    	FOR(i,1,n)
    	{
    		sl[i].clear() ; 
    		cnt[i] = 0  ; 
    	}
    }



    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



