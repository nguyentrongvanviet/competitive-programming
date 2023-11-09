#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int  n  ; 
ll  s , a[N]; 
ll l[1005][10005] ; 
ll r[1005][10005] ;  
ll f[N];
void inp()
{   
    cin>> n >> s;
    for(int i= 1;i<=n;i++)
    {
        cin>>a[i] ; 
    } 
    l[0][0]=1; 
    for(int i= 1;i<=n;i++)
    {   
        for(int j =0;j<=s;j++)
        {   
            l[i][j] =l[i-1][j] ; 
            if(j-a[i]>=0)
            {
                l[i][j] =(l[i-1][j-a[i]]+l[i][j])%sm; 
            }
        }
    }    
    r[n+1][0]=1 ;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=s;j++)
        {
            
            r[i][j] =r[i+1][j]; 
            if(j-a[i]>=0)
            {
                r[i][j]=(r[i+1][j-a[i]]+r[i][j])%sm;
            }
        }
    }
    for(int i =1;i<=n;i++) 
    {
        for(int t= 0 ;t<=s-a[i];t++)
        {
            f[i]=(f[i]+l[i-1][t]*r[i+1][s-a[i]-t])%sm; 
        }
    }
    for(int i= 1;i<=n;i++)
    {
        cout<<f[i]<<" ";  
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