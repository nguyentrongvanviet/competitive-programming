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

int n ; 
char x[N] ; 
int a[N] ; 
vector<char>p{'u','e','o','a','i'}; 
int f[N][N] ; 
int g[N][N] ; 
int check(char c )
{
    for(char v:p)
    {
        if(v==c)return  1 ; 
    }
    return 0 ;  
}
void inp()
{
    cin>> n ; 
    for(int i=1 ;i<=n;i++)  
    {
        char x; 
        cin>>x;  
        a[i] =check(x) ; 
    }   
    int res = 0 ; 
    for(int l=2;l<=n;l++)
    {
        for(int i =1 ;i<=n-l+1;i++)
        {
            int j = i+l-1;  
            f[i][j] = max(f[i+1][j],f[i][j-1]);
            if(a[i]==a[j]&&a[i]==0)
            {
                f[i][j] = g[i+1][j-1]+2;  
            }   
            g[i][j] = max(g[i+1][j],g[i][j-1]) ; 
            if(a[i]==a[j]&&a[i]==1)
            {
                g[i][j]=max(g[i][j],2+f[i+1][j-1]);  
            }
        }
    }
    cout<<n-max(g[1][n],f[1][n]); 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}