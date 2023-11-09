#include<bits/stdc++.h>
using namespace std;

#define TASK "A"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n ; 

void doc()
{
	int n , a,  b; 
 	cin>> n >>a >>b ; 
 	if(a==b&&a==n)
 	{
 		cout<<"Yes"<<"\n";
 	}
 	else if(n-a-b<=1)
 	{	
 		cout<<"No"<<"\n";
 	}
 	else 
 	{
 		cout<<"Yes"<<"\n";
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
    int t = 1;
    cin>>t ; 
    while(t--)
    {
        doc();
    }
}