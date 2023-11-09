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

struct bg 
{
	ll x, y , z; 
	bool operator <(const bg &a)const 
	{
		return x-y>a.x-a.y;  
	}
};	
int n  ,x, y, z; 
priority_queue<ll,vector<ll>,greater<ll>>q ; 
ll res= 0  ;
bg a[N] ; 
ll l[N] ; 
ll r[N] ;  
void input()
{
 	cin>> x>>y>>z;  
 	n =x+y+z; 
 	for(int i= 1;i<=n ;i++)
 	{
 		cin>>a[i].x>>a[i].y>>a[i].z; 
 		res+=a[i].z ; 
 	}   
}
void output()
{
    sort(a+1,a+n+1);
    ll s =0 ;
    for(int i= 1;i<=x;i++)
    {
    	q.push(a[i].x-a[i].z);
    	s+=a[i].x-a[i].z;
    } 
   	l[x]=s ; 
    for(int i=x+1;i<=n;i++)
    {
    	q.push(a[i].x-a[i].z) ; 
    	s+=a[i].x-a[i].z; 
    	s-=q.top() ;
    	q.pop();
    	l[i]=s; 
    }		
    while(!q.empty())
    {
    	q.pop();
    }
    s= 0 ; 
    for(int i=n;i>=n-y+1;i--)
    {
    	q.push(a[i].y-a[i].z) ; 
    	s+=a[i].y-a[i].z ; 
    }
    for(int i=n-y;i>=1;i--)
    {
    	q.push(a[i].y-a[i].z) ; 
    	s+=a[i].y-a[i].z; 
    	s-=q.top() ; 
    	q.pop() ; 
    	r[i]=s; 
    }
    ll ans= -inf ; 
    for(int i=x ;i<=n-y;i++)
    {
    	ans=max(ans,l[i]+r[i+1]) ; 
    }
    cout<<res+ans;
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