#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =200+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n  , m ; 
pii a[N] ; 
ll f[N][N] ; 
void input()
{
    for(int i= 1;i<=n;i++)cin>>a[i].fi>>a[i].se; 
}		
void output()
{
	for(int i= 0 ;i<=n;i++)
	{
		for(int j = 0;j<=m;j++)
		{
			f[i][j] = inf ; 
		}
	}
	f[2][2] =0;
	for(int i= 3 ;i<=n;i++)
	{
		f[i][2]=(a[1].se-a[i].fi)*(a[1].se-a[i].fi) ; 
	}
	for(int i =2;i<=n;i++)
	{
		for(int j= 3 ;j<=min(i,m);j++)
		{
			for(int t = j-1;t<=i-1;t++)
			{
				f[i][j] = min(f[i][j],f[t][j-1]+(t==i-1?0:(a[t].se-a[i].fi)*(a[t].se-a[i].fi)));
			}
		}
	}
	cout<<f[n][m]<<'\n'; 
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    //cin>>t;
    while(cin>>n>>m)
    {
    	if(n==0&&m==0)break ; 
        input();
        output(); 
    }
    return 0;
}