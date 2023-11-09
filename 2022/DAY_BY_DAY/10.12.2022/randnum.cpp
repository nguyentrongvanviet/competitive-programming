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
int T[N*35][2] ; 
int node= 1; 
int f[N*35] ; 
void up(ll u )
{
	int r= 1; 
	for(int i = 31;i>=0;i--)
	{
		int j=((u&(1<<i))!=0) ;
		if(T[r][j]==0)
		{
			T[r][j]=++node; 
		}
		r=T[r][j] ;
		f[r]++;
	}
}
ll get(int k )
{
	int r= 1; 
	ll ans = 0 ; 
	for(int i= 31;i>=0;i--)
	{
		int t = T[r][0]  ;
		int p =T[r][1] ; 	
		if(f[t]>=k)
		{
			r=t;  
		}
		else 
		{
			ans|=(1<<i);
			r=p;
			k-=f[t];
		}
	}
	return ans; 
}
void input()
{	
    cin>> n ; 
    for(int i= 1;i<=n;i++)
    {
    	int t; 
    	cin>> t; 
    	if(t==1)
    	{
    		ll u ;
    		cin>>u;
    		up(u) ;  
    	}
    	else 
    	{
    		ll u  ; 
    		cin>>u ; 
    		cout<<get(u)<<"\n"; 
    	}
    }
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