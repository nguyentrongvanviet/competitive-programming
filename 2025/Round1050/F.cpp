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

// typedef long long ll ;
#define ll long long 
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



int n ; 
ll mu[N] ;
vector<int>possible[N] ; 
void solve()
{
	cin>> n ; 
	vector<vector<ll>>hash ;
	vector<vector<int>>a ;  
	auto get = [&](int id,  int l, int r)
	{
		return (hash[id][r]-1ll*hash[id][l-1]*mu[r-l+1]%sm+sm)%sm ; 
	} ; 
	hash.push_back(vector<ll>()) ;
	a.push_back(vector<int>()) ; 
	for(int i=1;i<=n;i++)
	{
		hash.push_back(vector<ll>()) ;
		a.push_back(vector<int>()) ; 
		int sl ; cin>>sl;
		a[i].push_back(0) ; 
		hash[i].push_back(0) ; 
		for(int j=0;j<sl;j++)
		{
			int c ; cin>>c ; 
			a[i].push_back(c) ; 
			hash[i].push_back((1ll*hash[i].back()*cs%sm+c)%sm);
		}
		for(int j=1;j<=sl;j++)
		{
			possible[j].push_back(i) ; 
		}	
	}
	for(int i=1;i<N;i++)
	{
		if(possible[i].empty())break;
		sort(all(possible[i]),[&](int idx , int idy)
		{
			int ans = -1;
			int l = 0 ;  
			int r = min(a[idx].size(),a[idy].size())-i   -1;
			while(l<=r)
			{
				int mid =(l+r)>>1 ; 
				if(get(idx,i,i+mid)!=get(idy,i,i+mid))
				{
					ans=mid ; 
					r=mid-1; 
				}
				else
				{
					l=mid+1 ; 
				}
			}
			if(ans==-1)
			{
				return a[idx].size()<a[idy].size()||(a[idx].size()==a[idy].size()&&idx<idy);
			}
			return a[idx][i+ans]<a[idy][i+ans] ; 
		}
		) ;
	}
	int len = 0 ;
	while(1)
	{
		if(possible[len+1].empty())
		{
			break; 
		}
		int id = possible[len+1][0] ; 
		for(int i=len+1;i<=int(a[id].size())-1;i++)
		{
			cout<<a[id][i]<<" "; 
		}
		len = a[id].size()-1 ; 
	}
	cout<<'\n'; 
	for(int i=1;i<N;i++)
	{
		if(possible[i].empty())break; 
		possible[i].clear() ; 
	}
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
    mu[0] = 1;  
    for(int i=1;i<N;i++)
    {
    	mu[i] = 1ll*mu[i-1]*cs%sm ; 
    }
    int test ; cin>>test; 
    while(test--)
    {
    	solve() ; 
    }

    
    cerr<<'\n'<<"[Finished in "<<clock()<<"ms]"<<'\n';

}

// I'm old now 


