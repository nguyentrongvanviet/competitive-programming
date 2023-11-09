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

struct cap
{
    int x , y ; 
    bool operator<(const cap& a )const
    {
        return x<a.x||(x==a.x&&y>a.y) ; 
    }
};
int n ; 
int res= 0 ; 
vector<cap>q;  
int b[N];
int f[N];
int a[N] ;
void input()
{
    cin>> n ;
    for(int i=1 ;i<=n;i++)cin>>a[i] ; 
}
int np1(int val)
{
    int l =1 ; 
    int r =n ; 
    int ans ; 
    while(l<=r)
    {
        int mid =(l+r)/2;
        if(b[mid]>=val)
        {
            ans= mid ; 
            r=mid-1 ;
        }
        else 
        {
            l=mid+1; 
        }
    }
    return ans ; 
}
void lis(int mid)
{
    for(int i= 1;i<=n;i++)b[i]=oo ; 
    for(int i =0  ;i<_sz(q);i++)
    {
        if(q[i].x<=mid&&mid<q[i].y)
        {
            int pos =  np1(q[i].y) ;
            b[pos]= q[i].y;
            res=max(res,pos) ;  
        }
    }   
}
void output()
{
    for(int i=1 ;i<=n;i++)
   	{
   		for(int j= i+1;j<=n;j++)
   		{
   			if(a[i]<a[j])
   			{
   				q.pb({i,j}) ; 
   			}
   		}
   	}
    vector<pii>tmp ;
    sort(q.begin(),q.end());
    for(int mi= 2;mi<=2;mi++)
    {
        lis(mi) ;  
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