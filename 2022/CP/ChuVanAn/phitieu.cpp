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
#define int long long 

int n ; 
ll  a[N] ; 
ll f[N];  
int pre[N];
void input()
{
 	cin>>n ; 
 	for(int i =1 ;i<=n;i++)cin>>a[i] ;    
}
void output()
{
	f[1]= a[1] ; 
	f[2] =a[1]+a[2] ;
	pre[1] = 0 ; 
	pre[2] =  0 ;
	for(int i =3;i<=n;i++)
	{
		f[i]=f[i-1] ;
		pre[i] = i-1; 
		if(f[i-3]+a[i]+a[i-1]>f[i])
		{
			f[i]= f[i-3]+a[i]+a[i-1] ; 
			pre[i] = i-3;  
		}
		if(f[i-2]+a[i]>f[i]) 
		{
			f[i]=f[i-2]+a[i] ; 
			pre[i] =i-2; 
		}	
	}
	vector<int>q;
	int x= n ; 
	while(x)
	{
		int u = pre[x] ; 
		if(f[u]==f[x])
		{
			x=u  ; 
			continue ; 
		}
		q.pb(x) ; 
		if(f[u]+a[x]==f[x])
		{
			x=u ; 
			continue;  
		}
		if(f[u]+a[x]+a[x-1]==f[x])
		{
			q.pb(x-1) ;
			x=u  ; 
			continue ;  
		}
	} 
	cout<<_sz(q)<<" "<<f[n]<<"\n";
	for(int i= 0 ;i<_sz(q);i++)
	{
		cout<<q[i]<<"\n";
	}
}
main()
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