#include<bits/stdc++.h>

#define TASK "numberpuzzle"
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

const int N =50+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
string a,  b ,c ;
int n , m , p ;
ll f[N][2];
void read()
{
    cin>>a>>b>>c;
    if(c.size()>max(a.size(),b.size())+1||(c.size()<max(a.size(),b.size())))
    {
    	cout<<0 ; 
    	return;  
    } 
    reverse(all(a)) ; 
    reverse(all(b)) ; 
    reverse(all(c)) ;
}
pii ra(int pos , string a, int n  )
{
	int l = (pos==n) ;  
	int r =9;
	if(pos>n)return {0,0} ;
	if(a[pos]=='*')return {l,r};
	else return {a[pos]-'0',a[pos]-'0'}; 
}
ll tinh(int pos , int nho)
{
	if(f[pos][nho]!=-1)return f[pos][nho];
	if(pos==p+1)
	{
		return f[pos][nho]=(nho==0); 
	}
	int l = ra(pos,a,n).fi ; 
	int r = ra(pos,a,n).se; 
	int x = ra(pos,b,m).fi; 
	int y = ra(pos,b,m).se;
	int u = ra(pos,c,p).fi ; 
	int v =ra(pos,c,p).se; 
	ll tmp = 0; 
	FOR(i,l,r)
	FOR(j,x,y)
	FOR(k,u,v)
	{
		if((i+j+nho)%10==k)
		{
			tmp+=tinh(pos+1,(i+j+nho)/10);
			tmp%=sm;
		}
	}
	return f[pos][nho] =tmp ;
}
void process()
{
	n = a.size() ; 
	m = b.size() ; 
	p = c.size() ;
	FOR(i,0,p+1)f[i][0]=f[i][1] =-1;
	a='#'+a; 
	b='#'+b; 
	c='#'+c;    
}
void print()
{
	ll res=tinh(1,0);
 	cout<<res;   
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