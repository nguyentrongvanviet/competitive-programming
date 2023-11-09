/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
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
#define            tct  template<class T>
#define             LB  lower_bound
#define             UB  upper_bound 
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
const int N = 2e5+5, oo = 2e9, LO = 17, CH = 26 ; 

int n  ; 
str S ; 
int s[N] ;
void doc()
{
	cin>> n ; 
	cin>>S ; 
	FORN(i,0,S.size())
	{
		s[i] = S[i]-'0' ; 
	}
}
namespace sub1
{
	int go[N][2] ; 
	int kmp[N] ; 
	void build_edge()
	{
		int len = S.size(); 
		FORN(i,1,len)
		{	
			int j = kmp[i-1] ; 
			while(j&&s[i]!=s[j])
			{
				j=kmp[j-1] ; 
			}
			if(s[i]==s[j])++j ; 
			kmp[i] = j ; 
		}
		go[0][s[0]]=1 ; 
		FOR(i,1,len-1)
		{
			FOR(c,0,1)
			{
				if(c==s[i])
				{
					go[i][c]=i+1; 
				}
				else
				{
					int j= kmp[i-1] ; 
					while(j&&c!=s[j])
					{
						j=kmp[j-1] ; 
					}
					if(c==s[j])++j;
					go[i][c]=j;
				}
			}
		}
		go[len][0]=go[len][1] = len ; 
	}
	ll f[(int)1e5+5][100];
	ll tinh(int idx, int len)
	{
		if(idx==n+1)
		{
			return len==(int)S.size() ; 
		}
		if(f[idx][len]!=-1)return f[idx][len] ; 
		return f[idx][len] = (tinh(idx+1,go[len][1])+tinh(idx+1,go[len][0]))%sm ;
	}
	ll pw(ll a, ll n)
	{
		if(n==0) return 1;   
		ll b = pw(a,n/2); 
		if(n&1)return b*b%sm*a%sm;  	
		return b*b%sm ;
	}
    void xuly()
    {		
        build_edge() ; 
    	FOR(i,1,n)FOR(j,0,S.size())f[i][j] =-1 ; 
    	cout<<(pw(2,n)-tinh(1,0)+sm)%sm<<el;
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}