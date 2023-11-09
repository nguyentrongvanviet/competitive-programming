#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =3e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n  ,q ;
int a[N][N];  
unordered_map<int,pii>pos ; 
int b[N][N] ; 
void inp()
{
    cin>> n >> q ; 
    for(int i= 1 ;i<=n;i++)
    {
        for(int j =1 ;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i= 1;i<=n;i++)
    {
        sort(a[i]+1,a[i]+n+1) ;
    }
    for(int i =1 ;i<=n;i++)
    {
        for(int j= 1;j<=n;j++)
        {
            b[i][j] = a[j][i] ; 
        }
    }
    for(int i= 1;i<=n;i++)
    {
        sort(b[i]+1,b[i]+n+1) ; 
    }
    for(int i= 1;i<=n;i++)
    {
        for(int j= 1;j<=n;j++)
        {
            pos[b[i][j]].X=j ; 
            pos[b[i][j]].Y=i ; 
        }
    }
    while(q--)
    {
        int val ; 
        cin>>val ; 
        cout<<pos[val].X<<" "<<pos[val].Y<<"\n";; 
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