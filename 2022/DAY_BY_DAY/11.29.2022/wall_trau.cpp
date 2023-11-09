#include<bits/stdc++.h>
using namespace std;

#define TASK "wall"

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

int n ,d ; 
int a[N] ; 
void doc()
{
	int res=oo ;
   	cin>>n>>d; 
   	FOR(i,1,n)
   	{
   		cin>>a[i] ; 
   	}
   	FOR(i,0,(1<<n)-1)
   	{	
   		vector<int>q ;
   		FOR(j,0,n-1)
   		{
   			if(i>>j&1)
   			{
   				q.pb(a[j+1]);
   			}
   		}
   		int t= 0 ; 
   		for(int j=1 ;j<q.size();j++)
   		{
   			if(q[j]!=q[j-1])
   			{
   				t++ ;
   			}
   		}
   		if(t<=d)
   		{
   			res=min(res,n-__builtin_popcount(i));
   		}
   	}
   	cout<<res<<"\n";
}
void xuly()
{
    
}
int main()
{
    IOS(); 
    int test ;
    cin>>test ; 
    while(test--)
    {
    	doc(); 
    	xuly();
    } 
    
}