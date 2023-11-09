/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "math"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
#define pii pair<int,int>
#define vi vector<int> 
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
void IOS()
{
    fast 
    srand(time(0)) ;
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =1e6+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct Q 
{
	int x, y, u , v; 
	int c ;
}query[N]; 
int n , m ,q ;  
void doc()
{	
    cin>> n>> m; 
    vector<vi> a=vector<vi>(n+2,vi(m+2,0));
    vector<vi> d=vector<vi>(n+2,vi(m+2,0));
    vector<vi> M=vector<vi>(n+2,vi(m+2,0));
    vector<vi> D=vector<vi>(n+2,vi(m+2,0));

    FOR(i,1,n){FOR(j,1,m)cin>>a[i][j] ;}
    cin>>q;
    FOR(i,1,q)
    {
    	int  x,y,u,v,c ; 
    	cin>>x>>y>>u>>v>>c;
    	query[i]= {x,y,u,v,c}; 
    	d[x][y]+=c; 
    	d[x][v+1]-=c ; 
    	d[u+1][y]-=c ;
    	d[u+1][v+1]+=c;  
    }   
    FOR(i,1,n)
    {
    	FOR(j,1,m)
    	{
    		d[i][j] =d[i-1][j]+d[i][j-1]-d[i-1][j-1]+d[i][j]  ; 
    		a[i][j]+=d[i][j] ; 
    		M[i][j] = max({a[i][j],M[i-1][j],M[i][j-1]}); 
    	}
    }
    FORD(i,n,1)
    {
    	FORD(j,m,1)
    	{
    		D[i][j] = max({a[i][j],D[i+1][j],D[i][j+1]});
    	}
    }
    int ma =M[n][m] ; 
    int res= oo ; 
 	FOR(i,1,q)
 	{
 		int x=  query[i].x; 
 		int y= query[i].y; 
 		int u =query[i].u ; 
 		int v= query[i].v ;
 		int c= query[i].c; 
 		res=min(res,max({ma-c,M[x-1][m],M[n][y-1],D[1][v+1],D[u+1][1]}));
 	}   
 	cout<<res;
}
void xuly()
{

}
int main()
{
    IOS();  
    doc(); 
    xuly();
}
