#include<bits/stdc++.h>
using namespace std;

#define TASK ""
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#pragma CPP target("popcnt")
const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

struct pt 
{
	ll x , y ; 
};
bool cut(pt a, pt b , pt c , pt d)
{

}
bool check(vector<int>hoanvi)
{
	for(int i=0 ;i<hoanvi.siz();i++)
	{
		for(int i=1 ;i<=n;i++)
		{

		}
	}
	return 1 ;
}
int n ; 
pt a[N] ;  
void doc()
{	
    cin>> n; 
    for(int i=1 ;i<=n;i++)cin>>a[i].x>>a[i].y ; 
   	vector<int>hoanvi ; 
   for(int i= 1;i<=n;i++)
   {
   		hoanvi.pb(i) ; 
   }
   do
   {
   		if(check(hoanvi))res++ ;
   }while(_next_permutation(hoanvi.begin(),hoanvi.end())) ; 
}	

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}