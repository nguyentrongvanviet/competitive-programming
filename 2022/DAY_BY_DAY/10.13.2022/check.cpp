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

int n ; 
ll a[N] ; 
void input()
{
 	cin>> n  ; 
 	for(int i=1 ;i<=n;i++)
 	{
 		cin>>a[i] ; 
 	}   
 	ll res= inf ;
 	sort(a+1,a+n+1) ; 
 	do
 	{
 		ll mi  =a[1] ; 
 		ll ma = a[1] ;
 		ll ans=  0 ; 
 		for(int i= 2 ;i<=n;i++)
 		{
 			mi = min(mi,a[i]) ; 
 			ma =max(ma,a[i]) ; 
 			ans+=(ma-mi) ; 
 		}
 		if(ans<res)
 		{
 			for(int i =1 ;i<=n;i++)
 			{
 				cout<<a[i]<<" "; 
 			}cout<<"\n";
 		}
 		res=min(res,ans) ; 
 	}while(next_permutation(a+1,a+n+1)) ;
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