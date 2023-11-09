#include<bits/stdc++.h>

#define TASK "sumcir"
const bool multitest = false; 
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));
#pragma GCC target("popcnt")
#define ll long long 
#define db long double  
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define vi vector<int>
#define ve vector 
#define str string 
#define pll pair<ll,ll>
#define fi first 
#define se second
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++) 
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b)  a/gcd(a,b)*b
#define MT vector<vector<ll>> 
using namespace std;
const int N =5e2+1 , maxN=20 , oo = 2e9, CH = 26 ;
const ll cs=330 ,inf = 1e17 ;
ll sm ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n , k ,D ; 
void init(MT&a ,int n ,int m )
{
	vector<ll>tmp(m,0);
	FORN(i,0,n)a.pb(tmp);
}
MT mul(MT a , int  na,  int ma  , MT b ,int nb ,int mb  )
{
    MT tmp;
    int n = na; 
    int m = mb;
    init(tmp,n,m);
    int l= ma;
    for(int i =0;i<n;i++)
    {
        for(int j= 0 ;j<m;j++)
        {
            tmp[i][j]=0;
            for(int t= 0 ; t<l;t++)
            {
                tmp[i][j]+=(a[i][t]*b[t][j])%sm;
                tmp[i][j]%=sm;
            }
        }
    }
    return tmp ;
}
MT pw(MT a, ll p )
{
    if(p==1)return a;
    MT c =pw(a,p/2);
    if(p&1)return mul(mul(c,n,n,c,n,n),n,n,a,n,n);
    return mul(c,n,n,c,n,n);
}
MT a ; 
MT b ; 
MT ans ;

void read()
{
    cin>> n >>sm>>D>>k;

    init(a,1,n);
    FORN(i,0,n)cin>>a[0][i];
    init(b,n,n);
    FORN(i,0,n)
    {
    	FORN(j,0,n)
    	{
    		if(min(abs(i-j),n-(abs(i-j)))<=D)
    		{
    			b[i][j]=1 ;
    		}
    	}
    }
    b=pw(b,k) ; 
    FORN(i,0,n){
    	FORN(j,0,n)cout<<b[i][j]<<" ";
    	cout<<endl;
    }
    ans = mul(a,1,n,pw(b,k),n,n);
    FORN(i,0,n)cout<<ans[0][i]%sm<<" ";
}
void process()
{
    
}
void print()
{
    
}
signed main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout); 
    }
    int test = 1;  
    if(multitest)cin>>test; 
    while(test--)
    {
        read() ; 
        process();
        print() ; 
    }
}