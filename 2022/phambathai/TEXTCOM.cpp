/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
code is just not for fun , it is for you too 
so if you have seen this please take it as a simple love I give to you so please take it as a message from my heart
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "TEXTCOM"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n , m; 

ll  f[1<<maxN];
int a[N] ;   
ll res=0  ;
map<int,int>sl; 
void doc()
{
	cin>>m>> n; 
    FOR(i,1,m)
    {
    	int val =0 ;
    	char x ;  
    	FORN(i,0,n)
    	{
    		cin>>x; 
    		if(x=='+')val|=(1<<i);
    	}
    	a[i] =val; 
    	sl[val]++; 
    	f[val]++;
    }
   	FOR(j,0,n-1)
   	{
   		FOR(i,0,1<<n)
   		{
   			if(i>>j&1)
   			{
   				f[i]+=f[i^(1<<j)];
   			}
 	  	}
 	}
 	FOR(i,1,m)
 	{
 		res+=f[a[i]]-sl[a[i]] ; 
 	}
 	cout<<res; 
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