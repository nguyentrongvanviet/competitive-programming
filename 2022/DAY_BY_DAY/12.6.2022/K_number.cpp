// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "K_number"

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
int a[N] ;
int dd[N] ; 
void doc()
{
 	cin>> n; 
 	FOR(i,1,n)dd[i] =0;
 	FOR(i,1,n)cin>>a[i] ,dd[a[i]]=1 ; 
}
int check(int k)
{
	vector<int>ok(n+1,1) ; 
	vector<int>la(n+1,0) ; 
	for(int i= 1;i<=n;i++)
	{
		if(i-la[a[i]]>k&&la[a[i]]!=0)
		{
			ok[a[i]] = 0 ; 
		}
		else if(la[a[i]]==0&&i>k)
		{
			ok[a[i]]=  0 ;
		}
		la[a[i]] =i ; 
	}
	for(int i=1 ;i<=n;i++)
	{
		if(dd[i])
		{
			if(n-la[i]+1>=k+1)ok[i] = 0 ;
		}
	}
	FOR(i,1,n)
	{
		if(dd[i]&&ok[i])
		{
			return i ; 
		}
	}
	return -1 ; 
}
void xuly()
{
    FOR(i,1,n)
    {
    	cout<<check(i)<<" ";
    }
    cout<<"\n";
}
int main()
{
    IOS();  
    int test ;
    cin>>test; 
    while(test--)
    { 
    	doc(); 
    	xuly();
    }
   
}