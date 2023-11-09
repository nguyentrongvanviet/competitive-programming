#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define int ll 
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ,  m; 
int a[N] ,s[N] ; 
int tknp(int val )
{
    ll l = 1 ;
    ll r = n ; 
    ll  ans; 
    while(l<=r)
    {
        ll mid =(l+r)/2; 
        if(s[mid]>=val)
        {
            ans= mid ; 
            r=mid-1 ;
        }
        else
        {
            l=mid+1; 
        }
    }
    return ans; 
}
void inp()
{
    cin>>n ; 
    for(int i= 1; i<=n;i++)
    {
        cin>>a[i] ; 
        s[i] =s[i-1]+a[i] ; 
    }   
    cin>>m ; 
    for(int i= 1;i<=m;i++)
    {
        int val ; 
        cin>>val  ;
        cout<<tknp(val)<<" ";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}