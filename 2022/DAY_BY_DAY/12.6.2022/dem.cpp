// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "dem"

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
ll sq(int a )
{
	return (ll)a*(ll)a ;
}
map<tuple<int,int,ll>,int>sl;
int n ; 
pii a[N] ;
void doc()
{
	cin>>n ; 
	FOR(i,1,n)
	{
		cin>>a[i].fi>>a[i].se;  		
	}
	ll res = 0 ; 
	FOR(i,1,n)
	{
		FOR(j,i+1,n)
		{
			int x= a[i].fi+a[j].fi; 
			int y= a[i].se+a[j].se;
			int dis= sq(a[i].fi-a[j].fi)+sq(a[i].se-a[j].se) ;
			res+= sl[{x,y,dis}];
			sl[{x,y,dis}]++; 
		}
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