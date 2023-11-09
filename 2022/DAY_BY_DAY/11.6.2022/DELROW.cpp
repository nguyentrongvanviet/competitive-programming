#include<bits/stdc++.h>
using namespace std;

#define TASK "DELROW"

#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b) for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i = b;i>=a;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

const int N =5e3+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n  ,  m ;
ll a[N][N] ; 	
ll ha[N][N] ; 
ll mu[N];
ll get_hash(int col  , int l , int r )
{
	return (ha[r][col]-ha[l-1][col]*mu[r-l+1]%sm+sm*sm)%sm;
}

bool check(int len)
{
	unordered_set<ll>s ; 
	for(int i= 1;i<=m;i++)
	{	
		ll value = get_hash(i,len+1,n);
		if(s.find(value)!=s.end())
		{
			return 0 ;
		} 
		else 
		{
			s.insert(value) ;
		}
	}
	return 1; 
}
void doc()
{
	cin>> n >> m;  
	FOR(i,1,n)FOR(j,1,m)
	{
		char u  ; cin>> u ; 
		a[i][j] = u-'a'+1;
	}
	mu[0] = 1;
	FOR(i,1,max(n,m))mu[i] = (mu[i-1]*cs)%sm ;
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			ha[i][j] = (ha[i-1][j]*cs+a[i][j])%sm;
		}
	}
	int l = 1; 
	int r = n-1;
	int ans= 0 ;  
	while(l<=r)
	{
		int mid =(l+r)>>1;
		if(check(mid))
		{
			ans =mid ; 
			l=mid+1 ;
		}
		else 
		{
			r=mid-1 ;
		}
	}
	cout<<ans; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}