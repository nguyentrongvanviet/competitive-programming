#include<bits/stdc++.h>
using namespace std;

#define TASK "KITES"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#pragma CPP target("popcnt")
const int N =53 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e4;

struct pt 
{
	ll x, y; 
	bool operator <(const pt& a)const
	{
		return x<a.x ; 
	}
	pt operator-(const pt &a)const
	{
		return pt{x-a.x,y-a.y}; 
	}
	ll operator *( pt a )
	{
		return x*a.y-y*a.x; 		
	}
} ; 
ll ccw(pt a , pt b  , pt  c)
{
	return (b-a)*(c-b);
}
int n ; 
pt a[N] ;  
pt dieu[N] ; 
bool dd[N][N][N][N] ; 
ll f[N][N][N][N];
ll tinh(int l , int r , int t , int p ) 
{
	if(r-l+1==2)return f[l][r][t][p]=1;
	if(dd[l][r][t][p])return f[l][r][t][p];
	dd[l][r][t][p]=1;
	pt tmp ={-inf,-inf}; 
	int ma = -1;
	FOR(i,1,n)
	{
		if(ccw(a[l],dieu[i],dieu[t])>0&&ccw(a[r],dieu[i],dieu[p])<0&&dieu[i].y<=min(dieu[t].y,dieu[p].y))
		{
			if(dieu[i].y>tmp.y)
			{
				tmp = dieu[i] ; 
				ma = i ;
			}
		}
	}
	if(ma==-1)return f[l][r][t][p]=0;
	ll res=0 ;
	FOR(i,l+1,r-1)
	{
		res+=tinh(l,i,t,ma)*tinh(i,r,ma,p)%sm;
		res%=sm;
	}
	return f[l][r][t][p]=res; 
}
void doc()
{
	cin>> n;   
	FOR(i,1,n){cin>>a[i].x;a[i].y=0;} 
	sort(a+1,a+n+1); 
	FOR(i,1,n)
	{
		cin>>dieu[i].x>>dieu[i].y;  
	}
	a[0]={-inf,0}  ; 
	a[n+1]={inf,0} ; 
	dieu[0] = {-inf,inf} ; 
	dieu[n+1] = {inf,inf}; 
	cout<<tinh(0,n+1,0,n+1);
}
int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}