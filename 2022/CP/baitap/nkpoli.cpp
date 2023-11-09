#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back 
#define pk pop_back 
#define pii pair<int,int> 

const int N= 105 ,oo = 1e9 ; 
const ll  inf = 1e17 , sm =1e9+7 ; 

struct pt 
{
	int x , y;  	
	pt operator -(const pt&a)const
	{
		return pt{x-a.x,y-a.y} ; 
	}
	ll operator *(const pt&a)const 
	{
		return x*a.y-y*a.x; 	
	} 
};
ll ccw(pt a, pt b , pt  c )
{
	return (b-a)*(c-b) ; 
}
ll dis(pt a , pt b )
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) ; 
}
ll n ; 
pt  p[N] ; 
int f[N][N];
bool cmp(pt a, pt b)
{
	if(ccw(p[0],a,b)==0)
	{
		return dis(p[0],a)<dis(p[0],b) ; 
	}
	return ccw(p[0],a,b)>0; 
}
void inp()
{
	cin>> n ; 
	for(int i= 1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y; 
	}
	p[0] = {0,0};
	sort(p+1,p+n+1,cmp); 
	for(int i= 1;i<=n+1;i++)
	{	
		f[0][i] =1 ; 
	}
	p[n+1]=p[0]; 
	int res=0 ; 
	for(int i=1 ;i<=n;i++)
	{
		for(int j= i+1;j<=n+1;j++)
		{
			for(int k =0;k<=i-1;k++)
			{
				if(ccw(p[k],p[i],p[j])>0)f[i][j]=max(f[i][j],f[k][i]+1) ;
			}
			if(j==n+1)
			{
				res=max(res,f[i][j]); 
			}
		}
	}
	cout<<res; 
}
int main()
{
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	freopen("i.txt","r",stdin) ; 
	freopen("o.txt","w",stdout) ; 
	inp() ; 
}
