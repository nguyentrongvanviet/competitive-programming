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
const ll sm =  2111992,cs=330 ,inf = 1e17;

int n  , k ;  
ll f[N] , sum[N];
void input()
{
 	cin>> n>> k ; 
}
void output()	
{
	f[0] = 1; 
	sum[0 ] =1 ; 
    for(int  i=1 ;i<=n;i++)
    {
    	if(i<=k)
		{
   			f[i] =1 ;
    	}
    	else f[i] =sum[i-k-1];
    	sum[i]=(sum[i-1]+f[i])%sm;
    }
    ll res=0 ; 
    for(int i=1;i<=n+1;i++)
    {
    	res=(res+f[i-1])%sm;
    }
    cout<<res;
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