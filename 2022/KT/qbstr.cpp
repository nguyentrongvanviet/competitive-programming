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

int f[N][N] ; 
void inp()
{   
    string s1 ,s2 ;
    cin>>s1>>s2; 
    int n = s1.size() ; 
    int  m = s2.size() ;  
    s1="a"+s1; 
    s2="b"+s2;
    for(int i= 1 ;i<=n;i++)
    {
        for(int j = 1 ;j<=m;j++)
        {
            if(s1[i]==s2[j])
            {
                f[i][j] =f[i-1][j-1]+1; 
            }
            else 
            {
                f[i][j] = max(f[i-1][j],f[i][j-1]); 
            }
        }
    }
    cout<<f[n][m] ; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}