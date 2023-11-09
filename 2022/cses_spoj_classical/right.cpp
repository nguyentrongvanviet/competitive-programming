#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =1e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n  ; 
ll  d ; 
ll a[N] ; 
ll x[N] ; 
ll f[N] ; 
int np(ll val)
{
    int l = 1; 
    int r = n ; 
    int ans  ; 
    while(l<=r)
    {
        int mid =(l+r)>>1; 
        if(x[mid]>=val)
        {
            ans =mid ; 
            r=mid-1; 
        }
        else 
        {
            l=mid+1; 
        }
    }
    return ans ; 
}
void inp()
{
    cin>> n >> d ; 
    for(int i =1 ;i<=n;i++)
    {
        cin>>a[i] ; 
        x[i] =oo ; 
    }
    for(int i=1 ;i<=n;i++)
    {
        int pos =np(a[i]) ; 
        x[pos]=a[i];
        f[i] =pos;  
    }   
    for(int i=1 ;i<=n;i++)
    {
        cout<<a[i]+f[i]*d<<"\n"; 
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