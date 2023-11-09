#include<bits/stdc++.h>

#define TASK "segment"
const bool multitest = false; 
#define int long long 
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

const int N =2e3+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  
int xx[5] = {0,0,0,-1,1} ; 
int yy[5] = {0,1,-1,0,0};
struct hcn
{
	int  x, y,  u ,v ; 
}; 
hcn a[N];
vi value; 
int n ; 
int W , H ; 
int wall[N][N][5] ; 

vi D , R ; 
unordered_map<int,int>PD,PR;
bool dd[N][N];
ll val = 0 ;
bool in(int x , int y)
{
	return (1<=x&&x<=W-1&&1<=y&&y<=H-1);
}
void read()
{
    cin>> W >> H ;  
    cin>> n; 
    int cnt = 0 ; 
    FOR(i,1,n)
    {
    	int x, y ,u , v; 
        cin>>x>>y>>u>>v ; 
        if(x>u||y>v)
        {
            swap(x,u) ;
            swap(y,v) ; 
        }
        // cout<<x<<" "<<y<<" "<<u<<" "<<v<<endl;
        if(W<=x||u<=0||H<=y||v<=0)continue;
    	if(x==u)
        {
            cnt++;
            y=max(0LL,y) ;
            v=min(v,H) ;
        }
        else 
        {
            cnt++;
            x =max(0LL,x) ;
            u =min(u,W);
        }
    	a[cnt]={x,y,u,v} ; 
        // cout<<x<<" "<<y<<" "<<u<<" "<<v<<endl;
    }  
    a[++cnt] = {0,0,W,0};
    a[++cnt] ={0,0,0,H}; 
    a[++cnt] = {W,0,W,H}; 
    a[++cnt] = {0,H,W,H};
    n=cnt;   
    FOR(i,1,n)
    {
        D.pb(a[i].x) ; 
        D.pb(a[i].u) ;
        R.pb(a[i].y);  
        R.pb(a[i].v) ;
    }
    sort(all(D)) ;
    sort(all(R)); 
    D.resize(unique(all(D))-D.begin()); 
    R.resize(unique(all(R))-R.begin()); 
}

void dfs(int u , int v)
{
    dd[u][v]=1;
    int x= D[u] ; 
    int y= R[v] ;
    int a = D[u-1] ;    
    int b = R[v-1] ; 
    val+=(x-a)*(y-b);  
    FOR(i,1,4)
    {
        int nx = u+xx[i] ; 
        int ny = v+yy[i] ;
        if(wall[u][v][i]==0&&dd[nx][ny]==0&&in(nx,ny))
        {
            dfs(nx,ny);
        } 
    }
}
void process()
{
    FOR(i,1,D.size())PD[D[i-1]]= i ; 
    FOR(i,1,R.size())PR[R[i-1]]= i ; 
    W = PD[W]; 
    H= PR[H] ;
    FOR(i,1,n)
    {
        a[i]={PD[a[i].x],PR[a[i].y],PD[a[i].u],PR[a[i].v]} ; 
    }
    FOR(i,1,n)
    {	
        // cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].u<<" "<<a[i].v<<endl;
    	if(a[i].x==a[i].u)
    	{
    		FORN(j,min(a[i].y,a[i].v),max(a[i].y,a[i].v))
            {
                wall[a[i].x][j][3]=wall[a[i].x-1][j][4]=1;
            }
    	}
    	else
    	{
    		FORN(j,min(a[i].x,a[i].u),max(a[i].x,a[i].u))
            {
                wall[j][a[i].y][2]=wall[j][a[i].y-1][1]=1;
            }
    	}
    }
    ve<ll>res; 
    FOR(i,1,W-1)
    {
    	FOR(j,1,H-1)
    	{
    		if(!dd[i][j])
    		{
    			val= 0 ;
    			dfs(i,j) ;
    			res.pb(val) ;
    		}
    	}
    }
    sort(all(res),greater<ll>()); 
    for(auto v  : res)
    {	
    	cout<<v<<"\n";
    }
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
        process();
        print() ; 
    }
    
}