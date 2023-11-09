#include<bits/stdc++.h>
using namespace std;

#define TASK "KNIGHT"
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
const int N =3e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n  , m  ;  
int far[N] ;  
int res[N] ;
int get(int u)
{
	return far[u]==u ? u:far[u] = get(far[u]);
} 	
void doc()
{
 	cin>> n >> m; 
 	FOR(i,1,n)
 	{
 		far[i] = i ; 
 		res[i] = 0 ; 
 	}
 	far[n+1]=n+1;
 	FOR(i,1,m)
 	{
 		int l , r , x ; cin>>l>>r>>x; 
 		int it= l ; 
 		while(it<=r)
 		{
 			it= get(it);
 			if(it>r)continue;
 			
 			if(it<x)
 			{
 				res[it] =x;
 				far[it] =x;   
 			}
 			else if(it>x)
 			{
 				res[it] = x ; 
 				far[it] = get(i+1);
 			}
 			++it;
 		}	
 	}	   	
 	FOR(i,1,n)
 	{
 		cout<<res[i]<<" ";
 	}
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