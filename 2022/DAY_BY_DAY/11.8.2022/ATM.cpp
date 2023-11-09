#include<bits/stdc++.h>
using namespace std;

#define TASK "ATM"

#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b) for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i = a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

const int N =405+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n  , k;  
int a[N] ; 
bool f[N][N] ;
void doc()
{
 	cin>> n >> k; 
 	FOR(i,1,n)cin>>a[i];
 	f[0][0] =1 ;
 	FOR(i,1,n)
 	{
 		FORD(j,k,0)
 		{
 			FORD(t,k,0)
 			{
 				if(f[j][t])
 				{
 					if(j+a[i]<=k)
 					{
 						f[j+a[i]][t] = 1; 
 					}
 					if(t+a[i]<=k)
 					{
 						f[j][t+a[i]]=1; 
 					}
 				}
 			}
 		}
 	}
	int res=0 ; 
	vector<int>q; 
	FOR(i,0,k)
	{
		if(f[i][k-i])
		{
			res++ ;
			q.pb(i); 
		}
	}
	cout<<res<<"\n";
	FOR(i,0,q.size()-1)cout<<q[i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
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