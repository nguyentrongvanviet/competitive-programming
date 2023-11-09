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
ll sq(ll a )
{
    return a*a ; 
} 
struct pt 
{
    ll x , y ; 
}; 
pt p[N] ; 
ll ccw(pt a , pt b , pt c )
{
    return (b.x-a.x)*(c.y-b.y)-(b.y-a.y)*(c.x-b.x); 
}
ll dis(pt a , pt b )
{
    return sq(b.x-a.x)+sq(b.y-a.y); 
}
ll dt(pt a, pt b  , pt c)
{
    return abs(ccw(a,b,c)) ; 
}
bool cmp1(pt a , pt b)
{
    return a.y<b.y||(a.y==b.y&&a.x<b.x);
}
bool cmp2(pt a , pt b)
{
    if(ccw(p[1],a,b)==0)
    {
        return dis(a,p[1])<dis(b,p[1]) ; 
    }
    return ccw(p[1],a,b)>0 ;
}

int n  ; 
void convexhull()
{   
    vector<pt>q ;
    sort(p+1,p+n+1,cmp1);
    sort(p+2,p+n+1,cmp2); 
    q.pb(p[1]) ; 
    q.pb(p[2]) ; 
    p[n+1]= p[1];  
    for(int i= 3;i<=n+1;i++)
    {
        while(q.size()>=2&&ccw(q[q.size()-2],q[q.size()-1],p[i])<=0)
        {
            q.pk() ; 
        }
        q.pb(p[i]) ; 
    }   
    
    cout<<q.size()-1<<"\n"; 
    ll area= 0 ;  
    for(ll i =0 ;i<q.size()-1;i++)
    {
        area+=q[i].x*q[i+1].y-q[i+1].x*q[i].y; 
    }
    if(area%2==0)
    {
        cout<<area/2<<".0"<<"\n" ; 
    }  
    else 
    {
        cout<<area/2<<".5"<<"\n";
    }
    q.pk() ;
    for(auto it :q)
    {
        cout<<it.x<<" "<<it.y<<"\n";
    }
}   
void inp()
{
    cin>> n  ; 
    for(int i= 1; i<=n;i++)
    {
        cin>>p[i].x>>p[i].y;  
    }   
    convexhull() ; 
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}