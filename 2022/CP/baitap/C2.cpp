#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define sz(a) (int)a.size() 
#define all(a) (a.begin(),a.end())
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n  ,q ; 
int l[N] , a[N] , pre[N] ;  
void input()
{
   	cin>> n ; 
   	for(int i= 1;i<=n;i++)
   	{
   		cin>>a[i] ; 
   	}
}
void output()
{
	int L = 1;
	ll ans=  0 ; 
	for(int i= 1;i<=n;i++)
	{
		pre[i]=L ; 
		while(a[i]<(i-L+1))
		{
			L++ ; 
		}
		l[i] =L;
		ans+=i-l[i]+1;  
	}	    
	cin>>q; 
	while(q--)
	{
		int pos , val ; 
		cin>>pos>>val ; 
		if(val>a[pos])
		{
			cout<<ans-(pos-l[pos]+1)+(pos-min(pre[pos],val)+1)<<"\n";  
		}
		else if(val<a[pos])
		{
			cout<<ans-(pos-l[pos]+1)+(pos-val+1)<<"\n";
		}
		else 
		{
			cout<<ans<<"\n"; 
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    // cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}