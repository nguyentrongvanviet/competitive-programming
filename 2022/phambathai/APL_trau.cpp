#include<bits/stdc++.h>

#define TASK "APL"
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
using namespace std;
const int N =2e2+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n ; 
ll f[N][N];
int h1 , h2 ;
ll tinh(int h , int pos)
{
	if(f[h][pos]!=-1)return f[h][pos] ;
	if(pos==n+1&&h==h2)
	{
		return 1;  
	}
	ll tmp = 0 ; 
	for(int i = -1 ;i<=1;i++)
	{
		if(h+i>=0)tmp+=tinh(h+i,pos+1) ;
		tmp%=sm;
	}
	return f[h][pos] =tmp ;
}
void read()
{
    cin>>h1>>h2>>n;  
    FOR(i,0,n+1)FOR(j,0,2e2)f[j][i]=-1;
   	cout<<tinh(h1,1); 
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
        freopen(TASK".ANS","w",stdout); 
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