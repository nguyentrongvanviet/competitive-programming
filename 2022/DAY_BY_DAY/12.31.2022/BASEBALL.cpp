#define TASK "BASEBALL"
#include<bits/stdc++.h>
using namespace std; 

bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db long double
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".OUT","w",stdout) ;
    }
}

const int N =2e5+5, maxN=20, oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n;  
ll a[N]  ;
void read()
{
	cin>> n; 
	FOR(i,1,n)cin>>a[i] ; 
	sort(a+1,a+n+1) ; 
}

void solve()
{
	ll res=0 ;  
	FOR(i,1,n)
	{
		FOR(j,i+1,n)
		{
			int l = j+1; 
			int r=  n ; 
			int ans =  0 ;
			while(l<=r)
			{
				int mid =(l+r)/2; 
				if(a[mid]-a[j]>=a[j]-a[i])
				{
					ans=mid ; 
					r=mid-1;  
				}
				else
				{
					l=mid+1;  
				}
			}
			if(ans==0)continue ;
			l = ans ; 
			r = n ; 
			ans =0 ; 
			int idx = l; 
			while(l<=r)
			{
				int mid =(l+r)/2; 
				if(a[mid]-a[j]<=2*(a[j]-a[i]))
				{
					ans= mid; 
					l=mid+1; 
				}
				else
				{
					r=mid-1 ; 
				}
			}
			if(ans==0)continue ; 
			// cout<<i<<" "<<j<< " "<<ans<<el;
			if(ans)res+=1LL*(ans-idx+1); 
		}	
	}
	cout<<res;
}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        read(); 
        solve();
    }
}