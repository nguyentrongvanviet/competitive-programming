#include<bits/stdc++.h>
using namespace std;

#define TASK ""

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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
ll sq(ll a )return a*a ;
struct pt 
{
	ll x ,y ;  
	pt(){}
	pt(ll _x  , ll_ y )
	{
		x =_x ; 
		y =_y ; 
	} 
	bool operator <(const pt&a)const
	{
		return x<a.x||(x==a.x||y<a.y);
	}
	bool operator *(const pt&a)const
	{
		return x*a.y-y*a.x ;
	}
};
ll kc(pt a , pt b)
{

}
int n ; 
pt a[N]  ; 
set<pt>s ; 
void doc()
{
    cin>> n;  
    FOR(i,1,n)cin>>a[i].x>>a[i].y; 
}
void closet_pair() 
{
	set<pt>::iterator::
	sort(a+1,a+n+1) ;
}	

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
    // cin>>t ; 
    while(t--)
    {
        doc();
        closet_pair();
    }
}