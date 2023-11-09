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
const int N =105+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

struct bg 
{	
	int X, V ; 
	bool operator<(const bg&a)const
	{
		return V>a.V;
	}
};	
int n ; 
int a[N] , b[N] ;
pii f[N][N*N];
int sum =0 ;
void input()
{
 	cin>> n ; 
 	for(int i= 1;i<=n;i++)
 	{
 		cin>>a[i]; 
 		sum+=a[i]; 
 	}    
 	for(int i=1;i<=n;i++)
 	{
 		cin>>b[i]; 
 	}
}
void output()
{
	for(int i = 0;i<=n;i++)
	{
		for(int j= 0 ;j<=sum;j++)
		{
			f[i][j] = {oo,oo};
		}
	}
	f[0][0]={0,sum};
	for(int i=1 ;i<=n;++i)
	{	
		for(int j = 0 ;j<=sum;j++)
		{
			f[i][j] = {f[i-1][max(0,j-b[i])].first+1,f[i-1][max(0,j-b[i])].second-a[i]};
			f[i][j] = min(f[i-1][j],f[i][j]);
		}
	}
	cout<<f[n][sum].fi<<" "<<f[n][sum].se;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    // freopen("i.txt","r",stdin); 
    // freopen("o.txt","w",stdout); 
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