/*
Name   :   Nguyen Trong Van Viet
DoB    :   29 - 10 - 2006                      
School :   VNUHCM - University Of Science         
Donate :   VCB    - 1026950589                         
*/

#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

#include<bits/stdc++.h>
using namespace std; 

typedef long long ll ;

#define fi first 
#define se second
#define uni(a) a.resize(unique(all(a))-a.begin()) 
#define all(a) a.begin(),a.end()  
#define btpc __builtin_popcountll
#define LB lower_bound
#define UB upper_bound 
#define BIT(msk,i) ((msk)>>(i)&1)
#define MSK(i) (1ll<<(i))
#define tct template<class T>
tct T sq(T a){return a*a;}  
ll lg(ll a){return __lg(a);}
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};


const double PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

string s[N] ; 
struct SuffixArray {
vi sa, lcp;
SuffixArray(string& s, int lim=256) { // or basic string<int>
	int n = s.size()+ 1, k = 0, a, b;
	vector<int> x(all(s)), y(n), ws(max(n, lim));
	x.push_back(0), sa = lcp = y, iota(all(sa), 0);
	for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
		p = j, iota(all(y), n - j);
		for(int i=0;i<n;i++) if (sa[i] >= j) y[p++] = sa[i] - j;
		fill(all(ws), 0);
		for(int i=0;i<n;i++) ws[x[i]]++;
		for(int i=1;i<lim;i++) ws[i] += ws[i - 1];
		for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
		swap(x, y), p = 1, x[sa[0]] = 0;
		for(int i=1;i<n;i++) a = sa[i - 1], b = sa[i], x[b] =
			(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
	}
	for (int i = 0, j; i < n - 1; lcp[x[i++]] = k)
		for (k && k--, j = sa[x[i] - 1];
			s[i + k] == s[j + k]; k++);
	}
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    
    if(fopen(INPUT,"r")){
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ; 
    }
   	int n ; cin>> n;
   	for(int i=1;i<=n;i++)
   	{
   		cin>>s[i]; 
   		s[i] = "#"+s[i] ; 
   	}

    cerr<<"\n[Finished in "<<clock()<<"ms]\n";

}

// I'm old now 


