#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
string bracket ; 
const ll sm = 1e9+7 ; 
const int N = 2e5+5 ;  
vector<vector<ll >> fk,fk_1 ;
int n  , k;
int a[N] ;
namespace sub1
{
    ll tinh(int pos , int sum , int k , vector<vector<ll>>&f)
    {
        if(sum<0||sum>k)return 0 ; 
        if(pos==n+1)return sum==0 ; 
        ll &val = f[pos][sum] ; 
        if(val!=-1)return val; 
        return val=(3*tinh(pos+1,sum+1,k,f)%sm+tinh(pos+1,sum-1,k,f))%sm ;
    }
    void xuly()
    {
        fk.resize(n+2,vector<ll>(k+2,-1)) ; 
        fk_1.resize(n+2,vector<ll>(k+2,-1)) ;
        int sum = 0 , ok = 0 ;
        ll pos = 1 ; 
        for(int i=1;i<=n;i++)
        {
            for(int j=-3;j<min(0,a[i]);j++)
            {
                (pos+=tinh(i+1,sum+1,k,fk))%=sm;
                if(sum+1!=k&&ok==0)
                    (pos-=tinh(i+1,sum+1,k-1,fk_1)-sm)%=sm;
            }
            if(a[i]<0)sum++ ;   
            else sum-- ; 
            ok|=(sum==k) ; 
        }   
        cout<<pos ;
    }
} 
namespace sub2
{
    ll  fac[N] , inv_fac[N]; 
    ll pw(ll a, ll n)
    {
        if(n==0) return 1;
        ll b = pw(a,n/2); 
        if(n&1)return b*b%sm*a%sm;
        return b*b%sm ;
    }
    ll C(int k ,int n)
    {
        if(k>n)return 0; 
        return fac[n]*inv_fac[k]%sm*inv_fac[n-k]%sm; 
    }
    long long path(int n ,int u, int v )
    {
        if((v-u+n)%2)return 0 ;
        return C((v-u+n)/2,n);
    }
    ll tinh(int n , int h ,int k)
    {
        long long ans = path(n,h,0) ; 
        for(int i=1;i<=k;i++)
        {

        }
        return ans ; 
    }
    void xuly()
    {
        for(int i=1;i<=n;i++)fac[i] = fac[i-1]*i%sm; 
        inv_fac[n] = pw(fac[n],sm-2) ; 
        for(int i=n-1;i>=0;i--)
        {
            inv_fac[i] = inv_fac[i+1]*(i+1)%sm ; 
        }
        int sum = 0 , ok = 0 ;
        ll pos = 1 ; 
        for(int i=1;i<=n;i++)
        {
            for(int j=-3;j<min(0,a[i]);j++)
            {
                (pos+=tinh(i+1,sum+1,k))%=sm;
                if(sum+1!=k&&ok==0)
                    (pos-=tinh(i+1,sum+1,k-1)-sm)%=sm;
            }
            if(a[i]<0)sum++ ;   
            else sum-- ; 
            ok|=(sum==k) ; 
        }
        cout<<pos ; 
    }   
}
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;
    }
    cin>> bracket ;  
    int sum = 0 ;
    map<char,int> num ={{'(',-3},{'[',-2},{'{',-1},{')',0},{']',1},{'}',2}} ; 
    for(auto x : bracket)
    {
        a[++n] = num[x] ; 
        if(a[n]<0)++sum ; 
        else --sum ;
        k=max(k,sum) ; 
    } 
    if(n<=1e3)sub1::xuly() ; 
    else sub2::xuly() ;
    cerr<<"ok" ;
    return 0 ;
}