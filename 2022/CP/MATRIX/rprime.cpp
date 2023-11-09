/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "rprime"
#define int long long 
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

const int N =320000+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

ll n , m; 
ll nt[N] ; 
vi unt , Div; 
void doc()
{
 	cin>> n >> m; 
}
vector<int>snt;
ll tich[(int)1e7] ;
void thieve()
{
	for(ll i = 2 ;i<=(ll)N-1;i++)
	{
		if(!nt[i])
		{
			unt.pb(i) ;
			nt[i] =  i; 
			for(ll j = i*i;j<=(ll)N-1;j+=i)
			{
				nt[j] = i ;
			}
		}
	}
}
ll sl(ll a )
{
	if(a==0)return 0;
	int  x= Div.size() ;
	ll ans =0  ;
	for(int msk = 1 ;msk<(1<<x);msk++)
	{
		ll val= tich[msk];
		int s = btpc(msk) ; 
		if(s&1)ans+=a/val;  
		else ans-=a/val;
	}
	return ans; 
}
void xuly()
{	
	for(auto uoc : unt)
	{
		if(n==1)break;
		if(n%uoc==0)
		{
			Div.pb(uoc) ;
			while(n%uoc==0)
			{
				n/=uoc ; 
			}
		}
	}
	if(n!=1)Div.pb(n);
	int x = Div.size(); 
	FOR(msk,1,(1<<x))
	{
		tich[msk] = 1;
		FORN(i,0,x)
		{
			if(msk>>i&1)tich[msk]*=Div[i];
		}
	}
	while(m--)
	{
		ll l ,r ; 
		cin>>l>>r ; 
		cout<<(r-sl(r))-(l-1-sl(l-1))<<'\n';
	}
}
main()
{
    IOS(); 
    thieve() ; 
    doc(); 
    xuly();
}