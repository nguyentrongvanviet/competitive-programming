#include<bits/stdc++.h>
using namespace std;

#define TASK "VMQUABEO"

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

const int N =3e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n  ,  l ,d ; 
int a[N] ; 
int L[N] , R[N] ;
void doc()
{
 	cin>> n >> l>> d;  
 	FOR(i,1,n)
 	{
 		cin>>a[i]; 
 	}   
 	multiset<int>s ;
 	int l = 1; 
 	for(int i= 1;i<=n;i++)
 	{
 		s.insert(a[i]) ;
 		while(*s.rbegin()-*s.begin()>d)
 		{
 			s.erase(s.find(a[l]));
 			++l;
 		} 
 		L[i]= s.size();
 	}
 	s.clear();
 	int r=n ; 
 	FORD(i,n,1)
 	{	
 		s.insert(a[i]) ; 
 		while(*s.rbegin()-*s.begin()>d)
 		{
 			s.erase(s.find(a[r])); 
 			r--;
 		}
 		R[i]=  s.size();
 	}
 	int res=0 ;
    FOR(i,1,n)
    if(L[i]+R[i]-1>l)
    {
        res++ ; 
    }
 	cout<<res;
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
    // cin>>t ; 
    while(t--)
    {
        doc();
    }
}