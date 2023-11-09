/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
***************************************************************/

#define TASK "F_Sonya_and_Bitwise_OR"
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
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 1e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n , q , VALUE ; 
int a[N] ; 

struct DL
{
	int val , pos ; 
} ; 
struct NODE
{
	ve<DL> P , S ;
	ll res = 0 ; 
} ; 
NODE st[4*N] ; 
NODE merge(NODE L , NODE R,int l, int r)
{  
	if(L.S.empty())return R ; 
	if(R.P.empty())return L ; 
	NODE tmp ; 
	tmp.res=R.res+L.res ;
	int it =0 ;   
	FORD(i,L.S.size()-1,0)
	{
		while(it<R.P.size()&&(R.P[it].val|L.S[i].val)<VALUE)++it ; 
		
		if(it<R.P.size())
		{
			tmp.res+=1LL*(r-R.P[it].pos+1)*(L.S[i].pos-l+1); 
		}
		l=L.S[i].pos+1;
	}
	tmp.P = L.P ; 
	for(auto v : R.P)
	{
		int pre = tmp.P.back().val;
		if( pre != (pre|v.val) )tmp.P.pb({ pre|v.val,v.pos });
	}
	tmp.S=R.S ; 
	for(auto v: L.S)
	{
		int suf = tmp.S.back().val ; 
		if( suf != (suf|v.val) ) tmp.S.pb({ suf|v.val,v.pos }) ; 
	}
	return tmp ;  
}
void build(int id ,int l ,int r )
{
	if(l==r)
	{
		st[id].P=st[id].S={{a[l],l}} ; 
		st[id].res= a[l]>=VALUE ; 
		return;  
	}
	int mid =(l+r)/2 ;
	build(id*2,l,mid) ; 
	build(id*2+1,mid+1,r) ; 
	st[id] =merge(st[id*2],st[id*2+1],l,r) ; 
}
void up(int id, int l, int r ,int pos , int val)
{
	if(l==r&&l==pos)
	{
		a[l] = val ; 
		st[id].P=st[id].S={{a[l],l}} ; 
		st[id].res= a[l]>=VALUE ; 
		return ; 
	}
	if(r<pos||pos<l)return ; 
	int mid =(l+r)/2 ;
	up(id*2,l,mid,pos,val) ; 
	up(id*2+1,mid+1,r,pos,val) ; 
	st[id] =merge(st[id*2],st[id*2+1],l,r) ; 
}
NODE get(int id ,int l ,int r, int t ,int p )
{
	if(t<=l&&r<=p)return st[id] ; 
	if(r<t||p<l)return NODE{} ; 
	int mid = (l+r)/2; 
	return merge(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p),max(t,l),min(p,r)) ; 
}
void doc()
{
	cin>> n >>q >>VALUE ; 
	FOR(i,1,n)cin>>a[i] ; 
}

void xuly()
{	
	build(1,1,n) ; 	
	FOR(i,1,q)
	{
		int t  ; 
		cin>>t ;
		if(t==1)
		{
			int pos , val ; cin>>pos>>val ; 
			up(1,1,n,pos,val);
		}
		if(t==2)
		{
			int l, r ;cin>>l>>r ;
			NODE ans=get(1,1,n,l,r) ; 
			cout<<ans.res<<el;
		}
	}
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