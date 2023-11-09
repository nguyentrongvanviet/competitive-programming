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

bool cmp(pii a , pii b  )
{
    return a.X<b.X||(a.X==b.X&&a.Y>b.Y) ; 
}
int n , d ;
int a[N] ; 
int pos[N] ; 
vector<pii> p ;  
int b[N] ; 
int f[N]  ; 
int tknp(int val)
{
    int ans = 1 ; 
    int l = 1 ;
    int r = 2*n ; 
    while(l<=r)
    {
        int mid=(l+r)/2 ;
        if(b[mid]>=val)
        {
            ans =mid ;  
            r= mid-1 ; 
        }
        else 
        {
            l=mid+1 ; 
        }
    }
    return ans; 
}

int lis(int id)
{       
    for(int i =1;i<=2*n;i++)
    {
        b[i] = oo; 
    }    
    int ans = 0 ; 
    for(int i = 0 ;i<p.size();i++)
    {
        int l  = p[i].X; 
        int r  = p[i].Y ; 
        if(l<=id&&id<r)
        {
            int pos = tknp(p[i].Y) ; 
            b[pos]= p[i].Y ; 
            ans=max(ans,pos); 
        }
    }
    return ans; 
}   
void inp()
{
    cin>> n >> d ; 
    for(int i= 1; i<=2*n;i++)
    {
        cin>>a[i] ; 
    }   
    for(int i=2*n;i>=1;i--)
    {   for(int t = max(0,a[i]-d);t<=min(2*n,a[i]+d);t++)
        {
            if(pos[t]!=0)
            {
                p.pb({i,pos[t]});     
            }
        }
        pos[a[i]]= i ;
    }
    sort(p.begin(),p.end(),cmp) ;
    int ans =0 ; 
    for(int i= 1;i<=2*n;i++)
    {
        ans=max(ans,lis(i)); 
    }
    cout<<ans;  
}
// |x-y| <=d  x-d<=y&&y<=x+d  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}