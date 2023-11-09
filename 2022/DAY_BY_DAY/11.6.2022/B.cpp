#include<bits/stdc++.h>
using namespace std;

#define TASK "A"

#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b) for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i = b;i>=a;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n ; 
int a[N] ; 
void doc()
{
    cin>> n; 
    for(int i=1;i<=n;i++)
    {
    	char x; cin>>x;  
    	a[i]=(x=='1') ;
    }
    ll l =0  ; 
    ll r = 0 ; 
    ll res= 1 ; 
    ll x= 0 ; 
    ll y = 0 ;
    for(int i =1 ;i<=n;i++)
    {
    	if(a[i]==1)
    	{
    		x++ ; 
    		res=max(res,x*y) ;
    		r= 0  ;
    		if(l)
    		{
    			res=max(res,(i-l+1)*(i-l+1));
    		}
    		else 
    		{
    			l = i ;
    		}
    	}
    	else 
    	{
    		y++ ; 
    		res=max(res,x*y) ; 
    		l =0 ;  
    		if(r)
    		{
    			res=max(res,(i-r+1)*(i-r+1));
    		}
    		else 
    		{
    			r=i ; 
    		}
    	}
    }
    cout<<res<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}