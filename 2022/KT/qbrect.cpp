#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n , m ; 
int l[N] , r[N] ; 
int h[N][N] ; 
int a[N][N] ;  
int res= -oo; 
int st[N] ; 
void inp()
{
    cin>>n>>m ; 
    for(int i= 1 ;i<=n;i++)
    {
        for(int j= 1;j<=m ;j++)
        {
            cin>>a[i][j];  
        }
    }
    for(int i= 1; i<=n;i++)
    {
        for(int j =1 ;j<=m;j++)
        {
            if(a[i][j]==1 )
            {
                h[i][j] =h[i-1][j]+1; 
            }
            else
            {
                h[i][j]=0 ;  
            }
        }
        
    }
    for(int i= 1;i<=n;i++)
    {
        l[1]=1; 
        int sz=0;  
        for(int j= 2 ;j<=m;j++)
        {
            if(h[i][j]>h[i][j-1])
            {
                l[j]=j ; 
                st[++sz]=j-1; 
            }
            else
            {
                while(sz>0&&h[i][st[sz]]>=h[i][j])
                {
                    sz--;
                } 
                if(sz==0)
                {
                    l[j] =1;  
                }
                else
                {
                    l[j] = st[sz]+1;
                }
            }
        }
        r[m]=1 ;
        sz= 0  ; 
        for(int  j= m-1;j>=1;j--)
        {
            if(h[i][j]>h[i][j+1])
            {
                r[j] = j; 
                st[++sz]=j+1;
            }
            else
            {
                while(sz>0&&h[i][st[sz]]>=h[i][j])
                {
                    sz-- ; 
                }
                if(sz==0)
                {
                    r[j]= m ;
                }else
                {
                    r[j]=  st[sz]-1;
                } 
            }
        }
        for(int j= 1 ;j<=m;j++)
        {
            res=max(res,h[i][j]*(r[j]-l[j]+1));
        }
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