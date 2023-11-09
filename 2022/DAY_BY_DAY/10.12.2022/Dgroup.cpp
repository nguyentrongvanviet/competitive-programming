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
const int N =4e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n , m ; 
int s[N][N] ;  
int f[N][2];void input()
{
 	cin>>n>>m; 
 	for(int i=1 ;i<=n;i++)
 	{
 		for(int j= 1 ;j<=n;j++)
 		{
 			char u ; 
 			cin>> u ; 
 			int c=  u-'0';
 			s[i][j]=s[i-1][j]+s[i][j-1]+c-s[i-1][j-1];
 		}
 	}   
}
int sum(int u, int v   , int x  , int y )
{
	return (s[x][y]-s[u-1][y]-s[x][v-1]+s[u-1][v-1])/2;
}
void output()
{
	for(int i =1 ;i<=n;i++)
	{
		for(int j= 1;j<=m;j++)
		{
			f[i][j] = oo ;
		}
	}
	for(int i= 1;i<=n;i++)
	{
		f[i][1] =sum(i,i,1,1);
	}
   	for(int j =2 ;j<=m;j++)
   	{
   		for(int  i =j ;i<=n;i++)
   		{
   			for(int ii=i-1 ;ii>=j-1;ii--)
   			{
   				f[i][j] =min(f[i][j],f[ii][j-1]+sum(i, i, ii+1 , ii+1 ));
   			}
   		}
   	}
   	cout<<f[n][m];
}
void tinh(int l , int r , int t , int p)
{
	if(l>r)return ;  
	int mid=(l+r)/2; 	
	int id =0  ; 
	f[mid][1]=oo;
	for(int i= t;i<=min(mid,p);i++)
	{
		int val  =f[i-1][0] +sum(i,i,mid,mid);
		if(val<f[mid][1])
		{
			f[mid][1] =val;
			id = i ;
		}		
	}
	tinh(l,mid-1,t,id) ;  
	tinh(mid+1,r,id,p) ;
}
void subfull()
{
	for(int i =1 ;i<=n;i++)
	{
		f[i][0] =sum(1,1,i,i);
	}
	for(int i=2 ;i<=m;i++)
	{
		tinh(1,n,1,n);
		for(int j =1 ;j<=n;j++)
		{
			f[j][0]=f[j][1] ; 
		}
	}
	cout<<f[n][0];
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
        subfull(); 
    }
    return 0;
}