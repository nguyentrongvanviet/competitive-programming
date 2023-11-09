#define TASK "1777F"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = true;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define duyen first 
#define viet second 
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
void IOS()
{
    fast 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout) ;
    }
}
const int N = 2e5+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
// template <class T> debug(ve< a )
// {

// }
int n ;
int T[N*32][2] ; 
int a[N] ; 
int s[N] ;
int l[N] , r[N] ; 
pii asc[N] ;
int node ;
int root[N]; 
void add(int r , int val)
{	
	FORD(i,30,0)
	{
		int j= val>>i&1; 
		if(T[r][j]==0)T[r][j]=++node ; 
		r=T[r][j];
	}
}	
void merge(int r , int conr ,int val)
{
	FORD(i,30,0)
	{
		int j= val>>i&1;
		if(T[r][j])
		{
			r=T[r][j] ; 
			conr=T[conr][j];
		}
		else 
		{
			T[r][j]=T[conr][j] ;
		}
	}	
}
int get(int r , int val)
{
	int ans =0 ; 
	FORD(i,30,0)
	{
		int j= val>>i&1 ;
		if(T[r][j^1])ans|=(1<<i),r=T[r][j^1];
		else r=T[r][j] ; 
	}
	return ans ; 
}	
void doc()
{
	cin>> n ;
	FOR(i,1,n)
	{
		cin>>a[i] ; 
		asc[i] = mp(a[i],i) ; 
		s[i] = s[i-1]^a[i] ; 
	} 
}

void xuly()
{
	// preprocess 
	sort(asc+1,asc+n+1) ; 
	stack<int>st; 
	FOR(i,1,n)
	{
		while(!st.empty()&&a[st.top()]<=a[i]) st.pop() ; 
		if(st.empty())l[i] = 1 ; 
		else l[i] = st.top()+1;
		st.push(i) ; 
	}
	while(!st.empty())st.pop();
	FORD(i,n,1)	
	{	
		while(!st.empty()&&a[st.top()]<a[i])st.pop() ;  
		if(st.empty())r[i] = n ; 
		else r[i] = st.top()-1 ; 
		st.push(i) ;
	}
	int res = 0 ; 
	FOR(it,1,n)
	{
		int pos = asc[it].viet;
		if(l[pos]==r[pos])
		{
			root[pos]=++node; 
			add(root[pos],s[pos]);
			continue ;
		}

		int L = l[pos] ;
		int R = pos-1 ;
		int U = pos+1 ; 
		int V = r[pos] ;
		if(R-L+1>=V-U+1)
		{
			FOR(i,pos,V)
			{
				res=max(res,get(root[L],s[i]^a[pos]));
				res=max(res,s[i]^a[pos]^s[L-1]);
			}
			FOR(i,U,V)merge(root[L],root[U],s[i]);
			// root[U] = root[L]; 
		}
		else
		{
			FOR(i,L,pos)
			{
				res=max(res,get(root[U],s[i-1]^a[pos]));
				res=max(res,s[i-1]^s[pos-1]);
			}
			FOR(i,L,R)
			{
				merge(root[U],root[L],s[i]);
			}
			root[L]=root[U];
		}
		add(root[L],s[pos]);
	}
	cout<<res<<el;
}
void clear()
{
	FOR(i,1,node)
	{
		T[i][0] = T[i][1]= 0 ;
	}
	FOR(i,1,n)root[i] = 0 ;
	node = 0; 
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
        clear(); 
    }
    // FOR(i,1,1e8)cout<<"1";
    cerr<<"Time: "<<clock()<<"ms"<<el;
}