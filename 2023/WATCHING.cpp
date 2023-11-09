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

int n  , m  ; 
ll T  , k;  
ll a[N] , b[N] ; 
ll A = 0 ,B = 0 ; 
void doc()
{
    cin>> n >> m >> T >> k ;
    FOR(i,1,n)cin>>a[i],mini(a[i],T) ; 
    FOR(i,1,m)cin>>b[i],mini(b[i],T) ; 
    a[n+1]= T ; 
    b[m+1]= T ; 
}

void xuly()
{ 
	int turn = 1 ; 
	ll Time = 0 ;
	int id1 =1 , id2=1 	;  
	while(Time<T)
	{
		if(turn==1)
		{
			while(a[id1]<=Time)++id1;
			if(id1-1>=1&&a[id1-1]+k>=Time)
			{
				if(a[id1-1]+k>=T)break; 
				A+=a[id1]-(a[id1-1]+k);
			}else A+=a[id1]-Time ; 
			Time = a[id1] ; 
		}
		else
		{
			while(b[id2]<=Time)++id2;
			if(id2-1>=1&&b[id2-1]+k>=Time)
			{
				if(b[id2-1]+k>=T)break; 
				B+=b[id2]-(b[id2-1]+k);
			}
			else B+=b[id2]-Time;
			Time = b[id2] ;   
		}
		turn = 1-turn ; 
	}
	cout<<A<<" "<< B ; 
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