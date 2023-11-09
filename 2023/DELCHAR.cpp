/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
***************************************************************/

#define TASK "DELCHAR"
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
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 3e2+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n;  
str S ; 
int a[N] ; 
ve<char>D = {'(','[','{','=','}',']',')'} ; 
void doc()
{
	cin>>S ; 
	n=S.size() ; 
	S="%"+S ;
	FOR(i,1,n)
	{
		FORN(j,0,7)if(S[i]==D[j])a[i]=j-3 ; 
	} 	
}
int f[N][N] ;
void xuly()
{
	FOR(i,1,n)FOR(j,i,n)
	{
		f[i][j] = oo ; 
	}
	FOR(i,1,n)f[i][i]=1 ; 
	FOR(len,2,n)
	{
		FOR(i,1,n-len+1)
		{
			int j= i+len-1 ;
			f[i][j] = f[i+1][j-1]+2;   
			FOR(ii,i,j)
			{
				if(a[i]<0&&a[i]+a[ii]==0)mini(f[i][j],f[i+1][ii-1]+f[ii+1][j]) ; 
			}
			FOR(jj,i,j)
			{
				if(a[jj]<0&&a[jj]+a[j]==0)mini(f[i][j],f[i][jj-1]+f[jj+1][j-1]) ; 
			}
		}
	}
	cout<<f[1][n]; 
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