#define TASK "1777F"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
const int T = 100 ;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
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
const int N =2e5+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

ll rd(ll l , ll r )
{
    return  l +1LL*rand()*rand()%(r-l+1);
}
void create()
{
    ofstream cout(TASK".INP");

    int test = 1;
    cout<<test<<el;
    int tot = 2e5; 
    FOR(i,1,test)
    {
    	int n = rd(2e5,2e5);
    	cout<<n<<el; 
    	FOR(i,1,n)cout<<rd(1,1e9)<<" "; 
    	cout<<el;   
    }
    cout.close();
}

int main()
{
    fast
    srand(time(0));
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
    return 0;
}