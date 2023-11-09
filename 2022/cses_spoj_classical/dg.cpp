#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
ll a[N] ,b[N] ; 

ll res= 0 ; 
bool cmp(ll a , ll b)
{
    return a>b; 
}
void inp()
{
    cin>> n; 
    for(int i=1;i<=2*n;i++)
    {
        cin>>a[i]>>b[i] ; 
        res+=b[i];  
        a[i]  =a[i]-b[i] ; 
    }    
    sort(a+1,a+2*n+1,cmp) ; 
    for(int i= 1;i<=n;i++)
    {
        res+=a[i] ; 
    }
    cout<<res; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}
