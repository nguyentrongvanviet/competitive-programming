/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "B"

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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ,m ;
int a[N] ;
vi g[N] ; 
void doc()
{
    cin>> n>>m;  
    FOR(i,1,m)
    {
    	int x, y; 
    	cin>>x>>y;
    	g[x].pb(y) ; 
    	g[y].pb(x) ;  
    }
}
void xuly()
{
 	ll res= 0 ;
 	int cur= 0;
 	FOR(i,1,n)
 	{
 		int ma = 0  ; 
 		for(auto x : g[i])
 		{
 			if(x<=i&&x>=cur)ma= max(ma,x) ;
 		}	
 		cur =max(cur,ma+1);
 		res+=i-cur+1;
 	}
 	cout<<res<<'\n';
}
void clear()
{
	FOR(i,1,n)g[i].clear();
}
int main()
{
    IOS();  
    int test ;
    cin>>test ;
    while(test--)
    {
    	doc();
    	xuly() ;
    	clear() ;
    }
    return 0 ;
}	