#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =400+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
int a[N][N] ; 
int f[5][5] ; 
ll res= 0 ; 
void inp()
{
    cin>> n ; 
    for(int i= 1;i<=n;i++)
    {
        int x , y , c ;
        cin>>x>>y>>c;  
        x+=201; 
        y+=201;  
        a[x][y]=c; 
    }   
    for(int i= 1 ;i<=401;i++)
    {
        for(int j =i+1;j<=401;j++)
        {
            for(int t= 1;t<=4;t++)
            {
                for(int u=t+1;u<=4;u++)
                {
                    f[t][u] = 0 ; 
                }
            }
            for(int t = 1;t<=401;t++)
            {
                if(a[t][i]==a[t][j]||a[t][i]==0||a[t][j]==0)continue ; 
                int u =  a[t][i] ; 
                int v =a[t][j] ; 
                if(u>v)swap(u,v); 
                int x= 0 ; 
                int y= 0 ; 
                for(int q= 1;q<=4;q++)
                {
                    if(q==u||q==v)continue;
                    if(x==0)x=q; 
                    else y=q; 
                }
                res+=f[x][y] ; 
                f[u][v]++;
            }
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