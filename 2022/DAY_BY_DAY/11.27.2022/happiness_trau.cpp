#include<bits/stdc++.h>
using namespace std;

#define TASK "happiness"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".ANS","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct DL
{
	ll x, y ; 
};
int n  ; 
ll W; 
ll res=0  ; 
ll a[N] , b[N] ; 
void create(int l ,int r )
{
	vector<DL>ans ; 
	ans.pb({0,0});
	FOR(i,l,r)
	{
		vector<DL>tmp ; 
		for(auto it: ans)
		{
			tmp.pb({it.x+a[i],it.y}) ;
			tmp.pb({it.x,it.y+b[i]}) ; 
			tmp.pb({it.x+a[i],it.y+b[i]}); 
		}
		ans=tmp ;
	}
	FOR(i,0,ans.size()-1)
	{
		if(ans[i].x>=W&&ans[i].y>=W)res++;
	} 
}

void doc()
{
   	cin>> n>>W;
   	FOR(i,1,n)cin>>a[i] ; 
   	FOR(i,1,n)cin>>b[i] ;
   	res=0 ; 
   	create(1,n); 
   	cout<<res<<"\n";
}	
void xuly()
{
    
}
int main()
{
    IOS();  
    int test; 
    cin>>test; 
    while(test--)
    {
    	doc(); 
    	xuly();
    }
    
}