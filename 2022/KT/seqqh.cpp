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
#define int long long 
int n ; 
int a[N] , s[N] ;
int tknp1(int l , int r )
{
    int le = l ; 
    int su = (s[r]-s[l-1])/2;
    int ans= -1 ;  
    while(l<=r)
    {
        int mid =(l+r)/2; 
        if(s[mid]-s[le-1]>=su)
        {
            ans =mid; 
            r=mid-1; 
        }
        else 
        {
            l=mid+1; 
        }
    }
    if(ans==-1)return 0;
    if(s[ans]-s[le-1]==su)return ans; 
    return -1 ; 
}

int tknp2(int l  , int r )
{
    int su = (s[r]-s[l-1])/2 ;
    int le = l ;  
    int ans= -1 ;  
    while(l<=r)
    {
        int mid =(l+r)/2; 
        if(s[mid]-s[le-1]<=su)
        {
            ans =mid ; 
            l=mid+1; 
        }
        else 
        {
            r=mid-1; 
        }
    }
    if(s[ans]-s[le-1]==su)
    {
        return ans ; 
    }
    return -1; 
}
int solve(int l , int r)
{
    if(l==r) return 0  ; 
    if(s[r]-s[l-1]==0)
    {
        return r-l; 
    }
    if((s[r]-s[l-1])%2==1)
    {
        return 0  ; 
    }
    int lll = tknp2(l,r) ; 
    // int rrr= tknp2(l,r); 
    int res= 0 ; 
    // cout<<l<<r<<endl;
    // cout<<lll<<" "<<rrr<<endl;
    if(lll!=-1)
    {
        res=max(res,1+solve(l,lll ));
    }
    // if(lll!=-1)res=max(res,max(1+solve(lll+1,r),1+solve(l,lll))) ;
    return res  ; 
}
void inp()
{
    cin>> n ;
    for(int i= 1;i<=n;i++)cin>>a[i],s[i]=s[i-1]+a[i];  
    cout<<solve(1,n)<<"\n";   
}
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int test ;
    cin>>test ;
    while(test--)inp() ; 
    return 0;
}