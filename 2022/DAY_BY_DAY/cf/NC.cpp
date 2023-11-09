#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
bool multitest = true;
#include<bits/stdc++.h>
using namespace std; 
void IOS()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r")){freopen(INPUT ,"r",stdin) ;freopen(OUTPUT,"w",stdout);}
}
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define viet first 
#define duyen second  
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define mp make_pair 
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
#define SZ(a) (int)a.size()
#define debug(a) cerr<<#a<<" "<<a<<el;
#define DV cerr<<"<---------------->"<<el;
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
template<class T>void print(ve<T>a){cerr<<"[ ";for(auto v : a)cerr<<v<<" ";cerr<<" ]"<<el;}
const int N = 2e5+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ; 
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
int n , a[N] ; 
int ma[N] , mi[N] ; 
int  position[N];
int l , r ; 
void doc(){
	cin >> n ;
	for(int i= 1;i<=n;i++) cin >> a[i];
}
void xuly()
{
	int res = n /2 + ( n % 2 == 1 );
	for(int i= 1;i<=n;i++) position [ a[i] ] = i;
	if ( n % 2 == 0 ){l = n / 2;r = n / 2 + 1;}
	else{l = n / 2 + 1;r = n / 2 + 1;}
	int tamthoi_l = position[l] + 1;int tamthoi_r = position[r] - 1;int ok1 = 1 , ok2 = 0 ;
	while( l>0  &&  ok1 == 1 && position[l] <= position[r] && ok2 == 0&&  tamthoi_l >= position[l] && tamthoi_r <= position[r] )
	{
        tamthoi_l=position[l];
        ok1 = 1;
        tamthoi_r=position[r];
        ok2 = 0 ;
        l--;r++;res--;
	}
	cout << res << '\n';
}

signed  main()
{
	IOS();
	int test;
	cin>>test;
	while(test--)
	{
		doc();
		xuly();
	}

	return 0;
}