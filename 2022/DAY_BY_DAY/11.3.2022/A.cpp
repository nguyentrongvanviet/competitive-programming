#include<bits/stdc++.h>
using namespace std;

#define TASK "icpc22_mn_b"

#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b) for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i = b;i>=a;i--)
#define pii pair<int	,int>
#define fi first 
#define se second  
#define all(a) a.begin(),a.end()
const int N =2e5+5 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
ll a[N] ;
void doc()
{
 	cin>> n ; 
 	ll s1 =  0 ,s2 = 0 ; 
 	for(int i= 1;i<=n;i++)
 	{
 		cin>>a[i];
 		if(a[i]<0)s1+=a[i] ; 
 		else s2+=a[i] ; 
 	}  
 	cout<<max(abs(s1)-abs(s2),abs(s2)-abs(s1))<<"\n";
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