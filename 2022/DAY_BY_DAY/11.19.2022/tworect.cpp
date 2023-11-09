#include<bits/stdc++.h>
using namespace std;

#define TASK "tworect"

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

const int N =1e3+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n  ,m ;
int a[N][N]  ;
int mi[N]  ,ma[N] ; 
int up[N]  ;
int down[N] ; 
int leftt[N] ; 
int rightt[N] ; 
int l[N][N] , r[N][N] , u[N][N] , d[N][N];
void doc()
{
	cin>>n>>m;
	int t= 0 ;    
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			t+=(a[i][j]==0);
			cin>>a[i][j] ; 
		}
	}
	if(t<2)
	{
		cout<<0 ; 
		return ;
	}
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			if(a[i][j]==1)
			{
				l[i][j] = u[i][j] = 0 ;
			}
			else 
			{
				l[i][j] = l[i][j-1]+1; 
				u[i][j] = u[i-1][j]+1; 
			}
		}
	}
	FORD(i,n,1)
	{
		FORD(j,m,1)
		{
			if(a[i][j]==1)
			{
				r[i][j] = d[i][j] = 0 ;
			}
			else
			{
				r[i][j] = r[i][j+1]+1;  
				d[i][j] = d[i+1][j]+1;
			}
		}
	}
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			if(a[i][j]==1)
			{
				l[i][j] = u[i][j] = d[i][j]=r[i][j]= -oo ;
			}
		}
	}
	stack<int>st;  
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			while(!st.empty()&&u[i][st.top()]>=u[i][j])
			{
				st.pop() ; 
			}
			if(st.empty())
			{
				mi[j] = 1 ; 
			}
			else 
			{
				mi[j] = st.top()+1; 
			}
			st.push(j); 
		}
		while(!st.empty())st.pop() ; 
		FORD(j,m,1)
		{	
			while(!st.empty()&&u[i][st.top()]>=u[i][j])
			{
				st.pop() ; 
			}
			if(st.empty())
			{
				ma[j] = m ; 
			}
			else 
			{
				ma[j] = st.top()-1; 
			}
			st.push(j); 
		}
		while(!st.empty())st.pop() ; 
		up[i]=up[i-1];
		FOR(j,1,m)
		{
			if(a[i][j]==0)up[i] =max(up[i],u[i][j]*(ma[j]-mi[j]+1));
		}
	}	
	FORD(i,n,1)
	{
		FOR(j,1,m)
		{
			while(!st.empty()&&d[i][st.top()]>=d[i][j])
			{
				st.pop() ; 
			}
			if(st.empty())
			{
				mi[j] = 1 ; 
			}
			else 
			{
				mi[j] = st.top()+1; 
			}
			st.push(j); 
		}
		while(!st.empty())st.pop() ; 
		FORD(j,m,1)
		{	
			while(!st.empty()&&d[i][st.top()]>=d[i][j])
			{
				st.pop() ; 
			}
			if(st.empty())
			{
				ma[j] = m ; 
			}
			else 
			{
				ma[j] = st.top()-1; 
			}
			st.push(j); 
		}
		while(!st.empty())st.pop() ; 
		down[i] = down[i+1] ;
		FOR(j,1,m)
		{
			// cout<<i<<" "<<d[i][j]<<" "<<mi[j]<<" "<<ma[j]<<"\n";
			if(a[i][j]==0)down[i] =max(down[i],d[i][j]*(ma[j]-mi[j]+1));
		}
		// return ;
	}	
	FOR(j,1,m)
	{
		FOR(i,1,n)
		{
			while(!st.empty()&&l[st.top()][j]>=l[i][j])
			{
				st.pop() ; 
			}
			if(st.empty())
			{
				mi[i] = 1 ; 
			}
			else 
			{
				mi[i] = st.top()+1; 
			}
			st.push(i); 
		}
		while(!st.empty())st.pop() ; 
		FORD(i,n,1)
		{	
			while(!st.empty()&&l[st.top()][j]>=l[i][j])
			{
				st.pop() ; 
			}
			if(st.empty())
			{
				ma[i] = n ; 
			}
			else 
			{
				ma[i] = st.top()-1; 
			}
			st.push(i); 
		}
		while(!st.empty())st.pop() ; 
		leftt[j] =leftt[j-1];
		FOR(i,1,n)
		{
			// cout<<i<<" "<<l[i][j]<<" "<<mi[i]<<" "<<ma[i]<<endl;
			if(a[i][j]==0)leftt[j] =max(leftt[j],l[i][j]*(ma[i]-mi[i]+1));
		}
		// return ;
		// cout<<leftt[j]<<"\n";
	}
	FORD(j,m,1)
	{
		FOR(i,1,n)
		{
			while(!st.empty()&&r[st.top()][j]>=r[i][j])
			{
				st.pop() ; 
			}
			if(st.empty())
			{
				mi[i] = 1 ; 
			}
			else 
			{
				mi[i] = st.top()+1; 
			}
			st.push(i); 
		}
		while(!st.empty())st.pop() ; 
		FORD(i,n,1)
		{	
			while(!st.empty()&&r[st.top()][j]>=r[i][j])
			{
				st.pop() ; 
			}
			if(st.empty())
			{
				ma[i] = n ; 
			}
			else 
			{
				ma[i] = st.top()-1; 
			}
			st.push(i); 
		}
		while(!st.empty())st.pop() ; 
		rightt[j] = rightt[j+1];
		FOR(i,1,n)
		{
			// cout<<j<<" "<<r[i][j]<<" "<<mi[i]<<" "<<ma[i]<<"\n";
			if(a[i][j]==0)rightt[j] =max(rightt[j],r[i][j]*(ma[i]-mi[i]+1));
		}
		// return ; 
		// cout<<rightt[j]<<"\n";
	}
	int res= 0; 
	FOR(i,1,n-1)
	{
		res=max(res,up[i]+down[i+1]) ; 
	}
	FOR(i,1,m-1)
	{
		res=max(res,leftt[i]+rightt[i+1]);
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