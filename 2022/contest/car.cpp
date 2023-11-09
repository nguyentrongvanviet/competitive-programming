#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ,cs=330 ;
const ll mod = 1e9+7 ,inf = 1e17;
struct car
{
    int t ,dt ;
    bool operator<(car x )
    {
        return dt<x.dt; 
    }
};
int n , k , s , t ; 
car a[N] ; 
int petro[N]  ,dis[N] ; 
void inp()
{
    cin>>n>>k>>s>>t ; 
    for(int i =1;i<=n;i++)
    {
        cin>>a[i].t>>a[i].dt; 
    }
    for(int i =1 ;i<=k;i++)
    {
        int pos ; 
        cin>>pos;
        petro[i] = pos ; 
    }
    sort(a+1,a+n+1) ; 
    sort(petro+1,petro+k+1) ; 
    petro[0] =0 ; 
    petro[k+1]=s; 
    for(int i = 1 ;i<=k+1;i++)
    {
        dis[i] = petro[i] -petro[i-1] ;  
    }
}
int np(int val  , int dis)
{
    int l = 0 ; 
    int r = dis;  
    int ans=0;  
    while(l<=r)
    {
        int mid=(l+r)/2 ; 
        int cl = val-2*mid;
        if(cl+mid>=dis)
        {
            l=mid+1;
            ans = mid ; 
        }        
        else
        {
            r=mid-1;  
        }
    }
    return ans ; 
}
int check(int val )
{
    int ti= 0 ; 
    for(int i = 1;i<=k+1;i++)
    {
        if(val<dis[i])
        {
            return 0 ; 
        }
        int ma=np(val,dis[i]);
        ti+=ma+(dis[i]-ma)*2;
    }
    return (ti<=t);  
}
void tknp()
{
    int l = 1 ; 
    int r = n ;
    int ans =-1;  
    while(l<=r)
    {
        int mid = (l+r)/2 ; 
        if(check(a[mid].dt))
        {
            r=mid-1; 
            ans= mid ; 
        }
        else
        {
            l=mid+1; 
        }
    }
    if(ans==-1)
    {
        cout<<ans ; 
        return ; 
    }
    int res=oo;
    for(int i = ans;i<=n;i++)
    {   
        if(a[i].t<res)
        {
            res=a[i].t ; 
        }
    }
    cout<<res ; 
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    tknp();
    return 0;
}