/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "Path_prefix"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
#define pii pair<int,int>
#define vi vector<int> 
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
void IOS()
{
    fast 
    srand(time(0)) ;
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  
const int LO = 19; 

int n ; 
int pa[N][LO+1];
ll wa[N][LO+1] , wb[N][LO+1];
void doc()
{
    cin>>n ; 
    FOR(i,2,n)
    {
    	int p , a ,b; 
    	cin>>p>>a>>b; 
    	pa[i][0] = p ; 
    	wa[i][0] = a ; 
    	wb[i][0] = b;  
    }
}
ll goup(int u ,int dis)
{
	ll ans= 0 ; 
	FOR(i,0,LO)
	{
		if(dis>>i&1)
		{
			ans+=wb[u][i]; 
			u =pa[u][i] ; 
		}
	}
	return ans ;
}
void xuly()
{
 	FOR(j,1,LO)
 	{
 		FOR(i,1,n)
 		{
 			pa[i][j] = pa[pa[i][j-1]][j-1] ; 
	 		wa[i][j] = wa[i][j-1]+wa[pa[i][j-1]][j-1] ; 
	 		wb[i][j] = wb[i][j-1]+wb[pa[i][j-1]][j-1] ; 
	 	}
 	}
 	FOR(v,2,n)
	{
		int u = v; 
		int dis= 0 ; 
		ll ans= 0, value =0;
		FORD(i,LO,0)
		{
			if(pa[u][i])
			{
				dis+=(1<<i);
				ans+=wa[u][i] ;
				value+=wb[u][i] ; 
				u = pa[u][i] ; 
			}
		}
		u = v; 
		ll cl = value-ans;	 
		if(cl<=0)
		{
			cout<<dis<<' ';
			continue ;
		}
		int l =0  ; 
		int r = dis; 
		ans =0 ; 
		while(l<=r)
		{
			int mid = (l+r)/2; 
			ll x = goup(u,mid); 
			if(x>=cl)
			{
				ans=mid ; 
				r=mid-1;  
			}
			else 
			{
				l=mid+1 ;
			}
		}
		cout<<dis-ans<<' ';
	}
	cout<<'\n';
}
void clear()
{
	FOR(i,1,n)
	{
		FOR(j,0,LO)
		{
			pa[i][j] = 0 ;
			wa[i][j] = wb[i][j] = 0 ;
		}
	}
}	

int main()
{
    IOS();  
    int test ; 
    cin>>test; 
    while(test--)
    {
    	doc() ;
    	xuly() ; 
    	clear();
    }
}