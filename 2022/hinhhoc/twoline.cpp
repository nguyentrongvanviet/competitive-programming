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
};  
pt a[6];
ll ccw(pt a,  pt b , pt c)
{
    return (b.x-a.x)*(c.y-b.y)-(b.y-a.y)*(c.x-b.x);
}
bool inter(ll a, ll b ,ll c, ll d)
{
    if(a>b)swap(a,b) ; 
    if(c>d)swap(c,d) ; 
    return max(a,c)<=min(b,d);  
}
ll sgn(ll x )
{
    return (x>=0? x?1:0:-1); 
}
int n ; 
bool intersect(pt a, pt b , pt c , pt d)
{
    if(ccw(a,b,c)==0&&ccw(a,b,d)==0)
    {
        return inter(a.x,b.x,c.x,d.x) && inter(a.y,b.y,c.y,d.y); 
    }
    return sgn(ccw(a,b,c))!=sgn(ccw(a,b,d)) && sgn(ccw(c,d,a))!=sgn(ccw(c,d,b)); 
}
void inp()
{
    for(int i= 1;i<=4;i++)
    {
        cin>>a[i].x>>a[i].y ; 
    }
    cout<<(intersect(a[1],a[2],a[3],a[4])==1 ? "YES":"NO"); 
    cout<<"\n";  
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    // freopen("i.txt","r",stdin); 
    // freopen("o.txt","w",stdout);
    int test ; 
    cin>> test ;
    while(test--)inp();
    return 0;
}