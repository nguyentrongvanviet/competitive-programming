#include<bits/stdc++.h>
using namespace std;

#define TASK "icpc22_mn_b"

#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b) for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i = b;i>=a;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#define all(a) a.begin(),a.end()
const int N =2e5+5 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
void doc()
{
    cin>> n;
    cout<<n/2+(n&1)<<"\n";
    if(n&1)
    {
    	for(int  i= 1;i<=n/2;i++)
		{
			cout<<i*6-4<<" "<<i*6<<"\n";
		}
		cout<<(n-1)*3+1<<" "<<(n-1)*3+2<<"\n";
    }  
	else 
	{
		for(int  i= 1;i<=n/2;i++)
		{
			cout<<i*6-4<<" "<<i*6<<"\n";
		}
	}
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