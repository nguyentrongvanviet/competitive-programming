#define TASK "FKMEMBER"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define ll long long 
#define db double 
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
#define mp make_pair 
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
const int N = 2e5+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ; 
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
ll rd(ll l , ll r )
{
    return l+1LL*rand()*rand()%(r-l+1) ; 
}
void create()
{
    ofstream cout("text.INP");
    int n = 1e5 ,  k = 200 ; 
   	cout<<n<<" "<<k<<el ;
   	FOR(i,1,n-1)cout<<i<<" "<<rd(i+1,n) <<" "<<rd(1,1e9)<<el; 
    cout.close();
}

signed main()
{
	int T = 100; 
    FOR(i,1,T)
    {
        create(); 
        // system(TASK"_trau.exe");
        system(TASK".exe"); 
        // if(system("fc " TASK ".ANS " TASK ".OUT")!=0)
        // {   
        //     cout<<"Test "<<i<<" WA"<<"\n";
        //     return  0 ; 
        // }
        // else 
        // {
        //     cout<<"Test "<<i<<" AC"<<"\n";
        // }
    }
}