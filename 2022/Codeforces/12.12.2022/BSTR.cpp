/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "BSTR"

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
 
const int N =5e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct Q
{
	char t ;  
	string s ; 
};	
Q query[N] ;
int n , q; 
vector<string>ds ; 
unordered_map<ll,int>sl[N] ;
vi value ;
ll mu[N] ; 
ll ha[N] ;
void doc()
{
	cin>> n; 
	FOR(i,1,n)
	{
		string x; 
		cin>>x ; 
		ds.pb(x) ;  		
	}    
	cin>>q ;
	  
	FOR(i,1,q)
	{
		cin>>query[i].t >> query[i].s; 
		if(query[i].t=='q')
		{
			value.pb(query[i].s.size()) ; 
		}
	}
	sort(all(value)) ; 
	value.resize(unique(all(value))-value.begin()) ; 
}
ll to_hash(string s )
{
	ll ans =0 ; 
	FORN(i,0,s.size())
	{
		ans= ans*cs+s[i];  
	}
	return ans ; 
}
ll get_hash(int l ,int r, ll * ha )
{
	return ha[r]- ha[l-1]*mu[r-l+1];
}
void add(string s ,int id  )
{
	int n = s.size() ; 
	s=" "+s ;
	FOR(i,1,n)
	{
		ha[i] = ha[i-1]*cs+s[i] ; 
	}
	for(auto x : value )
	{	
		unordered_map<ll,bool>dd; 
		FOR(i,1,n-x+1)
		{
			ll val = get_hash(i,i+x-1,ha) ;
			if(!dd.count(val))
			{
				dd[val]=1 ; 
				sl[x][val]+=id; 
			}
		}
	}	
}
void xuly()
{
	mu[0] =1 ;
	FOR(i,1,N-1)mu[i] = mu[i-1]*cs;
	FORN(i,0,n)
	{
		add(ds[i],1);
	} 
	FOR(i,1,q)
	{
		int t= query[i].t;
		string s= query[i].s;  
		if(t=='q')
		{
			cout<<sl[s.size()][to_hash(s)]<<'\n' ; 
		}
		else if(t=='i')
		{
			add(s,1) ; 
		}
		else if(t=='e')
		{
			add(s,-1) ; 
		}
	}
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}