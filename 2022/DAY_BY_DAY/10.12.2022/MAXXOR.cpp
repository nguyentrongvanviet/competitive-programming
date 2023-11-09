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
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
ll a[N] ; 
int T[N*35][2];
int node=1;
void up(ll val)
{
	int r = 1; 
	for(int i=31;i>=0;i--)
	{
		int j=  ((1<<i)&val)!=0 ; 
		if(T[r][j]==0)
		{
			T[r][j]=++node; 
		}
		r=T[r][j] ; 
	}
}	
ll get(ll val)
{
	ll r= 1 ;
	ll ans= 0 ; 
	for(int i= 31;i>=0;i--)
	{
		int j= ((1<<i)&val)!=0 ; 
		if(T[r][j^1]!=0)
		{
			r=T[r][j^1]; 
			ans^=(1<<i);
		}
		else 
		{
			r=T[r][j];
		}
	}
	return ans; 
}
void input()
{
 	cin>> n ; 
 	for(int i=1 ;i<=n;i++)
 	{
 		cin>>a[i] ; 
 		up(a[i]); 
 	}   
 	ll res=0 ; 
 	for(int i=1 ;i<=n;i++)
 	{
 		res=max(res,get(a[i])); 
 	}
 	cout<<res; 
}
void output()
{
    
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