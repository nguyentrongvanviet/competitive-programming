/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
*code for dream,code for Truong Thi My Duyen :) yeu nhieu lam !*
***************************************************************/

#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool multitest = 0;

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
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define    FORN(i,a,b)  for(int i=(int)(a);i<(int)(b);i++)
#define         all(a)  a.begin(),a.end()  
#define           btpc  __builtin_popcountll       
#define            tct  template<typename T>

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
// end of template
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const int N = 2e5+5, oo = 2e9, LO = 17; 

int  m , n ; 
str S ; 
int kmp[N] ; 
vi len ;
ll f[N] ;  
void doc()
{
    cin>> m >> n ; 
    cin>>S ; 
    FORN(i,1,m)
    {
    	int j= kmp[i-1] ; 
    	while(j&&S[j]!=S[i])
    	{
    		j=kmp[j-1] ; 
    	}
    	if(S[j]==S[i])j++;
    	kmp[i] = j ; 
    }
    FORN(i,0,m)
    {
    	if(kmp[i]==0)len.pb(i+1) ; 
    }
    // for(auto v: len)cout<<v<<" ";cout<<el;
    n-=m ;
    f[0] = 1;  
    FOR(i,1,n)
    {	
    	for(auto v: len)
    	{
    		if(i<v)break; 
    		f[i] =  (f[i]+f[i-v])%sm; 
    	}
    }
    cout<<f[n] ; 
}

void xuly()
{
    
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test = 1;
    if(multitest)cin>>test ;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Duyen yeu Viet nhieu lam ! "<<el<<"Time elapsed : " << clock() <<"ms"<<el;
}