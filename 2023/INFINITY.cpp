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

bool mtt = 1 ;
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n ; 
str cong(str a , str b )
{
	while(a.size()<b.size())a='0'+a; 
	while(b.size()<a.size())b='0'+b;
	string ans= "";  
	int nho  =0 ; 
	for(int i= b.size()-1;i>=0;i--)
	{
		int tmp = nho+ a[i]-'0'+b[i]-'0' ; 
		int c= tmp%10 ; 
		nho = tmp/10 ; 
		ans=(char)(c+'0')+ans; 
	}
	if(nho)ans='1'+ans;		 
	return ans; 
}
str tru(str a , str b)
{
	while(b.size()<a.size())b='0'+b;
	str ans="" ; 
	int thieu =0 ;
	FORD(i,b.size()-1,0)
	{
		int tmp = a[i]-b[i]-thieu ; 
		if(tmp<0)thieu = 1 , tmp+=10; 
		else thieu = 0 ;
		int c= tmp%10;
		ans=(char)(c+'0')+ans; 
	}
	while(ans.size()>1&&ans[0]=='0')ans.erase(0,1);
	return ans ; 
}
str mul(str a , int b)
{
	str ans="";
	int nho = 0 ;
	FORD(i,a.size()-1,0)
	{
		int tmp = (a[i]-'0')*b+nho ; 
		nho=tmp/10;  
		int c= tmp%10;
		ans=(char)(c+'0')+ans;  
	}
	if(nho)ans=(char)(nho+'0')+ans;
	return ans;  
}
str nhan(str a, str b)
{
	str ans=""; 
	str zero = "" ;
	FORD(i,b.size()-1,0)
	{
		str tmp = mul(a,b[i]-'0');
		tmp+=zero;  
		ans=cong(ans,tmp);
		zero+="0"; 
	}
	return ans; 
}
bool cmp(str x , str y)
{
	if(x.size()<y.size())return 1; 
	if(x.size()>y.size())return 0 ; 
	FORN(i,0,x.size())
	{
		if(x[i]<y[i])return 1; 
		if(x[i]>y[i])return 0; 
	}
	return 1; 
}
void doc()
{
	str s ; cin>>s ;
	ll l =1 ; 
	ll r = 1e16 ; 
	ll ans =  -1 ; 
	while(l<=r)
	{
		ll mid =(l+r)/2; 
		str tmp = to_string(mid) ;
		str x = nhan(tmp,tmp) ;
		if(cmp(x,s))
		{
			ans=mid ; 
			l=mid+1; 
		}
		else r=mid-1 ; 
	}
	str x = to_string(ans) ;
	x= nhan(x,x) ; 
	if(x==s)
	{
		cout<<1<<el;	
		return ; 
	}
	s=tru(s,x); 
	ll tmp= 0 ; 
	for(auto v : s)
	{
		tmp=tmp*10+(v-'0') ; 
	}
	++ans;
	// cout<<s<<" "<<tmp<<el;
	// cout<<ans<<el;

	// cout<<ans<<" "<<tmp<<el;
	if(tmp<=ans)
	{
		cout<<tmp<<el;
	}
	else
	{
		cout<<2*ans-tmp<<el;
	}
}

namespace sub1
{
    void xuly()
    {
        
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

    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}