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
    pt operator -(const pt& a)const 
    {
        return pt{x-a.x,y-a.y} ; 
    }  
    ll operator *(const pt&a )const 
    {
        return x*a.y-y*a.x; 
    }
};  
pt a[5];
int n ; 
void inp()
{
    for(int i =1;i<=3;i++)
    {
        cin>>a[i].x>>a[i].y; 
    }   
    if((a[2]-a[1])*(a[2]-a[3])==0)
    {
        cout<<"NO"; 
    }
    else 
    {
        cout<<"YES"; 
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}