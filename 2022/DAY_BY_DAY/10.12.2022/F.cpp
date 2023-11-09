#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =2e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
string s1 ; 
ll s[N] ;
ll f[N] ; 
ll sum[N];
ll mu[N]  ; 
ll a[N] ; 
void input()
{
 	cin>> s1 ;
 	n =s1.size() ; 
 	s1='$'+s1;
 	for(int i=1;i<=n;i++)
 	{
 		a[i] =s1[i]-'0' ; 
 	}
 	mu[0]=1 ; 
    s[0]=1; 
 	for(int i=1;i<=2*n+5;i++)
 	{
 		mu[i] = (mu[i-1]*10)%sm;  
        s[i] =(s[i-1]+mu[i]*mu[i]%sm)%sm; 
 	}
    for(int i=1,b=1 ;i<=n;b+=2,i++)
    {
        sum[i]=sum[i-1]+mu[b];
    }
 	f[n] = (a[n]*a[n])%sm;
 	ll x = a[n]*10%sm;
 	for(int i =n-1;i>=1;i--)
 	{
 		f[i] =((a[i]*a[i]*s[n-i]%sm+2*a[i]*x%sm)%sm+f[i+1])%sm;
 		x= (a[i]*sum[n-i+1]%sm+x*10%sm)%sm;
 	}   
 	ll res=0 ;  
 	for(int i= 1; i<=n;i++)
 	{
 		res=(res+f[i])%sm ; 
 	}
 	cout<<res; 
}
void output()
{
    
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}