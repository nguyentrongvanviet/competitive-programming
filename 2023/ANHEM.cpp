/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
*code for dream,code for Truong Thi My Duyen :) yeu nhieu lam !*
***************************************************************/

#define TASK "ANHEM"
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
const ll inf = 1e17, cs = 330, sm = 1e18; 
const int N = 2e5+5, oo = 2e9, LO = 17; 


int a[20] ;
ll f[20][165][1500][2] ;  
ll L , R ;
int nt[1500] ; 
void thieve(int N )
{	
	nt[0] = -1 ; 
	nt[1] = -1 ; 
	for(ll i =2;i<=N;i++)
	{
		if(nt[i]==0)
		{
			nt[i] = i;  
			for(ll j = i*i;j<=N;j+=i)
			{
				nt[j] = i;  
			}
		}
	}
}
void doc()
{
	cin>>L>>R ; 
}
ll tinh(int idx , int sum ,int sum_mu , int ok)
{
	if(f[idx][sum][sum_mu][ok]!=-1)return f[idx][sum][sum_mu][ok] ; 
	if(idx==0)
	{
		return f[idx][sum][sum_mu][ok] = (nt[sum]==sum && nt[sum_mu]==sum_mu) ;
	}
	ll tmp = 0 ; 
	if(ok==1)
	{
		FOR(c,0,9)
		{
			int nsum = sum+c; 
			int nsum_mu = sum_mu + sq(c)  ; 
			tmp+=tinh(idx-1,nsum,nsum_mu,1);
		}	
	}
	else
	{
		FOR(c,0,a[idx]-1)
		{
			int nsum = sum+c; 
			int nsum_mu = sum_mu + sq(c)  ; 
			(tmp+=tinh(idx-1,nsum,nsum_mu,1))%=sm ;
		}	
		tmp+=tinh(idx-1,sum+a[idx],sum_mu+sq(a[idx]),0);  
	}
	return f[idx][sum][sum_mu][ok]=tmp ; 
}
ll cal(ll L)
{
	FOR(i,1,19)
	{
		a[i] = L%10 ;
		L/=10 ;  
	}
	FOR(i,0,19)
	FOR(sum,0,162)
	FOR(sum_mu,0,1458)
	FOR(ok,0,1)f[i][sum][sum_mu][ok]=-1 ;
	return tinh(19,0,0,0);  
}
void xuly()
{
	thieve(1458) ;
	cout<<cal(R)-cal(L-1)<<el; 
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