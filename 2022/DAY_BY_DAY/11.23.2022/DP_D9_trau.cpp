#include<bits/stdc++.h>
using namespace std;

#define TASK "DP_D9"

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
        freopen(TASK".ANS","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct DL
{
	int l , r ; 
	ll c;  
};
int n , m  ,k ;  
DL a[N] ; 
ll res= inf  ;
int dd[N] ; 
void doc()
{
 	cin>>n >> m >>k ; 
 	FOR(i,1,m)
 	{
 		cin>>a[i].l>>a[i].r>>a[i].c  ; 
 	}   
 	FOR(i,1,(1<<m)-1)
 	{
 		FOR(t,1,n)dd[t]= 0 ; 
 		ll gia =0 ; 
 		int cnt = 0 ; 
 		FOR(j,1,m)
 		{	
 			if(i>>(j-1)&1)
 			{
 				gia+=a[j].c ; 
 				FOR(t,a[j].l,a[j].r)
 				{
 					if(dd[t]==0)cnt++;
 					dd[t]= 1 ; 
 				}
 			}	
 		}
 		if(cnt>=k)
 		{
 			res=min(res,gia) ; 
 		}
 	}
 	if(res==inf)
 	{
 		cout<<-1;  
 		return ;
 	}
 	cout<<res;
}
void xuly()
{
    
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}