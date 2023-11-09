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

int n , m ; 

ll a[N] , q[N]  ; 
ll sum[N]  ;  
ll ans[N] ;  
ll res =0 ;
int pa[N];
int dd[N];
void input()
{
 	cin>> n >>  m ; 
 	for(int i= 1;i<=n;i++)
 	{
 		cin>>a[i] ; 
 		dd[i] =1 ; 
 	}   
 	for(int i= 1 ;i<=m;i++)
 	{
 		cin>>q[i] ; 
 		dd[q[i]] = 0 ;  
 	}
}
int goc(int u )
{
	return pa[u]==u?u:pa[u]=goc(pa[u]) ; 
}
void hop(int u , int v )
{
	int chau = goc(u) ; 
	int chav = goc(v) ; 
	if(chau==chav) return  ;  
	pa[chav] =chau; 
	sum[chau]+=sum[chav] ; 
	res=max(res,sum[chau]) ; 
}
void init()
{
	for(int i= 1;i<=n;i++)
	{
		pa[i] = i ; 
		sum[i]  = a[i] ; 
	}
}
void output()
{
	init() ; 
    for(int i=1;i<=n;i++)
    {
    	if(dd[i])res=max(res,sum[i]);
    	if(dd[i]&&dd[i-1])
    	{
    		hop(i,i-1); 
    	}
    }
    ans[m] =res ; 
    for(int i=m;i>=2;i--)
    { 
    	dd[q[i]]=1; 
    	res=max(res,sum[q[i]]) ; 
  		if(dd[q[i]-1])hop(q[i]-1,q[i]) ; 
  		if(dd[q[i]+1])hop(q[i],q[i]+1) ; 
  		ans[i-1]=res ; 
    }
    for(int i= 1;i<=m;i++)	
    {
    	cout<<ans[i]<<"\n";
    }
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