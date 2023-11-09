#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define int long long 
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

struct bg
{
    int u ; 
    ll t ;   
}; 
int n , m ; 
string s ; 
bg a[N] ; 
int b[N]  ;
ll f[N][55] ;   
ll tonum(string s )
{
    ll ans=0 ;  
    for(int i =0  ;i<s.size();i++)
    {
        ans=(ans*10%sm+s[i]-'0')%sm;
    }
    return ans;  
}
ll v(ll x , ll mu )
{
    ll ans= 1 ;
    while(mu)
    {
        if(mu&1)
        {
            ans=(ans*x)%sm; 
        }
        x=(x*x)%sm ; 
        mu>>=1; 
    }
    return ans;  
}
ll C(ll k , ll n )
{
    ll tu = 1; 
    ll mau=1 ; 
    for(ll i =n-k+1;i<=n;i++)
    {
        tu=(tu*i)%sm;
    }
    for(ll i = 1;i<=k;i++)
    {
        mau= (mau*i)%sm ; 
    }
    return (tu*v(mau,sm-2))%sm;
}
void inp()
{
    cin>> n; 
    cin>> m ; 
    cin>>s;
    int t= 0 ;  
    string tmp="" ;
    char u =s[0] ;  
    for(int i =2;i<=s.size();i++)
    {  
        char x=  s[i-1] ; 
        if('a'<=x&&x<='z')
        {
            a[++t] ={u-'a',tonum(tmp)}; 
            u =x ; 
            tmp=""; 
        }   
        else
        {
            tmp=tmp+s[i-1] ; 
        }
    }
    a[++t]={u-'a',tonum(tmp)};  
    for(int i= 1; i<=m;i++)
    {
        char u ;
        cin>>u ; 
        b[i]=u-'a';
    }
    n =t; 
    for(int i= 1; i<=n;i++)
    {
        f[i][1] = f[i-1][1] ;
        if(a[i].u==b[1])
        {
            f[i][1]=(f[i][1]+a[i].t)%sm; 
        }
        // cout<<f[i][1]<<endl;
    }
    for(int i =0;i<=n;i++)
    {
        f[i][0]=1; 
    }
    for(int j =2;j<=m;j++)
    {
        for(int i =1;i<=n;i++)
        {

            f[i][j] =f[i-1][j] ; 
            if(a[i].u==b[j])
            {
                int t= 0; 
                while(b[j-t]==b[j]&&t<=a[i].t&&j-t>0)
                {
                    // cout<<C(t+1,a[i].t)<<endl;
                    f[i][j]=(f[i][j]+C(t+1,a[i].t)*f[i-1][j-t-1]%sm)%sm;
                    t++;
                }
            }
        }
    }
    cout<<f[n][m];
}
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}