#include<bits/stdc++.h>
using namespace std;

#define TASK ""
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
const int N =1e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n ; 
ll s[N];
int convert(int a)
{
	
	int u= sqrt(a) ;  
	FOR(i,2,u)
	{
		if(a%i==0)
		{
			return i+1; 
		}
	}
	return a+1; 
}
void doc()
{
	int q;  
 	cin>> n >>q;
 	FOR(i,1,n)
 	{
 		cin>>s[i] ; 
 		s[i] =s[i-1]+convert(s[i]) ; 
 	}   
 	FOR(i,1,q)
 	{
 		int l , r ; cin>>l>>r ; 
 		cout<<s[r]-s[l-1]<<"\n";
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
