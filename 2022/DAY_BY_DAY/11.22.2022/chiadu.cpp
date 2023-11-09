#include<bits/stdc++.h>
using namespace std;

#define TASK "chiadu"

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
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
}

const int N =1e6+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ; 

int n  , m;
int a[N] ;
vector<int> q; 
int b[N] ;
int la= 0 ; 
int f[N] ;
int pos[N] ;
int ma[N] ;
multiset<int>s ; 
vector<int>uoc[N] ;
int last[N] ;
void doc()
{	
    cin>> n >> m; 
    FOR(i,1,n)
    {
    	int val;  
    	cin>>val;  
    	q.pb(val) ; 
    }
  	sort(q.begin(),q.end()); 
  	q.resize(unique(q.begin(),q.end())-q.begin());  
  	FOR(i,1,m)cin>>b[i] ; 
  	for(auto x :q )
  	{
  		for(int i = x ;i<=(int)1e6;i+=x)
  		{
  			a[i]+=1; 
  			uoc[i].pb(x);
  		}
  	}
  	int la = 0 ; 
  	FOR(i,1,(int)1e6)
 	{
 		if(a[i])
 		{
 			la=i ; 
 		}
 		f[i] =la ;
 	}
 	FOR(i,1,(int)1e6)
 	{
 		for(auto x: uoc[i])
 		{
 			if(last[x]==0)
 			{
 				s.insert(i) ; 
 				last[x] = i ;
 			}
 			else 
 			{
 				s.erase(s.find(last[x])) ; 
 				s.insert(i); 
 				last[x] =i;  
 			}
 		}
 		pos[i] =*s.begin();
 	}
 	FOR(i,1,m)   
 	{
 		cout<<b[i]-f[b[i]]<<" "; 
 		if(b[i]<q.back())
 		{
 			cout<<q.back() ;
 		}
 		else 
 		{
 			cout<<b[i]-pos[b[i]];
 		}
 		cout<<"\n";
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