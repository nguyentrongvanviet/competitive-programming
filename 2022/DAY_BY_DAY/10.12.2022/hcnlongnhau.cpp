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

struct hcn 
{
	int x , y , u , v  ; 
	bool operator < (const hcn& a )const
	{
		if(v==a.v)
		{
			if(u==a.u)
			{
				return  y>a.y||(y==a.y&&x>a.x) ;
			}
			return u<a.u ; 
		}
		return v<a.v ;  
	}
}; 
int n ; 
hcn a[N] ; 
int f[N];
void input()
{
 	cin>>n  ; 
 	for(int i= 1;i<=n;i++)
 	{
 		int x ,y , u ,v ; 
 		cin>>x>>y>>u>>v ; 
 		a[i]={x,y,u,v}; 
 	}   
}
bool in(int i  , int j )
{
	return (a[i].x>=a[j].x&&a[i].y>=a[j].y&&a[i].u<=a[j].u&&a[i].v<=a[j].v) ;
}
void output()
{
	int res= 1 ;
    sort(a+1,a+n+1) ; 
    for(int i= 1;i<=n;i++)
    {
    	f[i] = 1; 
    	for(int j= 1 ;j<=i-1;j++)
    	{
    		if(in(j,i))
    		{
    			f[i] =max(f[i],f[j]+1) ; 
    			res=max(res,f[i]);
    		}
    	}
    }
    // cout<<-1;
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