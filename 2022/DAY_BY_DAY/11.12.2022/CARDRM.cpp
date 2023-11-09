#include<bits/stdc++.h>
using namespace std;

#define TASK "CARDRM"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#pragma CPP target("popcnt")
const int N =55+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n ; 
int a[N][4] ; 
int f[N] ,  g[N][N] ; 
bool check(int x, int y )
{
    int ans= 0 ;
    FOR(i,1,3)
    {
        FOR(j,1,3)
        {
            if(a[x][i]==a[y][j])ans++ ; 
        }
    }
    return ans>=2; 
}
void tinh(int  i ,int j )
{
    if(g[i][j]!=-1)return ;
    g[i][j]=0;
    for(int k = i+1;k<=j-1;k++)
    {
        tinh(i,k) ; 
        tinh(k,j) ; 
        if(g[i][k]&&g[k][j]&&check(i,j))
        {
            g[i][j]=1 ; 
        }
    }
}
void doc()
{
 	cin>> n;  
    memset(g,-1,sizeof(g)) ; 
 	FOR(i,1,n)
 	{
        g[i][i+1] = 1; 
 		FOR(j,1,3)
        {
            cin>>a[i][j]; 
        }
 	}   
    int res=0; 
    FOR(i,1,n)
    {
        FOR(j,1,i-1)
        {
            tinh(j,i);
            if(g[j][i])
            {
                    f[i] = max(f[i],f[j]+i-j+1-2);
                res=max(res,f[i]);
            }
        }
    }
    cout<<res;
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}