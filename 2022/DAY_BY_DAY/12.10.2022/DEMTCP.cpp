/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
code is just not for fun , it is for you too 
so if you have seen this please take it as a simple love I give to you so please take it as a message from my heart
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "DEMTCP"

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

const int N =1e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ;
int nt[N];
int a[N] ;
void snt()
{
	nt[1]=-1 ;
	nt[0]=-1 ; 
	for(ll i =2 ;i<=(ll)1e5;i++)
	{
		if(nt[i]==0)
		{
			nt[i] = i ; 
			for(ll j =i*i ;j<=(ll)1e5;j+=i)
			{
				nt[j] = i ;
			}
		}
	}	
} 	
void doc()
{
    cin>>n ;
}	
int transform(int a)
{
	int ans=1 ;
	while(a>1)
	{
		int x= nt[a] ;
		int le =0 ; 
		while(a%x==0)
		{
			a/=x ; 
			le++;
		}
		if(le&1)ans*=x ; 
	}	
	return ans; 
}
int sl[N] ;
void xuly()
{	
	ll res=0;
	res= n; 
	FOR(i,1,n)
	{
		int ans = transform(i) ; 
		res+=2*sl[ans]; 
		sl[ans]++;
	}   
	cout<<res;
}
int main()
{
    IOS();  
    snt();
    doc(); 
    xuly();
}