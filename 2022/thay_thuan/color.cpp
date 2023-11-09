#include<bits/stdc++.h>
using namespace std;

#define TASK "color"

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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ; 

int n , k ;
int a[N] ;
int f[N]  ; 
int s1[N] , s2[N] ;
int st[4*N];
void doc()
{
    cin>> n >> k;   
    int la1 =0  ; 
    int la2 =0 ;  
    FOR(i,1,n)cin>>a[i],s1[i]=s1[i-1]+(a[i]==1),s2[i]=s2[i-1]+(a[i]==2);
    f[0] =oo;
    FOR(i,1,n)
    {
        
    }
    cout<<f[n];
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