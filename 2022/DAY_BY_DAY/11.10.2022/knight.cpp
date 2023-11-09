#include<bits/stdc++.h>
using namespace std;

#define TASK "knight"

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
#define pvvi pair<vector<vector<int>>,int> 
#define vvi vector<vector<int>> 
#define pvvipii pair<vvi,pii>
const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n ; 
map<vvi,int>dd ; 
int xx[] = {-2,-2,-1,1,2,2,1,-1}; 
int yy[] = {-1,1,2,2,1,-1,-2,-2};
bool in(int x , int y )
{
	return 0<=x&&x<=4&&0<=y&&y<=4;
}
void doc()
{
	vvi status(5,vector<int>(5,0));
	vvi ans(5,vector<int>(5,2));
	FOR(i,1,4)
	{
		FOR(j,0,i-1)
		{
			ans[i][j] = 1;  
		}
	}
	ans[2][2]= 0;
	ans[3][3] =1 ; 
	ans[4][4] =1 ;
	
	int  zx,zy ;
	FOR(i,0,4)
	{
		string s ; 
		getline(cin,s);
		FOR(j,0,4)
		{	
			if(s[j]=='0') 
			{
				status[i][j]  = 1 ; 
			}
			else if(s[j]=='1')
			{	
				status[i][j] =2 ;
			}	 
			else 
			{
				zx= i ; 
				zy =j ;
				status[i][j] = 0 ;
			}
		}
	} 
	queue<pvvipii>q;
	dd.clear();  
	if(status==ans)
	{
		cout<<0; 
		return; 
	}
	q.push({status,{zx,zy}}) ; 
	dd[status] = 0 ;
	// int u = 1 ; 
	while(!q.empty())
	{
		vvi tt =q.front().fi;
		pii otrong = q.front().se ;
		q.pop();
		int x = otrong.fi ; 
		int y = otrong.se ; 
		int t= dd[tt] ; 
		if(t==10)continue;
		FOR(i,0,7)
		{
			int nx = x+xx[i] ; 
			int ny = y+yy[i] ;  
			if(in(nx,ny)==0)continue ; 
			swap(tt[nx][ny],tt[x][y]);
			if(dd.find(tt)==dd.end())
			{ 
				if(tt==ans)
				{
					cout<<t+1<<"\n" ;
					return ; 
				}
				dd[tt]=t+1;
				q.push({tt,{nx,ny}});
			}
			swap(tt[nx][ny],tt[x][y]);
		}
	}
	// cout<<u<<" ";
	cout<<"123456789"<<"\n";
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
    cin>>t; 
    string s; 
    getline(cin,s);
    while(t--)
    {
        doc();
    }
}