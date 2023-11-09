#include<bits/stdc++.h>
using namespace std;

#define TASK "TUTHIEN"
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

int n  , k ;  
int a[N];
multiset<int>s; 
ll res=0 ; 
void doc()
{
 	cin>> n>> k; 
 	for(int i=1 ;i<=n;i++)cin>>a[i] ;
 	int l = 1 ;
 	for(int i=1 ;i<=n;i++)
 	{
 		s.insert(a[i]) ; 
 		if(i-l+1>k)
 		{
 			s.erase(s.find(a[l])) ; 
 			++l ;
 		}
 		res+=(*s.begin());
 	}
 	cout<<res*2;
}

int main()
{
    fast 
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