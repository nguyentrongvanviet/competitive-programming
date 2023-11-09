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

str S ; 
int n ; 
ll mu[N] , ha[N] ; 
int sa[N] ; 
ll get_hash(int l, int r , ll ha[])
{
	return (ha[r]-ha[l-1]*mu[r-l+1]+sm*sm)%sm;
}
void doc()
{
   	cin>>S ; 
   	n=S.size() ; 
   	S=" "+S ;
}

void xuly()
{
   	mu[0] = 1 ; 
   	FOR(i,1,n)ha[i] = (ha[i-1]*cs+S[i])%sm , mu[i]=mu[i-1]*cs%sm; 
   	FOR(i,1,n)sa[i] = i ; 
   	sort(sa+1,sa+n+1,

   		[](int i , int j )
   		{	
   			int l = 0 ; 
   			int r = min(n-i,n-j) ; 
   			int ans = -1 ;
   			while(l<=r)
   			{
   				int mid =(l+r)/2; 
   				if(get_hash(i,i+mid,ha)!=get_hash(j,j+mid,ha))
   				{
   					ans = mid ; 
   					r = mid-1 ; 
   				}
   				else l = mid+1 ; 
   			}
   			if(ans==-1)return i>j;
   			return S[i+ans]<S[j+ans];
   		}
   	); 
   	// prt(sa,n); 
   	// FOR(i,1,n)cout<<S.substr(sa[i])<<el;
   	int q; cin>>q; 
   	while(q--)
   	{
   		str s  ; cin>>s ; 
   		int m  = s.size() ; 
   		s=" "+s ; 
   		bool ok = 0; 
   		int l = 1 ;
   		int r = n ; 
   		while(l<=r)
   		{
   			int mid=(l+r)/2; 
   			for(int i=1 , j = sa[mid] ; i<=m && j<=n ;i++ , j++)
   			{
   				if(s[i]<S[j])
   				{
   					r=mid-1 ;
   					break;   
   				}
   				else if(s[i]>S[j])
   				{
   					l=mid+1 ;
   					break; 
   				} 
   				else if(i==m)
   				{
   					ok =1 ; 
   					break; 
   				}
   				else if(j==n)
   				{
   					l=mid+1 ;
   					break; 
   				}
   			}
   			if(ok)break;
   		}
   		cout<<(ok?"YES":"NO")<<el;
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