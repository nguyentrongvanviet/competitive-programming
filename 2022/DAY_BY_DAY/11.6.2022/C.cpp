#include<bits/stdc++.h>
using namespace std;

#define TASK ""

#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b) for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i = b;i>=a;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n ; 
void snt()
{
	for(int i= 2;i<=1e5;i++)
	{
		if(nt[i]==0)
		{
			nt[i]= i ; 
			for(int j  = i*i;j<=1e5;j+=i)
			{
				nt[j]=i;
			}
		}
	}
}
void doc()
{
 	cin>> n ;
 	for(int i=1 ;i<=n;i++)cin>>a[i] ;   

 	f[1] =1 ; 
 	for(int i=2 ;i<=n;i++)
 	{

 	}
 	cout<<f[n]<<"\n";
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