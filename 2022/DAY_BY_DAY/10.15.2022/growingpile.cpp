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
ll d,a[N] ; 
ll res=0 ; 
void input()
{
 	cin>> n>> d; 
 	for(int i= 1;i<=n;i++)
 	{
		cin>>a[i] ;  
 	}
 	sort(a+1,a+n+1) ; 
 	for(int i = n-1 ;i>=1;i--)
 	{
 		a[i]+=res*d;  
 		if((a[i+1]-a[i])%d)
 		{
 			cout<<-1 ; 
 			return ;
 		}
 		else 
 		{
 			res+=(n-i)*(a[i+1]-a[i])    /d;
 		}
 		a[i]+=(n-i)*(a[i+1]-a[i])/d*d;
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