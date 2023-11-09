#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define int long long 
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =1e6+5,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

struct pt
{
    int x , y;  
    bool operator<( pt b )
    {
        return x<b.x; 
    }
};
int n , k  ; 
int res=0 ; 
pt a[N] ; 
int s[N] ; 

int tknp(int val,int pos)
{
    int l = 1 ; 
    int r =pos ; 
    int ans ; 
    while(l<=r)
    {
        int mid =(l+r)>>1; 
        if(a[mid].x >= val)
        {
            ans= mid;
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
    cin>>n>>k ;
    for(int i =1 ;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;  
    } 
    sort(a+1,a+n+1) ; 
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i].y;  
    }
    for(int i= 1 ;i<=n;i++)
    {
        int pos = tknp(a[i].x-2*k,i);  
        // int pos =1 ;
        res=max(res,s[i]-s[pos-1]);
    }
    cout<<res; 
}
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}