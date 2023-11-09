#include<bits/stdc++.h>

#define TASK "astr2"
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
const int N =2e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n , k ;
string s[N] ; 
int res= 0  ;
bool check(string tmp)
{
	FOR(i,1,k)
	{
		FOR(j,0,tmp.size()-s[i].size())
		{
			if(tmp.substr(j,s[i].size())==s[i])return 0 ; 
		}	
	}
	return 1 ; 
} 
void read()
{
    cin>> n>>k; 
    FOR(i,1,k)
    {
    	cin>>s[i] ;
    }
    FORN(i,0,(1<<n))
    {
    	string tmp = "" ;
    	FORN(j,0,n)
    	{
    		if(i>>j&1)tmp+='1';
    		else tmp+='0';
    	}
    	if(check(tmp))res++;
    }
    cout<<res;
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