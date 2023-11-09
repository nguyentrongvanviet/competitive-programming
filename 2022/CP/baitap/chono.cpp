#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define sz(a) (int)a.size() 
#define all(a) (a.begin(),a.end())
const int N =1e4+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
ll f[N][(1<<5)+6];
int a[6][N] ; 
ll sum(int c , int bit )
{
	ll ans = 0 ; 
	for(int i = 0;i<5;i++)
	{
		if(bit&(1<<i))
		{
			ans+=a[i+1][c]; 
		}
	}
	return ans ; 
}
void input()
{
    cin>> n ; 
    for(int i= 1;i<=5;i++)
    {
    	for(int j= 1;j<=n;j++)
    	{
    		cin>>a[i][j] ; 
    	}
    }
}
void output()
{
    for(int i=1 ;i<=n;i++)
   	{
   		for(int j =0;j<(1<<5);j++)
   		{
   			f[i][j] = -inf ; 
   		}
   	}
    for(int i=1;i<=n;i++)
    {
    	for(int j= 0 ;j<(1<<5);j++)
    	{
    		for(int t =0 ;t<(1<<5);t++)
    		{
    			if((j&t)==0)
    			{
    				f[i][j] = max(f[i][j],f[i-1][t]+sum(i,j));

    			}
    		}
    	}

    }
    ll res=0  ;
    for(int i= 0;i<(1<<5);i++)
    {
    	res=max(res,f[n][i]); 
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}