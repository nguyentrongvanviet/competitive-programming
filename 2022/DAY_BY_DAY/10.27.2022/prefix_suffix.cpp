// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "prefix_suffix"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define vi vector<int> 
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
void IOS()
{
    fast 
    srand(time(0)) ;
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ; 
string s; 
int a[N] ; 

vi Z_func(int a[] , int n )
{
	vi z(n) ; 
	for(int i = 1 , l = 0 , r = 0 ; i<n;i++)
	{
		if(i<=r)
		{
			z[i] = min(r-i+1,z[i-l]);
		}
		while(s[i+z[i]]==s[z[i]])++z[i] ; 
		if(r<i+z[i]-1)
		{
			l =i ; 
			r =i+z[i]-1;  
		}
	}
	return z;  
}
void doc()
{
	cin>>s ;
	n = s.size() ; 
	FOR(i,1,n)
	{
		a[i-1]=s[i-1] ; 
	}
	vi z=  Z_func(a,n);
	vi zz = z ;  
	sort(all(zz)) ; 
	vector<pii> res; 
	for(int i =1 ;i<n;i++)
	{
		int it = lower_bound(all(zz),i)-zz.begin(); 
		if(it!=n&&z[n-i]==i)
		{
			res.pb({i,n-it+1}); 
		} 
	}	
	res.pb({n,1});  
	cout<<res.size()<<'\n';
	for(auto x : res)
	{
		cout<<x.fi <<" "<<x.se<<'\n';
	}
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