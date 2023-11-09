#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =5e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n , m ; 
int res= -oo ; 
int a[N] , b[N] ; 
int f[N][N] ;  
unordered_map<int,int>ma1; 
unordered_map<int,int>ma2;  
void inp()
{
    cin>>n>>m ; 
    for(int i =1 ;i<=n;i++)cin>>a[i] ;
    for(int j =1 ;j<=m;j++)cin>>b[j] ;
    for(int i= 1;i<=n;i++)
    {
        for(int j = i -1;j>=1;j--)
        {
            if(a[i]==a[j]) 
            {
                ma1[i] =  j ; 
                break ; 
            }
        }
    }
    for(int i =1 ;i<=m;i++)
    {
        for(int j = i-1;j>=1;j--)
        {
            if(b[i]==b[j])
            {
                ma2[i] =j ;
                break ;
            }
        }
    }
    for(int i=1 ;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            int u =  ma1[i];
            int v= ma2[j] ;
            int ii=i-f[i-1][j-1] ; 
            int jj= j-f[i-1][j-1];
            if(u<ii&&v<jj)
            {
                f[i][j] =f[i-1][j-1]+1; 
            } 
            else if(ii<=u&&jj<=v)
            {   
                int d1 = i - u ; 
                int d2=  j - v ; 
                if(d1==d2)
                {
                    f[i][j] = f[i-1][j-1]+1; 
                }
                else
                {
                    f[i][j] = min(d1,d2)+1; 
                }
            }
            else
            {
                int d1 = i - u ; 
                int d2=  j - v ; 
                f[i][j]  = min(d1,d2);
            }
            //cout if(f[i][j]>res)<<i<<" "<<j<<" "<<endl;
            res=max(res,f[i][j]); 
            // if(f[i][j]==4) cout<<i<<" "<<j<<endl;
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