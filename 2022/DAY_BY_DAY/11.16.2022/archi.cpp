#include<bits/stdc++.h>
using namespace std;

#define TASK "archi"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

const int N =2e3+100,cs=1010,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7 ,inf = 1e17 ;
int n ; 
int tung[N][N] ; 
int hoanh[N][N] ;
int dd[N][N] ;
int onepoint[N][N];
int b[N][N] ; 
int res=0;
void bfs(int i , int j)
{
	int tmp= 0 ; 
	queue<pii> q; 
	q.push({i,j}); 
	dd[i][j]=1;  
	while(!q.empty())
	{
		int i= q.front().fi ; 
		int j = q.front().se ; 
		tmp+=(b[i][j]&1);
		q.pop() ; 
		if(dd[i-1][j]==0&&hoanh[i-1][j])
		{
			dd[i-1][j]=1 ; 
			q.push({i-1,j});
		}
		if(dd[i+1][j]==0&&hoanh[i][j])
		{
			dd[i+1][j] = 1; 
			q.push({i+1,j}) ; 
		}
		if(dd[i][j-1]==0&&tung[i][j-1])
		{
			dd[i][j-1]=1;
			q.push({i,j-1});
		}
		if(dd[i][j+1]==0&&tung[i][j])
		{
			dd[i][j+1] = 1; 
			q.push({i,j+1});
		}
	}
	if(tmp==0)++res;
	else res+=tmp/2;
}
void doc()
{
    cin>> n  ; 
    FOR(i,1,n)
    {
    	int x , y , u ,v ; 
    	cin>>x>>y>>u>>v ; 
    	x+=cs; 
    	y+=cs;
    	u+=cs;
    	v+=cs;
    	if(x==u&&y==v)
    	{
    		onepoint[x][y] =1 ; 
    		continue ;
    	}
    	if(x==u)
    	{
    		if(y>v)swap(y,v);
    		// cout<<x<<" "<<y<<" "<<u<<" "<<v<<"\n"; 
    		tung[x][y]++;
    		tung[u][v]--;
    	}
    	else 
    	{
    		if(x>u)swap(x,u); 
    		// cout<<x<<" "<<y<<" "<<u<<" "<<v<<"\n";
    		hoanh[x][y]++;
    		hoanh[u][v]--;
    	}
    }
    FOR(i,1,N-4)
    {
    	FOR(j,1,N-4)
    	{
    		tung[i][j]+=tung[i][j-1] ; 
    		hoanh[i][j]+=hoanh[i-1][j];
    	}
    }
    FOR(i,1,N-4)
    {
    	FOR(j,1,N-4)
    	{
    		if(tung[i][j])
    		{
    			b[i][j]++; 
    		}
    		if(tung[i][j-1])
    		{
    			b[i][j]++;
    		}
    		if(hoanh[i][j])
    		{
    			b[i][j]++;
    		}
    		if(hoanh[i-1][j])
    		{
    			b[i][j]++;
    		}    		// cout<<b[i][j]<<" ";
    	}
    }
    FOR(i,1,N-4)
    {
    	FOR(j,1,N-4)
    	{
    		if(onepoint[i][j]&&b[i][j]==0)
    		{
    			res++ ;
    		}
    		else if(dd[i][j]==0&&b[i][j])
    		{
    			bfs(i,j);
    		}
    	}
    }
    cout<<res;
}

int main()
{	
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
    // cin>>t ; 
    while(t--)
    {
        doc();
    }
}