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

string s[N] ; 
ll mu[N] ; 
ll ha[N] ;
int sa[N] ; 
int sum[N]  ; 
int suf[N] , pre[N] ;
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
    string t ; cin>> t;
    int m = t.size() ; 
    t="#"+t ;
    mu[0] = 1 ; 
    FOR(i,1,m)
    {
    	mu[i] = mu[i-1]*cs%sm; 
    } 
    auto get_hash=[&](int l ,int r ){return (ha[r]-ha[l-1]*mu[r-l+1]%sm+sm)%sm;};
    FOR(i,1,m)
    {
    	ha[i] = (ha[i-1]*cs+t[i])%sm;
    } 
    int n ; cin>> n; 
    FOR(i,1,n)
    {
    	cin>>s[i] ;
    }
    FOR(i,1,m)sa[i] = i ; 
    sort(sa+1,sa+m+1,[&](int i ,int j ){
    	int l = 0 ; 
    	int r = m-max(i,j);
    	int ans = -1 ; 
    	while(l<=r)
    	{
    		int mid = (l+r)>>1 ; 
    		if(get_hash(i,i+mid)!=get_hash(j,j+mid))
    		{
    			ans=mid ;
    			r=mid-1 ; 
    		}
    		else l=mid+1 ;
    	}
    	if(ans==-1)
    	{
    		return i>j ; 
    	}
    	return t[i+ans]<t[j+ans] ; 
    });
    // FOR(i,1,m)
    // {
    // 	cout<<t.substr(sa[i])<<el;
    // }
    FOR(i,1,n)
    {
    	str tmp = s[i] ; 
    	int l = 1 ;  
    	int r = m ; 
    	int L = m+1 ; 
    	while(l<=r)
    	{	
    		int mid = (l+r)>>1 ; 
    		int id = sa[mid] ; 
    		for(int x=0,y=id;x<int(tmp.size())&&y<=m;x++,y++)
    		{
    			if(tmp[x]==t[y])
    			{
    				if(x==int(tmp.size()-1))
    				{
    					L=mid ; 
    					r=mid-1 ; 
    				}	
    				else if(y==m)
    				{
    					l=mid+1; 
    				}
    				else continue ;
    			}
    			if(tmp[x]<t[y])
    			{
    				r=mid-1 ;
    				break;
    			}
    			else if(tmp[x]>t[y])
    			{
    				l=mid+1 ;
    				break; 
    			}
    		}
    	} 
    	l=L ;
    	r=m ; 
    	int R = m+1 ; 
    	while(l<=r)
    	{	
    		int mid = (l+r)>>1 ; 
    		int id = sa[mid] ; 
    		for(int x=0,y=id;x<int(tmp.size())&&y<=m;x++,y++)
    		{
    			if(tmp[x]==t[y])
    			{
    				if(x==int(tmp.size()-1))
    				{
    					R=mid ; 
    					l=mid+1 ;  
    				}	
    				else if(y==m)
    				{
    					r=mid-1 ; 
    				}
    				else continue ;
    			}
    			if(tmp[x]<t[y])
    			{
    				r=mid-1 ;
    				break;
    			}
    			else if(tmp[x]>t[y])
    			{
    				l=mid+1 ;
    				break; 
    			}
    		}
    	}
    	sum[L]++ ; 
    	sum[R+1]-- ;
    	// cout<<L<<" "<<R<<el;
    }	
    FOR(i,1,m)
    {
    	sum[i]+=sum[i-1] ; 
    	suf[sa[i]] = sum[i] ; 
    }
    t.erase(0,1) ; 
    FOR(i,1,m)sum[i] = 0 ; 
    reverse(all(t)) ;
    t="#"+t ; 
    FOR(i,1,m)ha[i]=(ha[i-1]*cs+t[i])%sm;
    FOR(i,1,n)reverse(all(s[i])) ; 
     FOR(i,1,m)sa[i] = i ; 
    sort(sa+1,sa+m+1,[&](int i ,int j ){
    	int l = 0 ; 
    	int r = m-max(i,j);
    	int ans = -1 ; 
    	while(l<=r)
    	{
    		int mid = (l+r)>>1 ; 
    		if(get_hash(i,i+mid)!=get_hash(j,j+mid))
    		{
    			ans=mid ;
    			r=mid-1 ; 
    		}
    		else l=mid+1 ;
    	}
    	if(ans==-1)
    	{
    		return i>j ; 
    	}
    	return t[i+ans]<t[j+ans] ; 
    });
    
    FOR(i,1,n)
    {
    	str tmp = s[i] ; 
    	int l = 1 ;  
    	int r = m ; 
    	int L = m+1 ; 
    	while(l<=r)
    	{	
    		int mid = (l+r)>>1 ; 
    		int id = sa[mid] ; 
    		for(int x=0,y=id;x<int(tmp.size())&&y<=m;x++,y++)
    		{
    			if(tmp[x]==t[y])
    			{
    				if(x==int(tmp.size()-1))
    				{
    					L=mid ; 
    					r=mid-1 ; 
    				}	
    				else if(y==m)
    				{
    					l=mid+1; 
    				}
    				else continue ;
    			}
    			if(tmp[x]<t[y])
    			{
    				r=mid-1 ;
    				break;
    			}
    			else if(tmp[x]>t[y])
    			{
    				l=mid+1 ;
    				break; 
    			}
    		}
    	} 
    	l=L ;
    	r=m ; 
    	int R = m+1 ; 
    	while(l<=r)
    	{	
    		int mid = (l+r)>>1 ; 
    		int id = sa[mid] ; 
    		for(int x=0,y=id;x<int(tmp.size())&&y<=m;x++,y++)
    		{
    			if(tmp[x]==t[y])
    			{
    				if(x==int(tmp.size()-1))
    				{
    					R=mid ; 
    					l=mid+1 ;  
    				}	
    				else if(y==m)
    				{
    					r=mid-1 ; 
    				}
    				else continue ;
    			}
    			if(tmp[x]<t[y])
    			{
    				r=mid-1 ;
    				break;
    			}
    			else if(tmp[x]>t[y])
    			{
    				l=mid+1 ;
    				break; 
    			}
    		}
    	}
    	sum[L]++ ; 
    	sum[R+1]-- ;
    }	
    FOR(i,1,m)
    {
    	sum[i]+=sum[i-1] ; 
    	pre[m-sa[i]+1] = sum[i] ; 
    }
    ll res = 0 ; 
    FOR(i,2,m)
    {
    	res+=1ll*pre[i-1]*suf[i] ;
    }
    cout<<res<<el;
    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



