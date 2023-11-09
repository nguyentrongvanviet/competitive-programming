#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define int long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =6e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
string s1;  
ll a[N] ,s[N] ; 
void input()
{
 	cin>>s1 ; 
 	n= s1.size();
 	s[0]=0;
 	for(int i=1 ;i<=n;i++)
 	{
 		s[i] = 0 ; 
 	}
 	for(int i=1;i<=n;i++)
 	{
 		a[i] = s1[i-1]-'a'+1; 
 		s[i] =(s[i-1]+a[i])%sm ; 
 	}   
}
ll f[N] ; 
void output()
{
	for(int i=1 ;i<=n;i++)
	{
		f[i] = 0 ;
	}
	f[n] =a[n];
	ll x= a[n]; 
    for(int i=  n-1;i>=1;i--)
    {
    	f[i] = (((n-i+2)*(n-i+1)/2%sm*a[i]%sm+f[i+1])%sm+x)%sm;
    	x= (x+a[i]*(n-i+1)%sm)%sm;
    }
    ll res= 0 ;
    for(int i = 1;i<=n;i++)
    {
    	res=(res+f[i])%sm;
    }
    cout<<res<<endl;
}
 main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}