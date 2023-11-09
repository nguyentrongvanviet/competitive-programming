// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "allow"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  
struct DL
{
	int h , l , r;  
};
int xx[] = {-1,-1,-1,0,0,1,1,1} ; 
int yy[] = {-1,0,1,-1,1,-1,0,1} ; 
int n  , x, y,  u , v; 
DL a[N] ;
map<pii,int>ok; 
map<pii,int>dd;
void doc()
{
 	cin>>x>>y>>u>>v ;
 	cin>> n ;
 	FOR(i,1,n)
 	{
 		cin>>a[i].h>>a[i].l>>a[i].r;  
 		FOR(j,a[i].l,a[i].r)
 		{
 			ok[{a[i].h,j}]= 1; 
 		}
 	}    
 	queue<pii>q ; 
 	q.push({x,y}) ; 
 	dd[{x,y}] =1;
 	while(!q.empty())
 	{
 		int x = q.front().fi ; 
 		int y =q.front().se ; 
 		q.pop() ; 
 		for(int i = 0 ;i<8;i++)
 		{
 			int nx = x+xx[i] ; 
 			int ny = y +yy[i] ; 
 			if(ok.find({nx,ny})==ok.end()||dd.find({nx,ny})!=dd.end())continue ; 
 			dd[{nx,ny}] = dd[{x,y}]+1;
 			if(nx==u&&ny==v)
 			{	
 				cout<<dd[{nx,ny}]-1;
 				return ; 
 			}
 			q.push({nx,ny}); 
 		}
 	}  
 	cout<<-1<<"\n";
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