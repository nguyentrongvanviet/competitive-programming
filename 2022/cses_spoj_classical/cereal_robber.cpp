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

ll n , m ; 
void inp()
{
    cin>> n >> m ;
    if(n==1&&m==1)
    {
        cout<< 0 ;  
        return ;  
    } 
    if(n==1)
    {
        cout<<m-1 ; 
        return ;  
    }
    if(m==1)
    {
        cout<<n-1; 
        return ; 
    }
    cout<<n*(m-1);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}