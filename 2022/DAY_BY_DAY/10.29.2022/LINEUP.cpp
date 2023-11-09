#include<bits/stdc++.h>
using namespace std;

#define TASK "LINEUP"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =2e3+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n ; 
ll f[N][N] ; 
void doc()
{
 	cin>> n; 
 	for(int i=1 ;i<=n;i++)
 	{
 		int u  ; cin>> u ;  
 	}   
 	f[0][0] =1 ;
 	for(int i=1 ;i<=n;i++)
 	{
 		for(int j= 1;j<=i;j++)
 		{
 			f[i][j] = (f[i-1][j-1]+(i-1)*f[i-1][j]%sm)%sm;
 		}
 	}
 	C[0][0]=1 ; 
 	for(int i= 1;i<=n;i++)
 	{
 		C[i][0 ]= 1; 
 		for(int j =1 ;j<=i;j++)
 		{
 			C[i][j] =(C[i-1][j-1]+C[i-1][j])%sm;
 		}
 	}
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