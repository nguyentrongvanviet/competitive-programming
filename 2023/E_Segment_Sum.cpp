/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
***************************************************************/

#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0;

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
#define            tct  template<typename T>
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
const ll inf = 1e18, cs = 331, sm = 998244353; 
const int N = 20+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

str L  ,  R ; 
int k ;	
int digit[N] ;
struct DL
{
	ll sl ; 
	ll sum ;  
} ;
DL f[N][1<<11][2] ; 
ll mu[N] ;
void doc()
{		 
	cin>>L>>R>>k ;
}
void cong(DL&a ,DL b, int c,int len )
{
	(a.sl+=b.sl)%=sm; 
	(a.sum+=(b.sum+c*mu[len]*b.sl%sm)%sm)%=sm; 
}	
DL tinh(int idx , int msk ,int ok )
{
	if(idx==0)
	{
		return {ok,0};
	}
	if( f[idx][msk][ok].sum != -1 )return f[idx][msk][ok] ; 
	DL tmp ={0,0} ;
	FOR(i,0,9)
	{
		int nmsk = (msk|(1<<i)) ;
		if(nmsk==1)msk = 0 ;
		if(btpc(nmsk)>k)continue ; 
		if(ok||(i<digit[idx]))
		{
			cong(tmp,tinh(idx-1,nmsk,1),i,idx-1);
		}
		else if(i==digit[idx]) 
		{
			cong(tmp,tinh(idx-1,nmsk,0),i,idx-1);
		}
	}
	return f[idx][msk][ok]=tmp ; 
}
ll solve(str & S)
{
	int tt =0 ; 
	FORD(i,S.size()-1,0)
	{
		digit[++tt] =S[i]-'0' ;  
	}
	FOR(i,0,tt)FORN(msk,0,1<<10)FOR(ok,0,1)f[i][msk][ok]={-1,-1};
	DL tmp = tinh(tt,0,0) ;
	return tmp.sum; 
}
void xuly()
{
	mu[0] = 1; 
	FOR(i,1,22)mu[i]=mu[i-1]*10%sm ; 
	str val = "1";
	while(R.size()>val.size())val="0"+val;   
	int nho = 0; 
	str ans; 
	FORD(i,R.size()-1,0)
	{
		int c= R[i]+val[i]-2*'0'+nho;
		if(c>=10)nho=1,c-=10; 
		else nho = 0;
		ans=char(c+'0')+ans; 
	}
	if(nho)ans="1"+ans;
	R=ans; 
	ll res= (solve(R)-solve(L)+sm)%sm ;
	cout<<res;
}

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test = 1;
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Khanh An loves you very much !"<<el;
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}