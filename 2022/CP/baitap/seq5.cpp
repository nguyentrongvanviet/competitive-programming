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

struct bg
{
	ll val ; 
	int id ;
};		
bool cmp(bg a, bg b )
{
	if(a.val==b.val)
	{
		return a.id<b.id ; 
	}
	return a.val<b.val;  
}
int n ; ll k ; 
ll value = 0 ; 
bg q1[N] ,q2[N]; 
int a[N] ; 
ll s[N] ; 

void input()
{
 	cin>> n>> k; 
 	for(int i= 1;i<=n;i++)
 	{
 		cin>>a[i] ; 
 		value+=a[i] ;  
 	}
 	value=value-k; 
}
void output()
{
	s[0] =0 ;
   	for(int i= 1 ;i<=n;i++)
   	{
   		s[i] =s[i-1]+a[i] ; 
   		q1[i]={s[i-1],i}; 
   	}
   	s[n+1]= 0 ; 
   	for(int i=n;i>=1;i--)
   	{
   		s[i]=s[i+1]+a[i] ; 
   		q2[i]={s[i+1],i};
   	} 
   	sort(q1+1,q1+n+1,cmp) ; 
   	sort(q2+1,q2+n+1,cmp) ; 
   	int l =1 ,  r= n ;
   	int res= 0 ;  
   	while(l<=n&&r>=1)
   	{
   		ll sum =q1[l].val+q2[r].val;  
   		if(sum==value)
   		{
   			l++ ; 
   			r-- ; 
   			res=max(res,q2[r].id-q1[l].id+1);
   		}
   		else if(sum<value)
   		{
   			l++; 
   		}
   		else 
   		{
   			r-- ; 
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
        output(); 
    }
    return 0;
}