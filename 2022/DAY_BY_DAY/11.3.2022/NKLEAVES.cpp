#include<bits/stdc++.h>
using namespace std;

#define TASK "NKLEAVES"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =2e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n  , k ; 
ll a[N] ,si[N] , s[N] ; 
ll cp(int  l , int r )
{
	return si[r]-si[l]-l*(s[r]-s[l]);
}  
ll pre[N] ,now[N] ;
void tinh(int l , int r, int t , int p  )
{
	if(l>r)return ; 
	int mid =(l+r)/2 ;
	ll best =inf  ; 
 	int pos=t;
 	now[mid] =inf ; 
	for(int  i =t ;i<=min(p,mid);i++)
	{
		ll value = pre[i-1]+cp(i,mid);
		if(value<best)
		{
			best =value; 
			pos = i ;
		}
	}
	now[mid] =best ; 
	tinh(l,mid-1,t,pos);
	tinh(mid+1,r,pos,p);
}
void doc()
{
	cin>>n>> k;  
	for(int i=1 ;i<=n;i++)
		cin>>a[i],
		si[i]=si[i-1]+i*a[i],
	    s[i]=s[i-1]+a[i]; 
	for(int i=1 ;i<=n;i++)
	{
		pre[i] = now[i] = cp(1,i);
	}
	for(int j=2;j<=k;j++)
	{
		tinh(j,n,j,n);
		for(int i= 1;i<=n;i++)
		{
			pre[i] =now[i];
		}
	}
	cout<<now[n]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}