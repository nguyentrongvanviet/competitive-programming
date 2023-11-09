#include<bits/stdc++.h>
using namespace std;

#define TASK "L_shape"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =1e3+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n , m  ; 
ll a[N][N] ; 
ll trai[N][N] ; 
ll phai[N][N] ; 
ll tren[N][N] ; 
ll duoi[N][N] ; 
ll res=0  ;
ll value(ll x,  ll y )
{
	ll ans =0; 
	if(x*2<=y)
	{
		ans+=x; 
	}
	else 
	{
		ans+=y/2;
	}
	if(y*2<=x)
	{
		ans+=y;
	}
	else 
	{
		ans+=x/2;
	}
	ans-=2;
	return ans; 
}
void doc()
{
   	cin>>n >> m; 
   	for(int i= 1;i<=n;i++)
   	{
   		for(int j= 1 ;j<=m;j++)
   		{
   			cin>>a[i][j];
   			if(a[i][j]==0)continue ;
   			trai[i][j] = 1+trai[i][j-1] ; 
   			tren[i][j] = 1+tren[i-1][j];
   		}
   	} 
   	for(int i =n;i>=1;i--)
   	{
   		for(int j= m;j>=1;j--)
   		{
   			if(a[i][j]==0)continue ; 
   			phai[i][j] = 1+phai[i][j+1] ; 
   			duoi[i][j] =1+duoi[i+1][j];
   		}
   	}
   	for(int i= 1;i<=n;i++)
   	{
   		for(int j= 1; j<=m;j++)
   		{
   			if(a[i][j]==0)continue;
   			int x=  trai[i][j] ; 
   			int y=phai[i][j] ; 
   			int t=tren[i][j]  ; 
   			int d= duoi[i][j] ; 
   			if(x>=2&&t>=2)
   			{
   				res+=value(x,t) ; 
   			}
   			if(x>=2&&d>=2)
   			{
   				res+=value(x,d) ; 
   			}
   			if(y>=2&&t>=2)
   			{
   				res+=value(y,t) ; 
   			}
   			if(y>=2&&d>=2)
   			{
   				res+=value(y,d); 
   			}
   		}
   	}
   	cout<<res;
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