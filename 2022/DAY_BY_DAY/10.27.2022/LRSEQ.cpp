#include<bits/stdc++.h>
using namespace std;

#define TASK "LRSEQ"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =1e6+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n ; 
ll a[N] ;   
set<ll>sum;  
ll s[N];
void doc()
{
 	cin>> n; 
 	for(int i= 1;i<=n;i++)
 	{
 		cin>>a[i] ; 
 		s[i] =s[i-1]+a[i] ; 
 	}   
 	sum.insert(s[1]) ;
 	ll res= inf ; 
 	for(int i=2 ;i<=n;i++)
 	{
 		auto  it = sum.lower_bound(s[n]-s[i-1]);
 		if(it!=sum.end())
 		{
 			res=min(res,*it-(s[n]-s[i-1])) ;
 		}
 		if(it!=sum.begin())
 		{
 			--it;
 			res=min(res,s[n]-s[i-1]-*it); 
 		}
 		sum.insert(s[i]);
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