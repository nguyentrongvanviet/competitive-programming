#include<bits/stdc++.h>
using namespace std;

#define TASK "SEGMENT"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =55+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n ; 
int a[N][5] ; 
int g[N][N] ;
int f[N] ;
bool check(int i , int k , int j )
{
    int ans =0  ;
    for(int x=1;x<=3;x++)
    {
        for(int y= 1;y<=3;y++)
        {
            if(a[i][x]==a[j][y])
            {
                ans++ ; 
            }
        }
    }
    return ans>=2; 
}
void doc()
{
 	cin>>n ; 
 	for(int i=1;i<=n;i++)
 	{
 		for(int j= 1;j<=3;j++)
 		{
            char c ; cin>>c ; 
 			a[i][j] =c-'A' ;
 		}
 	}   
    int res=0 ; 
    for(int i =1 ;i<=n;i++)g[i][i+1]=1;
    for(int l=3;l<=n;l++)
    {
        for(int i= 1;i<=n-l+1;i++)
        {
            int j=  i+l-1; 
            for(int k =i+1;k<=j-1;k++)
            {
                if(g[i][k]==1&&g[k][j]==1&&check(i,k,j))
                {
                    g[i][j] =1 ; 
                    break; 
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j = 1;j<=i-1;j++)
        {
            for(int k =i+1;k<=j-1;k++)
            {
                if(g[j][k]&&g[k][i])
                {
                    if(g[i][k]&&g[k][j])
                    {
                        f[i] =max(f[i],f[j])
                    }
                }
            }
        }
    }
    cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
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