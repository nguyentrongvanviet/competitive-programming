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

int n ; 
ll R(ll l ,  ll r )
{
    return l+rand()%(r-l+1) ;
}
void inp()
{
    ll n , k ; 
    cin>> n;
    for(int i =1 ;i<=500;i++)
    {
        cout<<R(1,n)<<" "<<R(1,n)<<"\n";
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