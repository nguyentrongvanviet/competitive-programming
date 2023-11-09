#include<bits/stdc++.h>
#define TASK "theater"
const bool multitest = false; 

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));; 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= (a);i<=(b);i++)
#define FORD(i,a,b) for(int i= (a);i>=(b);i--)
#define FORN(i,a,b) for(int i= (a);i<(b);i++)
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
#define db double 
using namespace std;
// template
const int N =2e5+5 ,maxN=16 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ;
const db inf = 1e12  ;  
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
struct pt 
{
	double x, y ; 
}; 
db F[2][maxN][1<<maxN]; 
db C[2][2][1<<maxN] ;
db ans[N][2][2];

db sq(db a){return a*a ; }
int n , m ; 
db V1 ,V2 ,  W , H ; 
pt a[maxN] ;
int q[N]; 
void read()
{
    cin>> W >> H >> V1 >> V2 >> n ;
    swap(W,H) ;
    FORN(i,0,n)cin>>a[i].x>>a[i].y;
    cin>>m ;  
    FOR(i,1,m)
    {
    	int  k ; 
    	cin>> k; 
    	FOR(j,1,k)
    	{
    		int x; 
    		cin>>x; 
    		q[i]|=(1<<(x-1)) ;
    	}
    } 
}
db dis(pt a, pt b){return sqrt(sq(a.x-b.x)+sq(a.y-b.y));}
db go(int id , int en)
{
	if(en==0)return a[id].x; 
	else return W-a[id].x;
}

void init()
{
	FORN(i,0,2)FORN(u,0,n)FORN(msk,0,1<<n)F[i][u][msk]= inf ;
	FORN(i,0,2)FORN(j,0,2)FORN(msk,1,1<<n)C[i][j][msk]=inf;
	FOR(i,0,m)FORN(j,0,2)FORN(x,0,2)ans[i][j][x]=inf;
}
void process()
{
	init();

 	FORN(i,0,2)
 	{
		FORN(x,0,n)
		{
			F[i][x][0]= 0 ; 
			F[i][x][1<<x]= go(x,i); 
		}
 	}
 	FORN(msk,0,1<<n)
 	{
 		FORN(i,0,2)
 		{
			FORN(u,0,n)if(msk>>u&1)
			{
				FORN(v,0,n)if(!(msk>>v&1))
				{
					db tmp = F[i][v][msk|(1<<v)];
					db val = F[i][u][msk]+dis(a[u],a[v]);
					F[i][v][msk|(1<<v)]=min(tmp,val);
				}
 			}
 		}
 	}
 	FORN(msk,0,1<<n)
 	{
 		FORN(i,0,n)if(msk>>i&1)
 		{
 		 	FORN(l,0,2)
	 		{
	 			FORN(r,0,2)
	 			{
	 				db tmp = F[l][i][msk]+go(i,r);
	 				db cur = C[l][r][msk];
	 				C[l][r][msk]=min(cur,tmp);
	 			}
	 		}
 		}	
 	}
 	C[0][0][0] =0  ;
    C[0][1][0] = W; 
    C[1][1][0] = 0 ;
    C[1][0][0] = W ;
 	ans[1][0][1]= 0 ;
 	FOR(t,2,m)
 	{
 		int pre =q[t-1] ; 
 		int cur = q[t] ; 	
 		int a= 0 ; 
 		int b = 0 ; 
 		FORN(i,0,n)
 		{
 			if((pre>>i&1)&&!(cur>>i&1))
 			{
 				a|=(1<<i);
 			}
 			if(!(pre>>i&1)&&(cur>>i&1))
 			{
 				b|=(1<<i); 
 			}
 		}
 		swap(a,b);
 		FORN(i,0,2)
 		{	
 			FORN(j,0,2)
 			{
 				FORN(ii,0,2)
 				{
 					FORN(jj,0,2)
 					{
 						db nx=ans[t-1][i][j]+C[i][ii][a]/V1;
 						db ny=ans[t-1][i][j]+C[j][jj][b]/V2;
 						ans[t][ii][jj] = min(ans[t][ii][jj],max(nx,ny));
 					}
 				}
 			}		
  		}
 	}
}
void print()
{
	db res= (db)inf;
	FORN(i,0,2)
	{
		FORN(j,0,2)
		{
			res=min(res,ans[m][i][j]);
		}
	}
	cout<<setprecision(5)<<fixed;
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
