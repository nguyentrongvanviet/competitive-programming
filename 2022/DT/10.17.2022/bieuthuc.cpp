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
const int N =3e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
ll  l[N]  ,r[N]  ,a[N] ;
priority_queue<ll,vector<ll>,greater<ll>> trai;
priority_queue<ll>phai;   
void input()
{
	cin>> n ;
	for(int i=1 ;i<=3*n;i++)cin>>a[i] ;
	ll s=0 ; 
	for(int i=1 ;i<=n;i++)
	{
		trai.push(a[i]) ;
		s+=a[i] ; 
	}  	    
	l[n] = s;  
	for(int i = n+1;i<=3*n;i++)
	{
		trai.push(a[i]) ;
		s+=a[i] ; 
		s-=trai.top(); 
		trai.pop();
		l[i]=s;
	}
	s=0  ;
	for(int i= 3*n; i>=2*n+1;i--)
	{
		phai.push(a[i]);  
		s+=a[i] ;
	}
	r[2*n+1] =s;
	for(int i =2*n;i>=1;i--)
	{
		phai.push(a[i]) ;
		s+=a[i] ; 
		s-=phai.top();
		phai.pop();
		r[i]=s;
	}
	ll res= 0 ;  
	for(int i= n;i<=2*n;i++)
	{
		res=max(res,l[i]-r[i+1]);
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