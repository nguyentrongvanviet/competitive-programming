#include<bits/stdc++.h>
using namespace std;

#define TASK "BOBA"

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
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
}

const int N =2e3+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ; 

int n , q; 
int a[N] ; 
map<int,int>dd; 
vector<int>value ;
ll biti[N] , bitj[N] , bitk[N] ; 
ll f[N][N] ; 
void doc()
{
 	cin>> n >> q; 
 	FOR(i,1,n)
 	{
 		cin>>a[i] ; 
 		value.pb(a[i]) ; 
 	}   
 	sort(value.begin(),value.end()) ; 
 	value.resize(unique(value.begin(),value.end())-value.begin()) ; 
 	FOR(i,0,value.size()-1)
 	{
 		dd[value[i]]=i+1;
 	}
 	FOR(i,1,n)
 	{
 		a[i] = dd[a[i]]  ;
 	}
}	
ll get( ll bit[] , int idx )
{
	ll ans= 0  ;
	for(int i=idx;i;i-=i&-i)ans+=bit[i]; 
	return ans  ; 
}
void up(ll bit[] , int idx,int val)
{
	for(int i=idx;i<=n;i+=i&-i)bit[i]+=val; 
}
void xuly()
{
    FOR(i,1,n)
 	{
 		FOR(j,1,n)biti[j]=bitj[j]=bitk[j]=0; 
 		f[i][i] = 0 ; 
 		FOR(j,i+1,n)
 		{
 			f[i][j] = get(bitk,a[j]-1);
 			up(bitk,a[j],get(bitj,n)-get(bitj,a[j]));
 			up(bitj,a[j],get(biti,a[j]-1));
 			if(a[j]<a[i])up(biti,a[j],1);
 		}	
 	}	
 	while(q--)
 	{
 		int u ,v ; 
 		cin>>u>>v ; 
 		cout<<f[u][v]<<"\n";
 	}
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}