#include<bits/stdc++.h>
using namespace std;

#define TASK "FRACPATH"

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
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct DL
{
	ll p , q ; 
	DL operator +(const DL&a)const
	{
		return DL{p+a.p,q+a.q};
	}
	bool operator ==(const DL&a)const
	{
		return p==a.p&&q==a.q;
	}
	bool operator <(const DL&b)const
	{
		ll x= p/q ;  
		ll y= b.p/b.q;
		ll u=  p%q ;  
		ll v= b.p%b.q ;  
		if(x<y)return 1;  
		else if(x==y) 
		{
			// cout<<u<<" "<<b.q<<" "<<v<<" "<<q<<endl;
			return u*b.q<v*q; 
			return (double)u/v <(double)q/b.q;
		}
		return 0 ;  
	}
} ; 
int n ;
ll p ,q; 
void doc()
{
 	cin>> p >>q ;    
}
void dfs(int id ,DL cur ,DL L , DL R , DL X  )
{
	// cout<<id<<" "<<cur.p<<" "<<cur.q<<" "<<L.p<<" "<<L.q<<" "<<R.p<<" "<<R.q<<endl;
	if(cur==X)
	{
		cout<<"\n";
		return ;
	}
	if(X<cur)
	{
		cout<<"L"; 
		dfs(id*2,L+cur,L,cur,X);
		// return ;
	}	
	else 
	{
		cout<<"R";
		dfs(id*2+1,R+cur,cur,R,X);
		// return ;
	}
}
void xuly()
{
	DL L = {0,1} ; 
	DL R = {1,0} ; 
	DL X = {p,q} ;
	DL cur = {1,1} ; 
    // cout<<(X<DL{3,4});
    // cout<<X.p<<" "<<X.q<<endl;
    dfs(1,cur,L,R,X);  
}
int main()
{
    IOS(); 
    int test ;
    cin>>test;  
    while(test--){
    	doc(); 
    	xuly();
    } 
    
}