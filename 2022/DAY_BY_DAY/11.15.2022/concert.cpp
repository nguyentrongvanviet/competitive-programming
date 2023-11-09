#include<bits/stdc++.h>
using namespace std;

#define TASK "concert"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#pragma CPP target("popcnt")
const int N =1e6+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

struct DL 
{
	ll l ,r , c; 	
	bool operator <(const DL&a)const
	{
		return r<a.r||(r==a.r&&l<a.l);
	}
};

int n , M ; 
vector<ll>a[N] ;
ll tmp = 0 ; 
ll s= 0 ; 
void doc()
{
 	cin>> n>> M ; 
 	FOR(i,1,n)
 	{
 		ll l , r , c; 
 		cin>>l>>r>>c;  
 		a[l].pb(c) ; 
 		a[r+1].pb(-c);
 	}
 	ll res=0 ; 
 	FOR(i,1,M)
 	{	
 		FOR(j,0,(int)a[i].size()-1)
 		{
 			ll x= a[i][j] ;
 			// ll x= 0 ;  
 			if(x<0)
 			{
 				x =-x; 
 				tmp-=x*(s-x);
 				s-=x; 
 			}
 			else 
 			{	
 				tmp+=x*s;
 				s+=x;
 			}
 			s=(s+sm)%sm;
 			tmp=(tmp+sm)%sm;
 		}
 		// cout<<tmp<<" "<<s<<endl;
 		res+=tmp;
 		res+=sm ; 
 		res%=sm;	
 	}
 	cout<<res;
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}