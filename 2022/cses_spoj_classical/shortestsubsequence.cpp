#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
bool multitest = false;
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
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

str s ; 
int n;  
void doc()
{
	cin>>s; 
	n = s.size() ; 
	s="#"+s;
}

void xuly()
{	
	int A = 0 ; 
	int C = 0 ; 
	int G = 0 ; 
	int T = 0 ;  
	str res;
	for(int i = 1 , j = i ; i<=n ; i=j)
	{
		A=C=G=T=0;
		while(j<=n&&A+C+G+T!=4)
		{
			A|=(s[j]=='A');
			C|=(s[j]=='C');
			G|=(s[j]=='G');
			T|=(s[j]=='T');
			++j;
		}		
		if(A+C+G+T==4)res+=s[j-1];
	}
	if(A+C+G+T==4) res+='A';
	else if(A==0)res+='A';
	else if(C==0)res+='C';
	else if(G==0)res+='G';
	else if(T==0)res+='T';
	cout<<res;
}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        doc(); 
        xuly();
    }
    cerr<<"Time: "<<clock()<<"ms"<<el;
}