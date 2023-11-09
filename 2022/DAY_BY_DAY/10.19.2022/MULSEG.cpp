#include<bits/stdc++.h>
using namespace std;

#define TASK "MULSEG"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

const int N =3e6+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
struct DL
{
	int t , l , r , tuoi ;
	ll val ;
};
int q ,  n ;
DL a[N] ;
vector<int>tuoi;
vector<ll>st  , lazy;
map<int,int>pos;
void dolazy(int id )
{
	st[id] =(st[id]*lazy[id])%sm; 
	lazy[id*2] =(lazy[id*2]*lazy[id])%sm; 
	lazy[id*2+1]=(lazy[id*2+1]*lazy[id])%sm;
	lazy[id]=1;
}
void up(int id , int l ,int r , int t, int p ,ll val)
{
	dolazy(id);
	if(t<=l&&r<=p)
	{
		st[id]=(st[id]*val)%sm; 
		lazy[id*2]=(lazy[id*2]*val)%sm; 
		lazy[id*2+1]=(lazy[id*2+1]*val)%sm;
		return ; 
	}
	if(r<t||p<l)return ; 
	int mid = l+r>>1; 
	up(id*2,l,mid,t,p,val) ; 
	up(id*2+1,mid+1,r,t,p,val) ; 
	st[id]= (st[id*2]*st[id*2+1])%sm;
}
ll get(int id,int l , int r , int pos)
{
	dolazy(id) ; 
	if(l==r&&l==pos)return st[id]; 
	int mid =l+r>>1 ; 
	if(pos<=mid)
	{
		return get(id*2,l,mid,pos) ; 
	}
	else 
	{
		return get(id*2+1,mid+1,r,pos);
	}
}
void doc()
{
    cin>> q; 
    FOR(i,1,q)
    {
    	cin>>a[i].t; 
    	if(a[i].t==1)
    	{
    		cin>>a[i].tuoi ;
    		tuoi.pb(a[i].tuoi); 	 
    	}
    	else 
    	{
    		cin>>a[i].l>>a[i].r>>a[i].val ;
    		tuoi.pb(a[i].l); 
    		tuoi.pb(a[i].r); 
    	}
    }
    sort(tuoi.begin(),tuoi.end());  
    tuoi.resize(unique(tuoi.begin(),tuoi.end())-tuoi.begin());

    for(int i =0;i<tuoi.size();i++)
   	{
   		pos[tuoi[i]]=i+1;
   	}
   	n = tuoi.size();
   	lazy.resize(8*n+1) ; 
    st.resize(8*n+1);
   	FOR(i,1,8*n)
   	{
   		st[i] = lazy[i] =1 ;
   	}
   	FOR(i,1,q)
   	{
   		if(a[i].t==1)
   		{
   			a[i].tuoi = pos[a[i].tuoi] ; 
   		}
   		else 
   		{
   			a[i].l=pos[a[i].l]; 
   			a[i].r=pos[a[i].r];
   		}
   	}
   	FOR(i,1,q)
   	{
   		if(a[i].t==1)
   		{
   			cout<<get(1,1,n,a[i].tuoi)<<"\n";
   		}
   		else 
   		{
   			up(1,1,n,a[i].l,a[i].r,a[i].val);
   		}
   	}
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
    // cin>>t ; 
    while(t--)
    {
        doc();
    }
}