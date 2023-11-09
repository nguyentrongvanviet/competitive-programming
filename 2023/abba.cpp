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

#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 
 
int n;  
str KA,S ; 
ll mu[N] ; 
void doc()
{
	cin>>KA>> S ;
}

namespace sub1
{
	char a[3][N] ; 
	ll ha[3][N] ;
	int f[N][N][2]; 

	ll get_hash(int l ,int r , int TYPE)
	{
		return (ha[TYPE][r]-ha[TYPE][l-1]*mu[r-l+1]%sm+sm)%sm;
	}
	int tinh(int l ,int r ,int TYPE)
	{
		if(f[l][r][TYPE]!=-1)return f[l][r][TYPE]; 
		if(r==n)
		{
			if(l==1)return f[l][r][TYPE] =1 ; 
			else return f[l][r][TYPE] = 0 ;
		}
		if(a[TYPE][r+1]=='A')
		{
			return f[l][r][TYPE] = tinh(l,r+1,TYPE) ; 
		}
		return f[l][r][TYPE] = tinh(n-r,n-l+1,3-TYPE) ; 
	}
    void xuly()
    {
    	if(KA.size()>S.size())return void(cout<<"No"<<el) ;
		n = S.size() ; 
		int TYPE = 0 ; 
		FOR(i,1,n)
		{
			a[1][i] = S[i-1]; 
			a[2][n-i+1] = S[i-1] ;
			TYPE+=(a[1][i]=='B');
		}
		FOR(j,1,2)
		{
			FOR(i,1,n)
			{
				ha[j][i] = (ha[j][i-1]*cs+a[j][i])%sm;
			}
		}	
    	ll hash = 0 ; 
    	for(auto v: KA)
    	{
    		TYPE+=(v=='B') ; 
    		hash=(hash*cs+v)%sm;
    	}
    	FOR(i,1,n)FOR(j,i,n)FOR(TYPE,1,2)f[i][j][TYPE] = -1 ; 
    	TYPE%=2 ; 
    	TYPE++;
    	FOR(i,1,n-KA.size()+1)
    	{
    		if(hash==get_hash(i,i+KA.size()-1,TYPE)&&tinh(i,i+KA.size()-1,TYPE))
    		{
    			return void(cout<<"Yes"<<el); 
    		}
    	}
    	cout<<"No"<<el;
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
    test = 3 ;
    mu[0] =1 ; 
    FOR(i,1,1e3)mu[i] = mu[i-1]*cs%sm; 
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}