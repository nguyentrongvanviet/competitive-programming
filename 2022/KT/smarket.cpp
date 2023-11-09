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
#define int long long 
int n , q  ; 
int s[N] ; 
int f[N][105] ; 
int a[N] ; 
int tknp(int val, int le )
{
    int l = le ; 
    int r  = n ; 
    int ans= l-1; 
    while(l<=r)
    {
        int mid =(l+r)/2; 
        if(s[mid]-s[l-1]<=val)
        {
            ans= mid ; 
            l = mid+1; 
        }
        else 
        {
            r=mid-1; 
        }
    }
    return ans ; 
}
void inp()
{
    cin>>n>>q ; 
    for(int i= 1 ;i<=n;i++)
    {
        cin>>a[i] ; 
        s[i] =s[i-1]+a[i] ; 
    }
    for(int i=n;i>=1;i--)
    {
        for(int j = 0;j<=100;j++)
        {
            if(a[i]>j)
            {
                f[i][j] = f[i+1][j];
            }
            else 
            {
                f[i][j] = 1+ f[i+1][j-a[i]] ; 
            }
        }
    }
    while(q--)
    {
        int x , l ;  
        cin>>x>>l ; 
        int r= tknp(x,l) ; 
        // cout<<x-(s[r]-s[l-1])<<" A "<<r<<endl;
        cout<<r-l+1+f[r+1][x-(s[r]-s[l-1])]<<"\n"; 
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