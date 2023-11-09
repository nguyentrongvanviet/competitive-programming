#include<bits/stdc++.h>
using namespace std;

#define TASK "skyscrapper"

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
struct DL
{
	int val ; 
	int id ; 
	bool operator <  (const DL&a)const
	{
		return val>a.val; 
	}
};
int n , m ;
int a[N] , ans[N]  ; 
DL q[N] ;
int query[N] ; 
int dd[N] ;
int res[N] ;
void doc()
{
 	cin>> n >> m ; 
 	FOR(i,0,n+1)dd[i] = 0 ; 
 	FOR(i,1,n)cin>>a[i] ; 
 	FOR(i,1,n)
 	{
 		q[i] = {a[i],i};  
 	}
 	sort(q+1,q+n+1) ; 
 	FOR(i,1,m)
 	{
 		cin>>query[i];
 	}
 	int ans= 0  ;
 	int cur =1 ;
 	FORD(i,m,1)
 	{
 		while(cur<=n&&q[cur].val>query[i])
 		{
 			int pos = q[cur].id;  
 			dd[pos] =1 ; 
 			if(dd[pos-1]&&dd[pos+1])
 			{	
 				ans-- ;
 			}	
 			else 
 			{
 				if(dd[pos-1]==0&&dd[pos+1]==0)
 				{
 					ans++ ;
 				}
 			}
 			++cur; 
 		}
 		res[i]  = ans ;
 	}
 	FOR(i,1,m)cout<<res[i]<<"\n";
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
    cin>>t ; 
    while(t--)
    {
        doc();
    }
}