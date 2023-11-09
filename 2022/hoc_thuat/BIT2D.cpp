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
const int N =5e2+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
#define int long long 
int n  , m , q; 
int a[N][N]  ; 
ll bit[N][N][4]; 

void up(int x , int y , int val   )
{
	for(int i = x ;i<=n;i+=i&-i)
	{
		for(int j= y;j<=m;j+=j&-j)
		{
			bit[i][j][0] +=val ; 
			bit[i][j][1] +=x*val;  
			bit[i][j][2] +=y*val; 
			bit[i][j][3] +=x*y*val; 
		}
	}
}
void update(int x , int y , int u , int v,  int val )
{
	up(x,y,val); 
	up(x,v+1,-val) ; 
	up(u+1,y,-val) ;
	up(u+1,v+1,val) ; 
}

ll get(int x ,int y )
{
	ll ans =0  ;
	for(int i =x ;i;i-=i&-i)
	{
		for(int j= y;j;j-=j&-j)
		{		
			ans+=(x+1)*(y+1)*bit[i][j][0]-(x+1)*(bit[i][j][2])-(y+1)*(bit[i][j][1])+bit[i][j][3];
		}
	}
	return ans ; 
}	
ll query(int x , int y,int u , int v  )
{
	return get(u,v)+get(x-1,y-1)-get(x-1,v)-get(u,y-1);
}
void input()
{
	cin>> n>> m>> q;  
	for(int i =1 ;i<=n;i++)
	{
		for(int j= 1;j<=m;j++)
		{
			cin>>a[i][j] ; 
		}
	}	
}
void init()
{
	for(int i= 1; i<=n;i++)
	{
		for(int j= 1;j<=m;j++)
		{
			update(i,j,i,j,a[i][j]); 
		}
	}
}
void output()
{
 	init();
 	while(q--)
	{
		int t , x , y , u ,v , val ; 
		cin>>t>>x>>y>>u>>v; 
		if(t==2)
		{
			cout<<query(x,y,u,v)<<"\n"; 
		}
		else 
		{
			cin>>val; 
			update(x,y,u,v,val); 
		}
	}
}
 main()
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