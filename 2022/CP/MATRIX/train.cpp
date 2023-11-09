/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "train"

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

struct DL
{
	int L , R ;   
	bool operator<(const DL& a)const
	{
		return L<a.L ; 
	}
};
struct cmp
{
	bool operator()(DL a, DL b)
	{
		return a.R<b.R; 
	}
}; 
DL a[N] ;
multiset<DL,cmp>s; 
int n , m ,c ; 
void doc()
{
    cin>> n >>c>>m;
    FOR(i,1,n)cin>>a[i].L>>a[i].R;
  	sort(a+1,a+n+1) ;
  	a[n+1] = {m,m}; 
  	int ans= 0 ; 
  	FOR(i,1,n+1)
  	{
  		while(!s.empty()&&(*s.begin()).R<=a[i].L)
  		{
  			ans++ ; 
  			s.erase(s.begin()); 
  		}
  		s.insert(a[i]) ; 
  		if(s.size()>c)
  		{
  			s.erase(s.find(*s.rbegin()));
  		}
  	}	
  	cout<<ans; 
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