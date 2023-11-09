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
const int N =1e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
ll a[N];
void input()
{
 	cin>> n;  
 	for(int i= 1;i<=n;i++)
 	{
 		cin>>a[i] ; 
 	}   
}
void output()
{
 	ll ma1  = 0 ; 
 	ll ma2 = 0 ; 
 	for(int  i=1 ;i<=n;i++)
 	{
 		ll tmp1 = ma2+a[i] ;  
 		ll tmp2=  ma1-a[i] ;
 		ma1=max(ma1,tmp1) ; 
 		ma2=max(ma2,tmp2) ;  
 	}   
 	cout<<ma1;
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