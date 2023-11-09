#include<bits/stdc++.h>
using namespace std;

#define TASK "MEET_IN_MIDDLE"

#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b) for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i = b;i>=a;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#define all(a) a.begin(),a.end()
const int N =40+5 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
ll m ; 
ll a[N]  ; 
int res=0 ; 
void doc()
{
 	cin>> n>> m; 
 	for(int  i=1 ;i<=n;i++)cin>>a[i] ; 
 	for(int i= 1;i<(1<<n);i++)
 	{
 		ll s=0  ; 
 		for(int j= 0 ; j<n;j++)
 		{
 			if(i>>j&1)
 			{
 				s+=a[j+1] ; 
 			}
 		}
 		if(s==m)res++ ;
 	}  
 	cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
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