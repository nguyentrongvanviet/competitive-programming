#include<bits/stdc++.h>
using namespace std;

#define TASK "beautifulsubgrid"
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b) for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i = b;i>=a;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#define all(a) a.begin(),a.end()
const int N =3e3+5,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
#pragma GCC target("popcnt")
int n ; 
bitset<N>a[N];
ll sl(int a)
{
	return a*(a-1)/2;
}
void doc()
{
	cin>> n; 
	for(int i= 1;i<=n;i++)
	{
		cin>>a[i];
	}
	ll res=0 ;

	for(int i= 2;i<=n;i++)
	{
		for(int j=1;j<=i-1;j++)
		{
			res+=sl((a[i]&a[j]).count());
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
