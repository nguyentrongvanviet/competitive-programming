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
    return a*a;  
}
struct pt 
{
    ll x , y ; 
}; 
ll dis(pt a , pt b)
{
    return sq(a.x-b.x)+sq(a.y-b.y) ; 
}
int n ; 
pt a[5] ; 
pt b[5] ; 
void inp()
{   
    vector<pt>phai ; 
    vector<pt>trai ;
    for(int i= 1; i<=2;i++)
    {
        cin>>a[i].x>>a[i].y; 
        trai.pb(a[i]) ;  
    }
    for(int  i= 1 ;i<=2;i++)
    {
        cin>>b[i].x>>b[i].y ;
        phai.pb(b[i]) ;  
    }
    trai.pb({a[1].x,a[2].y}) ; 
    trai.pb({a[2].x,a[1].y}) ;
    phai.pb({b[1].x,b[2].y}) ; 
    phai.pb({b[2].x,b[1].y}) ;
    ll res= inf ; 
    for(int i= 0 ;i<trai.size();i++)
    {
        for(int j= 0 ;j<trai.size();j++)
        {
            res=min(res,dis(trai[i],phai[j])) ; 
        }
    }
    cout<<res<<"\n"; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int test ; 
    cin>>test ; 
    while(test--)inp();
    return 0;
}