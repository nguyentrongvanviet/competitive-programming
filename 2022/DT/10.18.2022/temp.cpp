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
ll s[N];
ll sum =0  ; 
int m[N] ;
void input()
{
    cin>> n;  
    for(int i=1 ;i<=n;i++)
    {
    	cin>>a[i] ; 
    	s[i] =s[i-1]+a[i] ; 
    	sum+=a[i] ; 
    }
    if(sum%3!=0)
    {
    	cout<<-1 ;
    	return ; 
    }
    ll res = 0;
    for(int i=n;i>=1;i--)
    {
    	if(s[n]-s[i-1]==sum/3)
    	{
    		m[i] = i ;
    	}
    	else 
    	{
    		m[i] =m[i+1];
    	}
    }
    for(int i=1 ;i<=n;i++)
    {
    	if(s[i]==sum/3&&m[i+1]!=0)
    	{
    		cout<<i-1<<" "<<m[i+1]-1;
    		return ;
    	}
    }
    cout<<-1;
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