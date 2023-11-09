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
const int N =1e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n , k  ;
ll f[N][N];
ll a[N] , s[N] ; 
void input()
{
 	cin>> n>>  k ; 
}
ll binpow(ll a,ll n )
{
	if(n==0)return 1 ; 
	ll b= binpow(a,n/2) ; 
	if(n&1)
	{
		return b*b%sm*a%sm ; 
	}
	else 
	{
		return b*b%sm;
	}
}
void output()
{
    a[0]=1 ; 
 	s[0]=1 ; 
 	for(int i= 1;i<=n;i++)
 	{
 		a[i] =a[i-1]*10%k ;
 		s[i] =(s[i-1]+a[i])%k; 
 	}
 	for(int i= 1 ;i<=7;i++)
 	{
 		f[1][i*s[n-1]%k]++;
 	}
 	for(int i=2;i<=n;i++)
 	{
 		for(int j= 0  ;j<k;j++)
 		{
 			for(int t= 0 ;t<=7;t++)
 			{
 				f[i][j] =(f[i][j]+f[i-1][(j-i*t%k*s[n-i]%k+k)%k])%sm; 
 			}
 		}
 	}   
 	ll res= 0 ;
 	for(int i= 0 ;i<k;i++)
 	{
 		for(int j= i+1;j<k;j++)
 		{
 			int cl = (k-(i+j)%k)%k ; 
 			if(cl>j)
 			{
 				res=(res+f[n][i]*f[n][j]%sm*f[n][cl]%sm)%sm;
 			}
 		}
 	}
 	for(int i=0 ;i<k;i++)
 	{
 		int cl = (k-(2*i)%k)%k;
 		// cout<<i<<" "<<cl<<endl;
 		if(cl==i)
 		{
 			res=(res+ f[n][i]*(f[n][i]-1)%sm*(f[n][i]-2)%sm*binpow(6,sm-2)%sm)%sm;
 		}	
 		else 
 		{
 			res=(res+f[n][i]*(f[n][i]-1)%sm*binpow(2,sm-2)%sm*f[n][cl]%sm)%sm;
 		}
 	}
 	cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("TUPLE.INP","r",stdin); 
    freopen("TUPLE.OUT","w",stdout); 
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