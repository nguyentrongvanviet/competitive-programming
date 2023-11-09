#include<bits/stdc++.h>
using namespace std;

#define TASK "rowboat"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
// #define int long long 
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#define int long long 
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n , m ;
int res=0  ;  
int mu[5*N] , fac[5*N] ; 
int cong(int a, int b )
{
	return ((ll)a+(ll)b)%sm;
}
int nhan(int a, int b)
{
	return (ll)a*(ll)b%sm; 
}
int tru(int a, int b)
{
	return ((ll)a-(ll)b+sm)%sm;
}
int pw(int a , int n)
{
    if(n==0)return 1; 
    int b = pw(a,n/2) ; 
    if(n&1)
    {
        return (ll)b*(ll)b%sm*(ll)a%sm ; 
    }
    else 
    {
        return (ll)b*(ll)b%sm;
    }
}
int C(int k ,int n )
{
    if(k>n)return 0 ;
    int tu = fac[n] ; 
    int mau =nhan(fac[k],fac[n-k]);  
    return nhan(tu,pw(mau,sm-2));
}
int A(int k ,int n)
{
    if(k>n)return 0 ;
    int tu =fac[n] ;    
    int mau = fac[n-k];
    return nhan(tu,pw(mau,sm-2)); 
}
void doc()
{
 	cin>> n>>m ;
    mu[0] =1 ;  
 	fac[0] =1 ; 
 	FOR(i,1,8*n)
 	{	
        mu[i] = nhan(mu[i-1],2); 
 		fac[i] = nhan(fac[i-1],i)%sm;
 	}
    // res=fac[n];
 	res=fac[2*n];      
    FOR(i,1,m)
    {
        int tmp = nhan(C(2*n-2*i,2*n-2*i+i),nhan(nhan(fac[2*n-2*i],fac[i]),nhan(C(i,m),mu[i])));
        // cout<<tmp<<endl;
        if((i&1)==0)
        {
            res=cong(res,tmp);
        }   
        else
        {
            res=tru(res,tmp) ;
        }
    }
    cout<<res<<"\n";
}
void xuly()
{
    
}
 main()
{
    IOS(); 
    int test ; 
    cin>>test; 
    while(test--)
    {
         doc(); 
         xuly();
    } 
    return 0 ; 
}