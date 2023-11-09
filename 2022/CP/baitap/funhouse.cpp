#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second

const int N =1e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n , m;  
char a[N][N] ; 
ll res= 0 ; 
int xx[] ={-1,-1,-1,0,0,0,1,1,1}; 
int yy[] ={-1,0,1,-1,0,1,-1,0,1};
void inp()
{
 	cin>>n>>m ;
 	for(int i= 1 ;i<=n;i++)
 	{
 		for(int j= 1;j<=m;j++)
 		{
 			cin>>a[i][j] ;  
 		}
 	}
 	for(int i= 1;i<=n;i++)
 	{
 		for(int j= 1;j<=m;j++)
 		{
 			if(a[i][j]=='#')
 			{
 				for(int t = 0;t<9;t++)
 				{
 					int ni = i+xx[t] ; 
 					int nj = j+yy[t];
 					if(a[ni][nj]=='#')
 					{
 						res++ ; 
 					}
 				}
 				res--;
 			}
 		}
 	}    
 	res/=2; 
 	int ans =0 ; 
 	for(int i =1;i<=n;i++)
 	{
 		for(int j= 1;j<=m;j++)
 		{
 			if(a[i][j]=='#')continue;
 			int ma= 0 ;   
 			for(int t = 0 ;t<9;t++)
 			{
 				int ni =  i+xx[t] ; 
 				int nj = j+yy[t]; 
 				if(a[ni][nj]=='#')
 				{
 					ma++ ; 
 				}
 			}
 			ans=max(ans,ma) ; 
 		}
 	}
 	cout<<res+ans; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    while(t--)
    {
        inp();
    }
    return 0;
}