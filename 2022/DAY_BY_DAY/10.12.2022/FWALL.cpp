/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "FWALL"

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

int n ; 
int T[N][CH]; 
int en[N];
vector<string>q,res;
int node =1 ;  
int dd[N] ; 
bool ok =1 ; 
void up(string s )
{
	int r = 1; 
	FORN(i,0,s.size())
	{
		int j= s[i]-'a' ; 
		if(T[r][j]==0)
		{
			T[r][j] =++node; 
		}
		r=T[r][j];
	}
	en[r] =1; 
}
void solve(string s )
{
	int r= 1; 
	FORN(i,0,s.size())
	{
		int j= s[i]-'a';  
		if(T[r][j]==0)break; 
		r=T[r][j] ;
		if(en[r])
		{
			ok= 0 ; 
			break; 
		} 
		dd[r] =1 ;
	}
}
void dfs(int node , string s )
{
	if(dd[node]==0)
	{
		res.pb(s) ;
		return ; 
	}
	FORN(i,0,CH)
	{
		if(T[node][i])
		{
			dfs(T[node][i],s+(char)('a'+i));
		}
	}
}
void doc()
{
    cin>> n ; 
    FOR(i,1,n)
    {
    	char t ; cin>>t ; 
    	string s ; cin>>s ; 
    	if(t=='-')
    	{
    		up(s) ; 
    	}
    	else 
    	{
    		q.pb(s); 
    	}
    }
    for(auto v : q)
    {	
    	solve(v) ; 
    }
    if(!ok)
    {
    	cout<<-1; 
    	return ; 
    }
    dd[1]=1; 
    dfs(1,"");
    cout<<res.size()<<'\n' ;
    for(auto s : res)
    {
    	cout<<s<<"\n";
    }
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