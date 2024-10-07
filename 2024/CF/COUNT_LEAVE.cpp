#include<bits/stdc++.h>
using namespace std ; 
#define ll long long 
const int N = 3e6+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ;
ll fac[N] , inv_fac[N] ; 

ll pw(ll a, ll n)
{
    if(n==0) return 1;
    ll b = pw(a,n/2); 
    if(n&1)return b*b%sm*a%sm;
    return b*b%sm ;
}
ll C(int k ,int n)
{
    return fac[n]*inv_fac[k]%sm*inv_fac[n-k]%sm; 
}
int nt[N] ;
vector<int>primes ;
void snt()
{
    for(int i=2;i<=int(1e6);i++)
    {
        if(nt[i]==0)
        {
            nt[i] = 1 ;
            primes.push_back(i) ;  
            for(int j=i;j<=int(1e6)/i;j++)
            {   
                nt[i*j] = 1; 
            }
        }
    }
}   
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    snt() ;
    fac[0] = 1; 
    for(int i=1;i<=(int)3e6;i++)fac[i] = fac[i-1]*i%sm ; 
    inv_fac[(int)3e6] = pw(fac[(int)3e6],sm-2)  ; 
    for(int i=(int)3e6-1;i>=0;i--)inv_fac[i] = inv_fac[i+1]*(i+1)%sm ; 
    int t  ;cin>>t ;
    while(t--)
    {
        int n , k ,d ;  
        cin>> n >> k >>d ; 
        ll res = 1; 
        for(auto x : primes)
        {
            if(x==1)break;
            int cnt = 0; 
            while(n%x==0)
            {
                cnt++ ; 
                n/=x ; 
            }
            if(cnt)(res*=C(cnt*k,cnt*k+d))%=sm ; 
        }
        if(n!=1)
        {
            (res*=C(k,k+d))%=sm; 
        }
        cout<<res<<'\n' ; 
    }
}
