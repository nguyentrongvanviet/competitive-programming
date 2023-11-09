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
const int N =5e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n  , m  ;
int f[N][N][3] ;
int a[N] ; 
int b[N] ; 
void input()
{
    cin>> n>> m ;
    for(int i=1 ;i<=n;i++)
    {
    	cin>>a[i] ;  
    }
    for(int i=1 ;i<=m;i++)
    {
    	cin>>b[i ]; 
    }
}
void output()
{
    for(int i=1 ;i<=n;i++)
    {
    	for(int j= 1 ;j<=m;j++)
    	{
    		f[i][j][1]= max(f[i-1][j][1],f[i][j-1][1]) ; 
    		f[i][j][2]=max(f[i-1][j][2],f[i][j-1][2] ) ;  
    		if(a[i]<=b[j])
    		{
    			f[i][j][1] =max(f[i][j][1],f[i-1][j-1][2]+1);
    		}
    		if(a[i]>=b[j])
    		{
    			f[i][j][2] =max(f[i][j][2],f[i-1][j-1][1]+1);
    		}
    	}
    }
    cout<<max(f[n][m][1],f[n][m][2]);
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