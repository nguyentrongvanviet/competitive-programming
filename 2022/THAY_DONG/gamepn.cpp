#include<bits/stdc++.h>

#define TASK "astr2"
const bool multitest = false; 

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));; 
#pragma GCC target("popcnt")
#define ll long long
#define int long long
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

const int N =150+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll cs=330 ,inf = 1e17  ;  
int xx[] = {0,1,0}; 
int yy[] = {0,0,1};
int uu[] = {0,-1,0} ;
int vv[] = {0,0,-1} ;
ll sm ; 
int n , m ,sz ; 
char a[N][N] ;
str s;
ll res=0 ; 
map < tuple<int,int,int,int,int> , ll> f;
void read()
{
    cin>> n >>m >>sm;
    cin>>s;
    sz=s.size() ;
    FOR(i,1,n)FOR(j,1,m)cin>>a[i][j] ;
}	
int pre[N][CH] ;
int suf[N][CH] ;
int truoc[N] , sau[N] ; 
bool ok[30][30];
void process()
{
	FORN(i,0,sz)
	{
		FORN(c,0,CH)
		{
			str tmp = s.substr(0,i); 
			tmp+=(char)(c+'a');
			while(tmp.size()&&tmp!=s.substr(0,tmp.size()))
			{
				tmp.erase(0,1);
			}
			pre[i][c] =tmp.size();
		}
	}
	FORN(i,0,CH)
	{
		pre[sz][i]= sz; 
	}
	FORN(i,0,sz)
	{
		FORN(c,0,CH)
		{
			str tmp =s.substr(sz-i);
			tmp=(char)(c+'a') + tmp ;
			while(tmp.size()&&tmp!=s.substr(sz-tmp.size()))
			{
				tmp.pk();
			}
			suf[i][c] = tmp.size();
		}

	}
	FORN(i,0,CH)
	{
		suf[sz][i] = sz; 
	}
	FOR(i,1,sz)
	{
		str tmp = s.substr(0,i); 
		reverse(all(tmp));
		while(tmp.size()&&tmp!=s.substr(sz-tmp.size()))
		{
			tmp.pk() ;
		}
		sau[i] =tmp.size() ;
	}
	FOR(i,1,sz)
	{
		str tmp = s.substr(sz-i) ; 
		reverse(all(tmp));
		while(tmp.size()&&tmp!=s.substr(0,tmp.size()))
		{
			tmp.erase(0,1) ;
		}
		truoc[i] = tmp.size();
	}
	FOR(i,0,sz)
	{
		FOR(j,0,sz)
		{
			str tmp = s.substr(0,i) +s.substr(sz-j);
			if(tmp.size()<sz)continue ; 
			// cout << i << " "<<j << " "<<tmp<<endl;
			FOR(x,0,tmp.size()-sz)
			{
				if(tmp.substr(x,sz)==s)
				{
					ok[i][j] = 1; 
					break; 
				}
			}
		}
	}
	// cout << pre[0][0]<<endl;
}
// ll f[N][N][N][2][21];
bool check(int tr , int sa)
{
	if(sa<0)return 0 ;
	if(tr<0)return 0;
	return ok[tr][sa] ;
}
ll tinh(int x , int y  ,int u , int v  , int t, int len)
{
	// cout<<x<<" "<<y<<" "<<u<<" "<<v<<" "<<t<<" "<<len<<endl;
	if(f.find({ x , y ,u , t , len})!= f.end()  )return f[{ x , y , u , t , len }];
	int d= abs(x-u)+abs(y-v);
	if(d<=1)
	{
		int tr , sa ; 
		if(t==0)tr=len,sa= sau[tr];
		else sa= len,tr = truoc[sa] ;
		if( len==sz || check(tr,sa-(d==0)) ) 
		{
			return f[{ x , y , u , t , len }]=1 % sm;
		}
		else return f[{ x , y , u , t , len }]=  0 ;
	}
	ll tmp  =0 ;
	int tr , sa; 
	if(t==0)tr=len , sa= sau[tr];
	else sa= len , tr=truoc[sa] ; 
	// cout << tr<<" "<<sa<<endl;	
	FOR(i,1,2)
	{
		FOR(j,1,2)
		{
			int nx = x+xx[i] ; 
			int ny = y+yy[i] ; 
			int nu = u+uu[j] ; 
			int nv = v+vv[j] ; 


			if(nx<=nu&&ny<=nv&&a[nx][ny]==a[nu][nv]&&a[nx][ny]!='#')
			{	
				int l1 = pre[tr][a[nx][ny]-'a'];
				int l2 = suf[sa][a[nu][nv]-'a'];
				tmp+=tinh(nx,ny,nu,nv,!(l1>=l2),max(l1,l2));
				tmp%=sm;
			}
		}
	}
	return f[{ x , y , u , t , len }]=tmp;
}
void print()
{
	if(a[1][1]!=a[n][m]||a[1][1]=='#'||a[n][m]=='#')cout<<0;
	else 
	{
		int c= (a[1][1] == s[0]);
		int d= (a[n][m] ==s[0]) ;
		if(c>=d)res= tinh(1,1,n,m,0,a[1][1]==s[0])  ;
		else res=tinh(1,1,n,m,1,1); 
		cout<<res%sm;
	}
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