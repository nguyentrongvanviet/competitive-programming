/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "xquery"
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

#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 18 , CH = 26 ; 

int n , q ;

void doc()
{	
	cin>> q ; 
}

namespace sub1
{
    void xuly()
    {
    	multiset<int>S ; 
    	while(q--)
    	{	
    		int TYPE,val ; cin>>TYPE>>val ; 
            if(TYPE==0)
    		{
    			S.insert(val) ; 
    		}
    		else if(TYPE==1)
    		{
    			if(S.count(val))S.erase(S.find(val)) ; 
    		} 
    		else if(TYPE==2)
    		{
                vi q ; 
    			for(auto &v : S)
    			{
                    q.pb(v^val) ; 
    			}
                S.clear() ; 
                for(auto v : q)S.insert(v) ; 
    		}
    		else
    		{
                ll res = 0; 
                for(auto v : S)
                {
                    if(val)res+=v ;
                    else break; 
                    val--; 
                }   
                cout<<res<<el;
    		}
    	}  
    }
}
namespace sub2
{
    int sl[N] ; 
    int tot =  0 ; 
    int node = 1; 
    
    int cnt[N*LO][LO+1] ;
    int f[N*LO] ; 
    int T[N*LO][2] ;

    void up(int val)
    {
        int r = 1; 
        FORD(i,LO,0)
        {
            int c = BIT(val,i) ; 
            if(T[r][c]==0)
            {
                T[r][c]=++node ; 
            }
            r=T[r][c] ; 
            f[r]++ ; 
            FOR(j,0,LO)cnt[r][j]+=BIT(val,j) ; 
        }
    }
    void del(int val)
    {   
        int r = 1; 
        FORD(i,LO,0)
        {
            int c = BIT(val,i) ; 
            r=T[r][c] ; 
            FOR(j,0,LO)cnt[r][j]-=BIT(val,j); 
            f[r]--;
        }
    }
    ll get(int k)
    {
        int r = 1 ; 
        ll res = 0; 
        FORD(i,LO,0)
        { 
            int c = BIT(tot,i);  
            if(f[T[r][c]]>=k)
            {
                r=T[r][c] ; 
            }
            else
            {
                FOR(j,0,LO)
                {
                    int v= T[r][c] ;
                    if(BIT(tot,j))
                    {   
                        res+=1ll*(1<<j)*(f[v]-cnt[v][j]);
                    }   
                    else
                    {
                        res+=1ll*(1<<j)*cnt[v][j];
                    }
                }
                k-=f[T[r][c]] ; 
                r=T[r][c^1] ;
            }
        }
        FOR(j,0,LO)
        {
            if(BIT(tot,j))
            {
                res+=1ll*(1<<j)*min(k,f[r]-cnt[r][j]);
            }
            else
            {
                res+=1ll*(1<<j)*min(k,cnt[r][j]);
            }
        }
        return res ; 
    }
    void xuly()
    {
        multiset<int>s ; 
        while(q--)
        {
            int TYPE , val ; cin>>TYPE>>val;  
            if(TYPE==0)
            {
                val^=tot ;
                s.insert(val) ; 
                up(val) ; 
            }
            else if(TYPE==1)
            {
                val^=tot; 
                if(s.count(val))
                {
                    del(val) ; 
                    s.erase(s.find(val)) ; 
                }
            }   
            else if(TYPE==2)
            {
                tot^=val ; 
            }
            else
            {
                cout<<get(val)<<el;
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
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>test;

    FOR(i,1,test)
    {
        doc() ; 
      	// if(q<=2000)sub1::xuly() ; 
        sub2::xuly() ; 
    } 
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}