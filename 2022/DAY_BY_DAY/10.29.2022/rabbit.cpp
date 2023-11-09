#include<bits/stdc++.h>
using namespace std;

#define TASK "rabbit"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =300+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

struct bg 
{
	int x , y ; 
	ll val ; 
};
int n  , m ; 
ll a[N][N]; 
ll res= 0; 
int xx[] = {1,0,-1,0} ; 
int yy[] = {0,1,0,-1} ;
int dd[N][N]  ;
ll ma=-inf ;
struct cmp
{
	bool operator()(bg a , bg b )
	{
		return a.val<b.val; 
	}
};
int in(int x , int y)
{
	return (1<=x&&x<=n&&1<=y&&y<=m);
}
void doc()
{
 	cin>> n>> m; 
    priority_queue<bg,vector<bg>,cmp>q ; 
 	for(int i = 1;i<=n;i++)
 	{
 		for(int j= 1;j<=m;j++)
 		{
 			cin>>a[i][j] ;
            q.push({i,j,a[i][j]}); 	
 		}
 	}   
 	while(!q.empty())
 	{
 		int x = q.top().x ; 
 		int y = q.top().y ; 
 		ll val = q.top().val;
 		q.pop(); 
        if(dd[x][y])continue;
        dd[x][y] =1 ;
 		for(int i=0 ;i<4;i++)
 		{
 			int nx = x+xx[i] ; 
 			int ny=  y+yy[i] ; 
            if(dd[nx][ny]==1||in(nx,ny)==0)continue ;
            if(a[nx][ny]<a[x][y]-1)
            {
                res+=a[x][y]-1-a[nx][ny];
                a[nx][ny] =a[x][y]-1;
                q.push({nx,ny,a[nx][ny]});
            }
 		}
 	}
 	cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(TASK".inp","r"))
    {
        freopen(TASK".inp","r",stdin); 
        freopen(TASK".out","w",stdout); 
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