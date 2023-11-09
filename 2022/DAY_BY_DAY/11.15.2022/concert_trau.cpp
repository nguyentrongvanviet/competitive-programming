#include<bits/stdc++.h>
using namespace std;

#define TASK "concert"
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
const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

struct DL 
{
	int l ,r , c; 	
};
int n ; 
int M ; 
DL a[N] ;
void doc()
{
 	cin>> n>> M ; 
 	FOR(i,1,n)cin>>a[i].l>>a[i].r>>a[i].c;  
 	ll res= 0 ; 
 	FOR(i,1,n)
 	{
 		FOR(j,i+1,n)
 		{
 			if(a[i].r<a[j].l||a[j].r<a[i].l)continue ; 
 			res+=(min(a[i].r,a[j].r)-max(a[i].l,a[j].l)+1)*a[i].c%sm*a[j].c%sm;
 			res+=sm; 
 			res%=sm;
 		}
 	}
 	cout<<res;
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".ANS","w",stdout); 
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