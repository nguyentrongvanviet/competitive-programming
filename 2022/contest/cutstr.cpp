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

int n , k ;
int f[N][N] ;
string s1,s2;
int a[N] , b[N] ;
int res= 0  ;
int check(int x, int y , int z , int a, int b ,int c )
{
    int t = 0;
    vector<int>g{a,b,c}; 
    for(int v:g)
    {
        if(v==0)
        {
            t+=x;
            if(f[t][x]<x)return 0 ;
        }
        else if(v==1)
        {
            t+=y;
            if(f[t][x+y]<y)return 0 ;
        }
        else if(v==2)
        {
           t+=z;
           if(f[t][x+y+z]<z)return 0;
        }
    }
    return 1;
}
void inp()
{
    cin>>k ;
    cin>>s1;
    cin>>s2;
    n=s1.size() ;
    for(int i= 1 ;i<=n;i++)
    {
        a[i] =s1[i-1]-'a' ;
    }
    for(int j= 1 ;j<=n;j++)
    {
        b[j] = s2[j-1]-'a' ;
    }
    for(int i =1 ;i<=n;i++)
    {
        for(int j= 1 ;j<=n;j++)
        {
            if(abs(a[i]-b[j])<=k)
            {
                f[i][j]=f[i-1][j-1]+1;
            }
            else
            {
                f[i][j]= 0 ;
            }
        }
    }
    for(int i =1;i<=n-2;i++)
    {
        for(int j =i+1;j<=n-1;j++)
        {
            int x= i ;
            int y = j-i ;
            int z=  n-x-y ;
            int u , v,  c;    
           
            u =x , v= y , c= z ; 
            if(f[x][u]>=x&&f[x+y][u+v]>=y&&f[x+y+z][u+v+c]>=z)
            {
                res++ ; 
                continue ; 
            }
            
            u =x , v= z , c= y ; 
            if(f[x][u]>=x&&f[x+y][u+v+c]>=y&&f[x+y+z][u+v]>=z)
            {
                res++ ; 
                continue ; 
            }
            u =y , v= x , c= z ; 
            if(f[x][u+v]>=x&&f[x+y][u]>=y&&f[x+y+z][u+v+c]>=z)
            {
                res++ ; 
                continue ; 
            }
            u =y , v= z , c= x ; 
            if(f[x][u+v+c]>=x&&f[x+y][u]>=y&&f[x+y+z][u+v]>=z)
            {
                res++ ; 
                continue ; 
            }
            u =z, v= x , c= y ; 
            if(f[x][u+v]>=x&&f[x+y][c+u+v]>=y&&f[x+y+z][u]>=z)
            {
                res++ ; 
                continue ; 
            }
            u =z , v= y , c= x ; 
            if(f[x][u+v+c]>=x&&f[x+y][u+v]>=y&&f[x+y+z][u]>=z)
            {
                res++ ; 
                continue ; 
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
    return 0;
}
