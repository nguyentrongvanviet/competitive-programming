/*
Name   :   Nguyen Trong Van Viet
DoB    :   29 - 10 - 2006                      
School :   VNUHCM - University Of Science         
Donate :   VCB    - 1026950589                         
*/

#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

#include<bits/stdc++.h>
using namespace std; 

typedef long long ll ;

#define fi first 
#define se second
#define uni(a) a.resize(unique(all(a))-a.begin()) 
#define all(a) a.begin(),a.end()  
#define btpc __builtin_popcountll
#define LB lower_bound
#define UB upper_bound 
#define BIT(msk,i) ((msk)>>(i)&1)
#define MSK(i) (1ll<<(i))
#define tct template<class T>
tct T sq(T a){return a*a;}  
ll lg(ll a){return __lg(a);}
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};


const double PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


void solve()
{
	int n , m;  cin>>n >>m ; 
	vector<pair<int,int>>a(m+1) ; 
	vector<int>dd(n+1,0) ;  
	for(int i=1;i<=m;i++)
	{
		int l ,r ; cin>> l >>r ;
		a[i]= make_pair(l,r) ; 
		for(int pos = l ; pos<=r;pos++)
		{
			dd[pos] = 1 ; 
		}
	}
	for(int i=1;i<=n;i++)
	{ 
  		bool check =  1 ;
		for(int j=1;j<=m;j++)
		{
			if(!(a[j].first<=i&&i<=a[j].second))
			{
				check = 0 ; 
			}
		}
		if(check)
		{
			int pos = i ;
			int cnt = 1;  
			for(int i=1;i<=n;i++)
			{	
				if(i==pos)
				{
					cout<<0<<" ";
				}
				else cout<<cnt++<<" ";
			}	
			cout<<'\n' ;
			return ; 
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dd[i]==0)
		{
			int cnt = 1 ; 
			int pos = i ; 
			for(int i=1;i<=n;i++)
			{
				if(i==pos)
				{
					cout<<0<<" "; 
				}
				else cout<<cnt++<<" ";
			}
			cout<<'\n' ; 
			return ; 
		}
	}
	auto check =[](int pos ,int l, int r )->bool
	{
		return l<=pos&&pos<=r ; 
	};
	for(int i=1;i<=n-1;i++)
	{
		bool ok =1 ; 
		for(int j = 1;j<=m;j++)
		{
			if(check(i,a[j].first,a[j].second)&&(!check(i+1,a[j].first,a[j].second)))
			{
				ok = 0 ; 
				break; 
			}
		}
		if(ok==1)
		{
			int res = i ;
			int cnt = 2 ; 
			for(int i=1;i<=n;i++)
			{
				if(i==res)
				{
					cout<<0<<" " ; 
				}
				else if(i==res+1)
				{
					cout<<1<<" " ; 
				}
				else cout<<cnt++<<" ";
			}
			cout<<'\n' ; 
			return ; 
		}
	}
	for(int i=2;i<=n;i++)
	{
		bool ok = 1 ; 
		for(int j=1;j<=m;j++)
		{
			if(check(i,a[j].first,a[j].second)&&(!check(i-1,a[j].first,a[j].second)))
			{
				ok = 0 ; 
			}
		}
		if(ok)
		{		
			int res = i ;
			int cnt =2  ;  
			for(int i=1;i<=n;i++)
			{
				if(i==res-1)
				{
					cout<<1<<" " ; 
				}
				else if(i==res)
				{
					cout<<0<<" "; 
				}
				else cout<<cnt++<<" "; 
			}
			cout<<'\n'; 
			return ; 
		}
	}
	cout<<0<<" ";
	for(int i=2;i<n;i++)
	{
		cout<<i<<" "; 
	}
	cout<<1;
	cout<<'\n' ; 
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    
    if(fopen(INPUT,"r")){
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ; 
    }
  	int test; 
  	cin>>test; 
  	while(test--)
  	{
  		solve() ; 
  	}


    cerr<<"\n[Finished in "<<clock()<<"ms]\n";

}

// I'm old now 


