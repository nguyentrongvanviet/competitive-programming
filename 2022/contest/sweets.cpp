#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define int long long 
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =1e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
int a[N] , s[N] ; 
bool  f[(int)1e2+5][N][N];
int fa[1<<22] ; 
int fb[1<<22] ,fc[1<<22] ; 
int res =oo ; 
void inp()
{
    cin>> n ;
    for(int i= 1 ;i<=n;i++)
    {
        cin>>a[i] ; 
        s[i]=s[i-1]+a[i] ; 
    }
}
void sub1()
{
    int tt=  (1<<n) ; 
    for(int i =0  ;i<tt;i++)
    {
        ll temp = 0 ; 
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))temp+=a[j+1]; 
        }
        for(int j =  0;j<n;j++)
        {
            if(i&(1<<j))
            {
                int ntt=(i^(1<<j));
                if(fa[ntt]+a[j+1]<=s[n]/3)
                {
                    fa[i] = max(fa[i],a[j+1]+fa[ntt]); 
                }
                else
                {
                    fa[i] =max(fa[i],fa[ntt]);
                }
            }
        }
        fb[i] = temp-fa[i]; 
        fc[i] = s[n]-temp ;
        res=min(res,max(max(fa[i],fb[i]),fc[i])-min(min(fa[i],fb[i]),fc[i]));
    }
    cout<<res;
}
void sub2()
{   
    f[0][0][0]=true;
    for(int k = 1 ;k<=n;k++)
    {
        for(int i = 0 ;i<=s[n];i++)
        {
            for(int j=  0 ;j<=s[n];j++)
            {
                if(i>=a[k]&&f[k-1][i-a[k]][j])
                {
                    f[k][i][j]=true; 
                }
                else if(j>=a[k]&&f[k-1][i][j-a[k]])
                {
                    f[k][i][j]=true; 
                }
                else if(f[k-1][i][j])
                {
                    f[k][i][j]=true; 
                }
                else
                {
                    f[k][i][j]=false; 
                }
            }
        }
        if(k==n)
        {
            for(int i = 0  ;i<=s[n];i++)
            {
                for(int j=  0 ;j<=s[n];j++)
                {
                    if(f[n][i][j])
                    {
                        res=min(res,max(max(i,j),s[n]-i-j)-min(min(i,j),s[n]-i-j));
                    }
                }
            }
        }
    }
    cout<<res; 
}
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    if(n<=20)sub1();
    else sub2();
    return 0;
}