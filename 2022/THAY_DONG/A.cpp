#include<bits/stdc++.h>

#define TASK "A"
const bool multitest = true; 

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));; 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
#define pii pair<int,int>
#define vi vector<int>
#define ve vector
#define str string  
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b)  a/gcd(a,b)*b 
using namespace std;

const int N =2e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n ; 
char a[N] ;
void read()
{
    cin>> n; 
    int s=0 ; 
    FOR(i,1,n)cin>>a[i],s+=(a[i]=='1'); 
    s/=2;
    FOR(i,2,n)
    {		
    	if(a[i]=='0')cout<<'+';
    	else
    	{
    		if(s)
    		{
    			cout<<'-';
    			s-- ;
    		}
    		else
    		{
    			cout<<'+';
    		}
    	}
    }	
    cout<<'\n';
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