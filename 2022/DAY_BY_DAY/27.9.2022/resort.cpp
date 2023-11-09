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
#define int long long 
int n  , m , p , q ; 
int a[N][N]; 
int x[N][N] ; 
int be[N][N]  ,lon[N][N] ; 
int B ; 
void inp()
{
    cin>>n>>m ;
    cin>>p>>q;
    cin>>B ;   
    for(int i= 1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            x[i][j] =x[i][j-1]+x[i-1][j]-x[i-1][j-1]+(a[i][j]==B) ; 
            be[i][j] =be[i-1][j]+be[i][j-1]-be[i-1][j-1]+(a[i][j]<B);
            lon[i][j]= lon[i-1][j]+lon[i][j-1]-lon[i-1][j-1]+(a[i][j]>B); 
        }
    }
    int cnt= 0 ; 
    for(int i =p ;i<=n;i++)
    {
        for(int j =q;j<=m;j++)
        {
            if(be[i][j]-be[i][j-q]-be[i-p][j]+be[i-p][j-q]<(p*q+1)/2&&(p*q+1)/2<(p*q+1-(lon[i][j]-lon[i][j-q]-lon[i-p][j]+lon[i-p][j-q])))cnt++; 
        }
    }
    cout<<cnt ; 
}

signed  main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}