/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "WG"

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

const int N =1000+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct ke 
{	
	int v;  
	int w;  
	int len ; 
};
int  m , n ; 
string s;  
string a[N] ; 
vi g[N] ; 
bool dd[CH][N];
void doc()
{
  	cin>>s ;
  	cin>> n; 
  	m=s.size();
  	s='$'+s ;
  	
  	FOR(i,1,n)cin>>a[i],a[i]='#'+a[i]; 
}
void build()
{
	FOR(i,1,n)
	{
		g[a[i][1]-'a'].pb(i);
	}
} 
int len(int pos  ,int id )
{ 
	int ans= 0; 
	FORN(i,2,a[id].size())
	{
		if(pos+1>s.size()-1)break; 
		if(s[pos+1]==a[id][i])
		{
			++pos;
			++ans; 
		}
	}
	return ans; 
}
struct BG 
{
	int c; 
	int k; 
	int val; 
};
struct cmp
{
	bool operator()(BG a, BG b)
	{
		return a.val>b.val;
	}
};
int f[CH][N];
void dij()
{
	priority_queue<BG,vector<BG>,cmp>q; 
	FOR(i,0,m)FORN(j,0,CH)f[j][i] =oo ; 
	FOR(id,1 	,n)
	{	 
    	int c = a[id].back()-'a';
    	int val =a[id].size()-1 ; 
    	int ans= 0; 
    	int pos = 0 ;
		FORN(i,1,a[id].size())
		{
			if(pos+1>s.size()-1)break; 
			if(s[pos+1]==a[id][i])
			{
				++pos;
				++ans; 
			}
		}
		if(f[c][ans]>val)f[c][ans]=val , q.push({c,ans,f[c][ans]});
	}
	while(!q.empty())
	{
		int c= q.top().c;  
		int k= q.top().k;
		if(k==m)
		{
			cout<<q.top().val ; 
			return ; 
		}
		q.pop() ;  
		if(dd[c][k])continue ;
		dd[c][k] =1 ;
		for(auto v : g[c])
		{
			int w  = len(k,v);
			int nc = a[v].back()-'a'; 
			int val= a[v].size()-1;
			if(f[nc][k+w]>f[c][k]+val-1)
			{
				f[nc][k+w] = f[c][k]+val-1; 
				q.push({nc,k+w,f[nc][k+w]}); 
			}
		} 	
	}
	cout<<-1 ; 
}
void xuly()
{
    build() ;
    dij() ;
}

int main()
{
    IOS();  
    doc(); 
    xuly();
}