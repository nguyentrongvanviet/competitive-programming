#define TASK "coin2"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
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
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
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

int n ,m   ; 
void read()
{
	cin>>n >> m; 

}
struct DL
{
	ve<vi>a ;
	int sl=0 ; 
	int t=0 ; 
}; 
struct nhay
{
	int x,  y , u,v ; 
};
map<ve<vi>,nhay>pre;  
bool in(int x, int y )
{
	return 0<=x&x<n&&0<=y&&y<m;
}
void print(ve<vi>&a)
{
	FORN(i,0,n)
	{
		FORN(j,0,m)cout<<a[i][j]<<" ";cout<<el;
	}
}
DL bfs(DL s)
{
	queue<DL>q;
	pre[s.a] = {0,0,0,0};
	q.push(s);
	while(!q.empty())
	{
		ve<vi> a =q.front().a; 
		int sl= q.front().sl;
		int tt =q.front().t; 
		// print(a);cout<<tt<<el;cout<<el;
		q.pop() ;
		if(tt==2048)break;
		FORN(x,0,n)FORN(y,0,m)if(a[x][y])
		{
			FOR(t,1,4)
			{
				int nx = x+xx[t]; 
				int ny = y+yy[t]; 
				if(in(nx,ny))
				{
					if(a[nx][ny]==0)
					{
						swap(a[nx][ny],a[x][y]) ; 
						if(pre.find(a)==pre.end())
						{
							pre[a] = {x,y,nx,ny}  ; 
							q.push({a,sl,tt+1});
						} 
						swap(a[nx][ny],a[x][y]) ; 
					}
					else 
					{
						nx=nx+xx[t] ; 
						ny=ny+yy[t] ; 
						if(in(nx,ny)&&a[nx][ny]==0)
						{
							swap(a[nx][ny],a[x][y]); 
							a[nx-xx[t]][ny-yy[t]]=0;
							if(pre.find(a)==pre.end())
							{
								pre[a] = {x,y,nx,ny}; 
								q.push({a,sl-1,tt+1}) ; 
								if(sl-1==1)return {a,sl-1,tt+1};
							} 
							a[nx-xx[t]][ny-yy[t]]=1;
						}
					}
				}	
			}
		}
	} 
	DL tmp ; 
	return tmp ;
}

void solve()
{
	ve<vi>a(n,vi(m+1,0)) ;
	int s= 0 ; 
	FORN(i,0,n)FORN(j,0,m)
	{
		char x; cin>>x ; 
		a[i][j]=x-'0';  
		s+=a[i][j];
	}
	if(s==0)return void(cout<<-1) ;
	else if(s==1) return void(cout<<0);
	DL last = bfs(DL{a,s,0}) ;
	if(last.sl==0)return void(cout<<-1); 
	int tt =  last.t ; 
	ve<nhay>res;
	for(int  i= 1;i<=tt;i++)
	{
		nhay tmp = pre[last.a] ;  
		res.pb(tmp) ; 
		int x= tmp.x ; 
		int y= tmp.y ; 
		int u= tmp.u ; 
		int v= tmp.v; 
		swap(last.a[x][y],last.a[u][v]); 
		if(abs(x-u)+abs(y-v)==2)last.a[(x+u)/2][(y+v)/2]=1 ;
	}	
	reverse(all(res))  ; 
	cout<<tt<<el;
	for(auto x: res)
	{
		cout<<x.x+1<<" "<<x.y+1<<" "<<x.u+1<<" "<<x.v+1<<el;
	}
}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        read(); 
        solve();
    }
}