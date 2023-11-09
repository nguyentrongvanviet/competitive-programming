
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
	ll val ; 
	int id;  
	bool operator<(const bg& a)const
	{
		return val<a.val;
	}
};
int n ; 
ll k ;
int pos[N];
ll a[N]  ; 
ll s[N] ; 
bg x[N] ; 
ll st[4*N];
void up(int id , int l ,int r,int pos , ll val)
{
	if(l==r&&r==pos)
	{
		st[id]= 1;
		return ; 
	}
	if(r<pos||pos<l)return ; 
	int mid =(l+r)/2; 
	up(id*2,l,mid,pos,val);  
	up(id*2+1,mid+1,r,pos,val); 
	st[id]=st[id*2]+st[id*2+1];
}
ll get(int id , int l , int r, int t , int p )
{
	if(t<=l&&r<=p)
	{
		return st[id] ; 
	}
	if(r<t||p<l)return 0; 
	int mid =(l+r)/2 ; 
	return get(id*2,l,mid,t,p)+get(id*2+1,mid+1,r,t,p) ;
}
int  np1(ll val)
{
	int l =1 ; 
	int r =n ; 
	int ans =0 ; 
	while(l<=r)
	{
		int mid =(l+r)/2;  
		if(x[mid].val<val)
		{
			ans=mid; 
			l=mid+1; 
		}
		else 
		{
			r=mid-1 ;
		}
	}
	return ans;
}
int np2(ll val)
{
	int l = 1; 
	int r = n ; 
	int ans= n+1; 
	while(l<=r)
	{
		int mid=(l+r)/2; 
		if(x[mid].val>val)
		{
			ans= mid ; 
			r=mid-1  ; 
		}
		else 
		{
			l=mid+1;
		}
	}
	return ans ; 
}
void input()
{
    cin>> n>> k ; 
   	x[1] = {0,0} ;
    for(int i=1 ;i<=n;i++)
    {
    	cin>>a[i];
    	s[i] =s[i-1]+a[i] ; 
    	x[i+1] = {s[i],i} ; 
    }
   	sort(x+1,x+n+1) ;
   	for(int i= 1;i<=n;i++)
   	{
   		pos[x[i].id] = i ; 
   	}
   	up(1,1,n,pos[0],1);
   	ll res=0  ;
   	for(int i=1 ;i<=n;i++)
   	{
   		int l = np1(s[i]-k);
   		int r=  np2(s[i]+k);
   		res+=get(1,1,n,1,l); 
   		res+=get(1,1,n,r,n);
   		up(1,1,n,pos[i],1);
   	}
   	cout<<res; 
}	
void output()
{
	ll res= 0;  
 	for(int i= 1;i<=n;i++)
 	{
 		for(int j = i ;j>=1;j--)
 		{
 			if(abs(s[i]-s[j-1])>k)
 			{
 				res++ ; 
 			}
 		}
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
        // output(); 
        // sub();
    }
    return 0;
}