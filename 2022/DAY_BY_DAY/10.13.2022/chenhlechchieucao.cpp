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
ll a[N];
ll mi , ma;  
int q[N] ;
int it =   0 ; 
ll res=0  ;
map<ll,ll>sl;
void input()
{
	cin>> n ;  
	for(int  i= 1;i<=n;i++)
	{
		cin>>a[i] ; 
		sl[a[i]]++ ; 
		if(sl[a[i]]==1)
		{
			q[++it] =a[i]  ;
		}  
	}
	sort(q+1,q+it+1) ;
	n = it ;   
	for(int i =1 ;i<=n;i++)
	{
		a[i] =q[i];
	}
	int l = 1 , r = n;  
	while(1)
	{
		if(r-l+1==2)
		{
			res+=min(sl[a[r]]*(a[r]-a[l]),sl[a[l]]*(a[r]-a[l])) ; 
			break ; 
		}
		else if(r-l+1==1)
		{
			break ; 
		}
		res+=min(sl[a[r]]*(a[r]-a[l+1])+sl[a[l]]*(a[r]-a[l]),sl[a[l]]*(a[r-1]-a[l])+sl[a[r]]*(a[r]-a[l]));
		l++ ;  
		r-- ; 
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