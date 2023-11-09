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
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n  ; 
ll k ; 
ll a[N] , s[N] ; 
map<ll,ll>la;
map<ll,ll>dd;
void input()
{
 	cin>> n >>k ;  
 	for(int i= 1; i<=n;i++)
 	{
 		cin>>a[i] ;
 		a[i] =a[i]-k; 
 		s[i] = s[i-1]+a[i] ; 
 	}   
 	la[0]=0; 
 	dd[0] =1 ; 
 	ll res= 0 ; 
 	for(int i= 1;i<=n;i++)
 	{
 		if(dd[s[i]]==0)
 		{
 			dd[s[i]]=1;
 			la[s[i]]=i; 
 		} 
 		else 
 		{
 			res=max(res,i-la[s[i]]);
 		}
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