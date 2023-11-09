#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back 
#define pk pop_back 
#define pii pair<int,int>  

const  int N = 2e5+5 , oo =1e9 ; 
const ll inf = 1e17 , cs = 330 , sm = 1e9+7 ; 

struct pt 
{
	ll x , y ; 
	pt operator - (const pt& a )const 
	{
		return pt{x-a.x,y-a.y} ; 
	}
	ll operator *(const pt &a)const 
	{
		return x*a.y-y*a.x;
	}
};	
ll ccw(pt a,  pt b , pt c)
{
	return (b-a)*(c-a) ;
}
ll n; 
pt p[N] ;
void inp()
{
	cin>> n ; x
	for(int i=1 ;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y; 
	}
	ll res=0  ;
	int ans = oo  ; 
	int u; 
	for(int i=1 ;i<=n;i++)
	{
		int x= 0 ;  
		for(int j =1 ;j<=n;j++)
		{
			for(int t = 1 ;t<=n;t++)
			{
				if(ccw(p[i],p[j],p[t])!=0)
				{
					x++; 
				}
			}
		}
		if(x<ans)
		{
			ans=x ; 
			u = i ; 
		}
		res+=x ; 
	}
	res/=6; 
	cout<<res<<"\n";  
	cout<<u<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	freopen("i.txt","r",stdin) ;  
	freopen("o.txt","w",stdout) ; 
	inp() ; 

}