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

int n ,q ; 

struct DL
{
	int value ; 
	int idx ; 
}a[N];
void doc()
{
    cin>> n  >>q ;
    FOR(i,1,n)
    {
    	cin>>a[i].value ; 
    	a[i].idx=  i ; 
    }
    auto cmp =[](DL a, DL b ){
    	return a.value<b.value||(a.value==b.value&&a.idx<b.idx) ; 
    } ;
    sort(a+1,a+n+1,cmp);
}
int tknp(int value)
{
	int ans = n+1;
	int l = 1 ; 
	int r = n ; 
	while(l<=r)
	{
		int mid  =(l+r)/2 ;
		if(a[mid].value>=value)ans=mid,r=mid-1; 
		else l=mid+1;
	}
	return ans ; 
}
void xuly()
{
	auto  cmp1 = []( int val,DL a )
	{
		return a.value<val   ;
	} ;
	auto cmp2 = [] (int val ,DL a )
	{
		return val<a.value  ;
	};
	FOR(i,1,q)
	{
		int value ; cin>>value ; 
		int pos1 = tknp(value) ; 
		int pos2 = upper_bound(a+1,a+n+1,value,cmp2)-a ; 

		cout<<pos1<<" "<<pos2<<el; 
		cout<<a[pos1].idx<<" "<<a[pos2].idx<<el; 
	}
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