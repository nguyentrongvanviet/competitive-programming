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
ll a[N] , w[N] , d[N] ;  
ll sw[N] ,  s[N] ;  
ll res= inf ; 
ll cost(int l , int r)
{
	return d[r]*(sw[r]-sw[l-1])-(s[r]-s[l-1]);
}
void tinh(int l , int r , int bestl , int bestr )
{
	if(l>r)return ;
	int mid =(l+r)/2;
	ll ans =inf ;  
	ll best = 0;
	for(int i=max(mid+1,bestl);i<=bestr;i++)
	{
		ll sum =cost(1,mid)+cost(mid+1,i)+cost(i+1,n+1);
		if(ans>sum)
		{
			ans = sum ; 
			best = i ; 
		}
	}	
	res=min(res,ans) ; 
	tinh(l,mid-1,bestl,best);
	tinh(mid+1,r,best,bestr);  
}
void input()
{
	cin>> n;  
	for(int i  =1 ;i<=n;i++)
	{
		cin>>w[i]>>d[i] ; 
	}    
	for(int i= 1;i<=n;i++)d[i]=d[i-1]+d[i];
	for(int i = 1; i<=n;i++)
	{
		sw[i] =sw[i-1]+w[i] ; 
		s[i]=s[i-1]+w[i]*d[i] ; 
	}
	tinh(1,n,1,n);
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