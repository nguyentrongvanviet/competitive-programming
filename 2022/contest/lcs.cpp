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

int n ; 
string a , b ; 
int f[N][N] ; 

void inp()
{
    cin>>a ; 
    cin>>b; 
    int n = a.size() ; 
    int m =b.size();
    a='#'+a; 
    b='#'+b; 
    for(int i=1;i<=n;i++)
    {
        for(int j= 1 ;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                f[i][j]= f[i-1][j-1]+1; 
            }
            else
            {
                f[i][j] = max(f[i-1][j],f[i][j-1]); 
            }
        }
    }   
    cout<<f[n][m];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("in.txt","r",stdin); 
    freopen("out.txt","w",stdout); 
    inp();
    return 0;
}