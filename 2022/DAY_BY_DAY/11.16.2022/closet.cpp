#include<bits/stdc++.h>
using namespace std;

#define TASK "closet"

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
ll sq(ll a ){return a*a;}
struct pt 
{
	ll x, y ;  
	int id ; 
	pt(){}
	pt(ll _x ,ll _y,int _id )
	{
		x=_x ; 
		y=_y ;
		id =_id;
	}
	pt operator -(const pt&a)const
	{
		return pt{x-a.x,y-a.y,0}; 
	}
	ll operator *(const pt&a)const
	{
		return x*a.y-y*a.x;
	}
	bool operator <(const pt&a)const
	{
		return x<a.x ||(x==a.x&&y<a.y);
	}
};	
ll dis(pt a, pt b)
{
	return sq(a.x-b.x)+sq(a.y-b.y);
}
struct sx_theo_y 
{
	bool operator ()(pt a , pt b )
	{
		if(a.y!=b.y)return a.y<b.y;  
		return a.x<b.x;
	}
};
int n ;
pt a[N];  
void doc()
{
	cin>> n  ; 
	FOR(i,1,n)cin>>a[i].x>>a[i].y,a[i].id=i;  
}
void closet_pair()
{
	sort(a+1,a+n+1);
	map<pt,sx_theo_y>s ;	
	ll res= dis(a[1],a[2]);
	int mot = 1 ; 
	int hai = 2 ; 
	FOR(i,1,n)
	{
		ll x = a[i].x ; 
		ll y = a[i].y ; 
		ll d= sqrt(res); 
		pt cur = {-inf,y-d,0}; 
		while(1)
		{
			auto it= upper_bound(s.begin(),s.end(),cur,sx_theo_y());
			if(it==s.end())break; 
			cur = *it ;
			if(cur.y>y+d)break; 
			if(cur.x<x-d)
			{
				s.erase(it); 
				continue ;
			}
			if(res>dis(cur,a[i]))
			{
				mot =a[i].id ; 
				hai = cur.id ;
				res=min(res,dis(cur,a[i]));
			}
		}
		s.insert(a[i]);
	}
 	if(mot>hai)swap(mot,hai);
	cout<<mot-1<<" "<<hai-1<<" ";
	cout<<setprecision(6)<<fixed ; 
	cout<<sqrt(res);
	// cout<<res;
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