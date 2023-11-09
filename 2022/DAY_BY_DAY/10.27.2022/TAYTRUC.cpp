#include<bits/stdc++.h>
using namespace std;

#define TASK "TAYTRUC"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =2e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n  , m ; 
ll f[N][505] ; 
ll a[N] ; 
void doc()
{
 	cin>>n>> m;    
 	for(int i =1 ;i<=n;i++)cin>>a[i] ; 
 	for(int i =0;i<=n;i++)
 	{
 		for(int j = 0 ; j<=m;j++)
 		{
 			f[i][j] = -oo ;  
 		}
 	}
 	f[1][1] =a[1]; 
 	f[1][0] =0; 
 	for(int i=2  ;i<=n;i++)
 	{
 		f[i][0] =f[i-1][0];
 		for(int  j=1;j<=m;j++)
 		{
			f[i][0] =max(f[i][0],f[max(0,i-j)][j]);
 		}
 		for(int j =1;j<=m;j++)
 		{
 			f[i][j] =f[i-1][j-1]+a[i]  ;
 		}
 	}
 	cout<<f[n][0];
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