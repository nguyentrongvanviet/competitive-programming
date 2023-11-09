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
ll a[N]  ,b[N]; 
unordered_map<ll,int>sl; 
void doc()
{
 	cin>> n >> m;
 	int mid =n/2; 
 	for(int i= 1;i<=n/2;i++)
 	{
 		cin>>a[i] ; 
 	}  
 	for(int i=1;i<=n-mid;i++)
 	{
 		cin>>b[i] ; 
 	}
 	ll res=0 ; 
 	for(int i= 1;i<(1<<mid);i++)
 	{
 		ll s= 0  ;
 		for(int j=0 ;j<mid;j++)
 		{
 			if(i>>j&1)
 			{
 				s+=a[j+1]; 
 			}
 		}
 		if(s==m)res++ ;
 		else sl[s]++;
 	}
 	for(int i=1 ;i<(1<<(n-mid));i++)
 	{
 		ll s=0  ; 
 		for(int j=0  ;j<n-mid;j++)
 		{
 			if(i>>j&1)
 			{
 				s+=b[j+1] ; 
 			}
 		}
 		if(s==m)res++ ;
 		else 
 		{
 			if(sl.find(m-s)!=sl.end()) 
 			{
 				res+=sl[m-s];
 			}
 		}
 	}
 	cout<<res;
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
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}