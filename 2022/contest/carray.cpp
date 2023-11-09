#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =1e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

ll n, m , k ; 
ll mu[N];
ll f[N] ; 
ll su[N] ;
void inp()
{
    cin>>n>>m>> k ;
    mu[0]= 1; 
    for(int i=1;i<=n;i++)
    {
        mu[i] = (mu[i-1]*m)%sm;  
    }  
    // if(k==1)
    // {
    //     cout<<mu[n];
    //     return ; 
    // }else if(m==1)
    // {
    //     cout<<1 ;
    //     return  ; 
    // }
    // f[0]=1 ;
    f[k]=m;
    for(int i=k+1;i<=n;i++)
    {
        // cout<<f[i-1]*m<<" "<<mu[i-k]*m<<" "<<m*mu[i-k]<<endl;
        f[i]= ((f[i-1]*m)%sm+(mu[i-k]*m)%sm-m*mu[i-1-k]%sm+sm*sm)%sm; 
    }
    cout<<f[n];
}
void sub()
{
    cin>>n>>m>> k;  
    mu[0] = 1; 
    for(int i =1 ;i<=n;i++)
    {
        mu[i] = (mu[i-1]*m)%sm ; 
    } 
    for(int i= 1 ;i<=k-1;i++)
    {
        f[i]=mu[i]; 
    } 
    f[k] =(mu[k]-m+sm)%sm;
    for(int i=k+1;i<=n;i++)
    {
        f[i] = (f[i-1]*m%sm-f[i-k]*(m-1) %sm+sm)%sm;
    }
    cout<<(mu[n] - f[n]+sm)%sm; 
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    // inp();
    sub();
    return 0;
}