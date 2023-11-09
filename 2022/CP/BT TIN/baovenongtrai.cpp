#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
ll sq(ll a)
{
    return a*a; 
}
struct pt 
{
    ll x , y ;
};  
int n;  
pt p[N] ; 

ll dis(pt a , pt b)
{
    return sq(a.x-b.x)+sq(a.y-b.y); 
}
ll ccw(pt a , pt b , pt c )
{
    return (b.x-a.x)*(c.y-b.y) - (b.y-a.y)*(c.x-b.x) ; 
}
ll dt(pt a ,  pt b  , pt c )
{
    return abs(ccw(a , b , c  )) ; 
}
bool cmp2(pt a , pt b )
{
    if(ccw(p[1],a,b)==0){return dis(p[1],a)<dis(p[1],b);}   
    return ccw(p[1],a,b)>0; 
}
bool cmp1(pt a , pt b )
{
    return a.y<b.y||(a.y==b.y&&a.x<b.x) ; 
}
vector<pt> convexhull()
{
    vector<pt>q; 
    sort(p+1,p+n+1,cmp1) ; 
    sort(p+2,p+n+1,cmp2) ; 
    q.pb(p[1]) ;    
    q.pb(p[2]) ; 
    p[n+1]=p[1]; 
    for(int i= 3 ;i<=n+1;i++)
    {
        while(q.size()>=2&&ccw(q[q.size()-2],q[q.size()-1],p[i])<=0)
        {
            q.pk() ; 
        }
        q.pb(p[i]); 
    }
    q.pk(); 
    return q; 
}
void inp()
{
    cin>> n  ; 
    for(int i =1 ;i<=n;i++)
    {
        cin>>p[i].x>>p[i].y ; 
    }
    vector<pt>q =convexhull() ;
    int m ; 
    cin>>m; 
    n = q.size();
    for(int i= 1; i<=n;i++)
    {
        p[i] = q[i-1];
        // cout<<p[i].x<<" "<<p[i].y<<endl;
    }
    int res= 0 ;
    while(m--)
    {
        ll x,  y;  
        cin>>x>> y ; 
        pt u = {x,y}; 
        int l = 2; 
        int r =n-1; 
        x= 0 ; 
        while(l<=r)
        {
            int mid =(l+r)/2 ;
            if(ccw(p[1],p[mid],u)>=0)
            {
                l =mid+1; 
                x=mid;
            }
            else 
            {
                r=mid-1 ; 
            }
        } 
        if(x==0)continue ;
        y =x+1; 
        if(dt(p[1],p[l],p[r])==dt(p[1],p[x],u)+dt(p[1],u,p[y])+dt(p[x],u,p[y]))res++ ;
    } 
    // cout<<0  ; 
    // return ; 
    cout<<res ; 
}   

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}