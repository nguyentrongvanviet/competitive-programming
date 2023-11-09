#include<bits/stdc++.h>
using namespace std;

#define TASK "frac"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<ll,ll>
#define fi first 
#define se second  
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int h , k ; 
pii cong(pii a, pii b)
{
	return {a.fi+b.fi,a.se+b.se}; 
}
vector<ll>q ; 
void dfs(ll  id ,  pii L ,  pii R , pii u , pii dinh  )
{		
	if(u==dinh)
	{
		q.pb(id) ;
		return ; 
	}
	bool tmp =  (dinh.fi*u.se<u.fi*dinh.se); 
	if(tmp)
	{
		dfs(id*2,L,u,cong(L,u),dinh);
	}
	else 
	{
		dfs(id*2+1,u,R,cong(R,u),dinh);
	}
}  

void doc()
{
    cin>> h >>k ;  
    FOR(i,1,k)
    {
    	ll u , v; 
    	cin>>u>>v ; 
    	dfs(1,{0,1},{1,0},{1,1},{u,v}); 
    }
    int res=0; 	
    sort(q.begin(),q.end()); 
    queue<ll>h ; 
    while(!q.empty()||!h.empty())
    {
    	ll v = 0; 
    	if(!q.empty())
    	{
    		v=max(v,q[q.size()-1]); 
    	}
    	if(!h.empty())
    	{
    		v=max(v,h.front());
    	}
    	while(!h.empty()&&h.front()==v)h.pop() ; 
    	while(!q.empty()&&q.back()==v)q.pk() ; 
    	if(v==1)break;
    	h.push(v/2) ;
    	v/=2;  
    	res++ ; 
    }
    cout<<res; 
}
void xuly()
{
    
}
 main()
{
    IOS();  
    doc(); 
    xuly();
}