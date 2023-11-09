#include<bits/stdc++.h>
using namespace std;

#define TASK "B"

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
int a[N] ;
int dd[200] ;
void doc()
{
 	cin>>n ;  
 	FOR(i,1,n)
 	{
 		cin>>a[i] ; 
 	}
 	if(n==1)
 	{
 		cout<<1 ;
 		return  ; 
 	}   
 	memset(dd,0,sizeof(dd));
 	int cnt = 0 ; 
 	FOR(i,1,n)
 	{
 		dd[a[i]]++;
 		if(dd[a[i]]==2)cnt=1; 
 	}
 	FOR(i,1,n)
 	{
 		if(dd[i])cnt++;
 	}
 	cout<<cnt<<"\n";
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