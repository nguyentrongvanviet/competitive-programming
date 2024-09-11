#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 

int a[N] ;
struct DL
{
    int x, y; 
    bool operator<(const DL&a )const{
        return x<a.x||(x==a.x&&y<a.y); 
    }
} ; 
DL b[N] ;
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int n; cin>> n; 
    for(int i=1;i<=n;i++)cin>>a[i] ; 
    int m; cin>> m; 
    for(int i=1;i<=m;i++)
    {
        cin>>b[i].x>>b[i].y;
    }
    sort(b+1,b+m+1) ; 
    int mi = 1e9 ; 
    for(int i=m;i>=1;i--)
    {
        mi = min(mi,b[i].y) ; 
        b[i].y= mi ;
    }
    int res = 0 ; 
    for(int i=1;i<=n;i++)
    {
        int l = 1 ;
        int r = m ; 
        int ans = 0 ; 
        while(l<=r)
        {
            int mid = (l+r)>>1 ;
            if(b[mid].x>=a[i])ans=mid,r=mid-1 ;
            else l=mid+1 ;
        }
        res+=b[ans].y ; 
    }
    cout<<res<<'\n';
}