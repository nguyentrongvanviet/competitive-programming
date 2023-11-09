#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =4e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int q  , n ; 
string  a;  
int f[N][N] ; 
int res[N] ; 
int dd[N][N] ; 
int solve(int l , int r )
{
    int u  = l ; 
    int v = r ;
    if(r+(r-l)-1>n)return -oo;  
    int ans= 0 ;   
    while(u<r&&ans<=10)
    {
        int d =f[u][v] ; 
        if(d==0)
        {
            u++; 
            v++;
            ans++; 
        }
        else
        {
            u =u+d;
            v =v+d;
        }
    }
    return ans ; 
}
void init()
{
    for(int i =  n; i>=1;i--)
    {
        for(int j =n ;j>=1;j--)
        {
            if(a[i]==a[j])
            {
                f[i][j] = f[i+1][j+1]+1; 
            }
            else
            {
                f[i][j]=0; 
            }
        }
    }
    // cout<<solve(7,9)<<endl;
    for(int i= 1 ;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int u = solve(i,j)  ; 
            if(u>=0)
            {
                res[u] = max(res[u],j-i); 
            }
        }
    }
    for(int i =1;i<=n;i++)
    {
        res[i] = max(res[i],res[i-1]);
    }
}  
void inp()
{
    cin>> q ; 
    cin>>a ; 
    n = a.size() ;
    a='#'+a;  
    init() ; 
    while(q--)
    {
        int u ; 
        cin>>  u; 
        cout<<res[u]<<"\n";
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