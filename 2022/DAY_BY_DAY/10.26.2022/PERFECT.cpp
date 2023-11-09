#include<bits/stdc++.h>
using namespace std;

#define TASK "PERFECT"

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

struct NN
{	
	ll mi , ma ; 
};	
int n , q ; 
ll a[N] ; 
ll s[N] ; 
NN st[4*N] ;
void build(int id , int l , int r )
{
	if(l==r)
	{
		st[id].mi=a[l] ;
		st[id].ma=a[l] ; 
		return ; 
	}
	int mid=(l+r)>>1; 
	build(id*2,l,mid) ; 
	build(id*2+1,mid+1,r) ; 
	st[id].mi=min(st[id*2].mi,st[id*2+1].mi);  
	st[id].ma=max(st[id*2].ma,st[id*2+1].ma) ;
}
ll getmi(int id , int l ,int r , int t,  int p )
{
	if(t<=l&&r<=p)return st[id].mi ;
	if(r<t||p<l)return inf ; 
	int mid =(l+r)/2; 
	return min(getmi(id*2,l,mid,t,p),getmi(id*2+1,mid+1,r,t,p)) ; 
}
ll getma(int id,int l , int r,int t , int p )
{
	if(t<=l&&r<=p)return st[id].ma;  
	if(r<t||p<l)return -inf ;
	int mid =(l+r)/2 ;
	return max(getma(id*2,l,mid,t,p),getma(id*2+1,mid+1,r,t,p));
}
void doc()
{
 	cin>>n>>q ;
 	for(int i=1 ;i<=n;i++)cin>>a[i],s[i]=s[i-1]+a[i];
 	build(1,1,n);
 	for(int i= 1;i<=q;i++)
 	{
 		int l , r ; cin>>l>>r ; 
 		int mi = getmi(1,1,n,l,r) ; 
 		int ma =getma(1,1,n,l,r) ;
 		if(mi+(r-l+1)-1==ma)
 		{
 			cout<<"YES"<<"\n";
 		}
 		else 
 		{
 			cout<<"NO"<<"\n";
 		}
 	}   
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