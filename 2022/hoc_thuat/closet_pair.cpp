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
    ll x, y;   
}a[N] ; 
bool cmpx(pt a , pt b  )
{
    return a.x<b.x; 
}   
ll sq(int x )
{
    return x*x;  
}
ll closet(vector<int>a)
{

}
int n ; 
void inp()
{   
    cin>> n ;
    for(int i= 1 ;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y ; 
    }
    sort(a+1,a+n+1,cmpx) ; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}