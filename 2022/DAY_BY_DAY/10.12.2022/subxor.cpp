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
const int N =1e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n  , node=1 ; 
ll s[N] ,f[N*35] ;
int T[N*35][2];  
ll res=0 ;  
ll a[N]  , k ; 
void up(ll x)
{
	int r =1 ; 
	for(int i= 31;i>=0;i--)
	{
		int j= (x>>i&1) ; 
		if(T[r][j]==0)
		{
			T[r][j]=++node; 
		}
		r=T[r][j] ; 
		f[r]++;
	}
}
void get(ll x)
{
	int r= 1;  
	for(int i=31;i>=0;i--)
	{
		int j= (x>>i&1);
		int jj = (k>>i&1);
		if(j==0&&jj==1)
		{
			res+=f[T[r][0]];
			r=T[r][1];
		}	
		else if(j==0&&jj==0)
		{
			r=T[r][0];
		}
		else if(j==1&&jj==1)
		{
			res+=f[T[r][1]];
			r=T[r][0];  
		}
		else if(j==1&&jj==0)
		{
			r=T[r][1];
		}
	}
}
void input()
{
	cin>> n>> k ;
	up(0);  
	for(int i=1 ;i<=n;i++)
	{
		cin>>a[i] ; 
		s[i]=(s[i-1]^a[i]);  
		get(s[i]);
		up(s[i]); 
	}   
}
void output()
{
    cout<<res; 
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