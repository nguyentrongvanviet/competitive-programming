// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "SWGAME"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ; 
ll L , R  ; 
int q[N] ; 
int val ; 
ll res=  inf ; 
void doc()
{
    cin>>n>>L>>R;
    val =min(L,R);  
    FOR(i,1,n)cin>>a[i] , if(a[i]&1)q[++x] = i;
    int m = q.size() ; 
    if(m<=1)
    {	
    	cout<<0 ; 
    	return ; 
    } 
    for(int i=1;i<=m;i+=2)
    {
    	s1[i] =s1[i-2]+q[i+1]-q[i];
    }
    s1[m] = s1[i-1]+q[1]+n-q[m];
    s2[1] = q[1]+n-q[m];
    for(int i= 1;i<=m;i+=2)
    {
    	s2[i] = s2[i-2]+q[i+1]-q[i]; 
    }
    if(n%2==0)
    {
    	ll res=  min(s1[m],s2[m-1]);
    	cout<<res;
    }
    else
    {
    	ll res=inf ; 
    	FOR(i,1,m)
    	{
    		if(i%2==0)
    		{

    		}
    	}
    	cout<<res;
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