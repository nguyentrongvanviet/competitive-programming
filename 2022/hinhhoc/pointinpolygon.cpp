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

struct pt 
{
    ll x, y ; 
    pt operator -(const pt& a )const 
    {
        return pt{x-a.x,y-a.y} ; 
    }
    ll operator *(const pt& a)const 
    {
        return x*a.y-y*a.x; 
    }
};  
ll ccw(pt a , pt b , pt c)
{
    return (b-a)*(c-b); 
}
ll sgn(ll a )
{
    return a>=0? a?1:0:-1; 
}
int n , m ; 
pt p[N];
bool iter(ll a,  ll b , ll c , ll d )
{
    if(a>b)swap(a,b) ; 
    if(c>d)swap(c,d) ;
    return max(a,c)<=min(b,d) ; 
}
bool cut(pt a,  pt b  , pt c , pt d)
{
    if(ccw(a,b,d)==0&&ccw(a,b,c)==0)
    {
        return iter(a.x,b.x,c.x,d.x)&&iter(a.y,b.y,c.y,d.y); 
    }
    return sgn(ccw(a,b,c))!=sgn(ccw(a,b,d))&&sgn(ccw(c,d,a))!=sgn(ccw(c,d,b)); 
}
bool contain (pt a, pt b , pt c )
{
    if(ccw(a,b,c)!=0)return 0 ; 
    return  min(a.x,b.x)<=c.x&&c.x<=max(a.x,b.x) &&min(a.y,b.y)<=c.y&&c.y<=max(a.y,b.y);
}
bool check(pt a)
{
    pt out = {a.x+1,oo+1}; 
    p[n+1] = p[1] ;
    bool on = 0 ; 
    int cnt =0 ;  
    for(int i= 1;i<=n;i++)
    {
        if(contain(p[i],p[i+1],a))
        {
            on =1;
            break ; 
        } 
        if(cut(a,out,p[i],p[i+1]))cnt++ ; 
    }
    if(on)
    {
        cout<<"BOUNDARY";
    }
    else if(cnt&1)
    {
        cout<<"INSIDE";
    }
    else 
    {
        cout<<"OUTSIDE"; 
    }
    // cout<<cnt<<endl;
    cout<<"\n";  
}
void inp()
{
    cin>> n >> m ;
    for(int i= 1;i<=n;i++)
    {
        cin>>p[i].x>>p[i].y; 
    }
    for(int i= 1;i<=m;i++)
    {
        pt x ; 
        cin>>x.x>>x.y;
        check(x) ; 
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    // freopen("i.txt","r",stdin); 
    // freopen("o.txt/w",stdout); 
    inp();
    return 0;
}