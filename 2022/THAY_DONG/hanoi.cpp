#include<bits/stdc++.h>

#define TASK "hanoi"
const bool multitest = false; 

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

const int N =3,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
bool g[N][N] ;
ve<pair<int,int>>sol;
void move(int i, int f, int t)
{
    int mid = 3 - t - f;
    if(i==1)
    {
        if (g[f][t])
        {
            sol.pb({f, t});
            return;
        }
        else 
        {
            sol.pb({f, mid});
            sol.pb({mid ,t});
            return;
        }
    }

    if (g[f][t])
    {
        move(i - 1, f, mid);
        move(1, f, t);
        move(i - 1, mid, t);
    }
    else 
    {
        move(i - 1, f, t);
        sol.pb({f, mid});
        move(i - 1, t, f);
        sol.pb({mid, t});
        move(i - 1, f, t);
    }
}
void read()
{
	int n;
    cin>> n;	
    FOR(i,0,2)FOR(j,0,2)cin>>g[i][j] ; 
    move(n,0,2);
    cout<<sol.size()<<'\n';
    for(int i = 0 ;i<sol.size();i++)
    {
    	printf("%c%c",&char(sol[i].fi+'A'),&char(sol[i].se+'A'))<<'\n';
    }
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
        // process();
        print() ; 
    }
    
}
