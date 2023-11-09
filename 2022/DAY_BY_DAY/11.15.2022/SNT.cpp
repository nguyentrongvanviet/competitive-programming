#include<bits/stdc++.h>
using namespace std;

#define TASK "SNT"
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
const int N =1e6+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
ll sq(ll a ){return a*a;}
int n ; 
int nt[N];

void snt()
{
	for(ll i=2;i<=1e6;i++)
	{
		if(nt[i]==0)
		{
			nt[i] = i ; 
			for(ll j=i*i;j<=(ll)1e6;j+=i)
			{
				nt[j]=i;
			}
		}
	}
}
void doc()
{
	snt();
    cin>> n ;
    FOR(i,1,n)
    {
    	ll x; 
    	cin>> x; 
    	if(x==1)
    	{
    		cout<<"NO"<<"\n";
    		continue ;
    	}
    	ll sqx= sqrt(x) ; 
    	if(sqx*sqx==x&&nt[sqx]==sqx)
    	{
    		cout<<"YES"<<"\n"; 
    	}
    	else 
    	{
    		cout<<"NO"<<"\n";
    	}
    }
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