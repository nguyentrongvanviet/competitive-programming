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
int n ; 
pt p[N] ; 
ll area()
{
    ll ans= 0 ; 
    p[n+1] = p[1] ; 
    for(int i =1 ;i<=n;i++)
    {
        ans+=p[i].x*p[i+1].y-p[i].y*p[i+1].x; 
    }
    return ans ; 
}
void inp()
{
    int m ; 
    cin>> n>> m ; 
    for(int i= 1;i<=n;i++)
    {
        cin>>p[i].x>>p[i].y; 
    }
    ll res=  area();
    cout<<abs(res);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    // freopen("i.txt","r",stdin); 
    // freopen("o.txt","w",stdout); 
    inp();
    return 0;
}