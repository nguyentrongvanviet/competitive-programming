#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =4000+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const ll L = 100  ; 
int f[N][L] ; 
int n ; 
void cong(int a , int b )
{   
    for(int i= 1;i<=n;i++)
    {
        
    }
}
string f[N] ; 
void inp()
{
    cin>> n ; 
    if(n<3)
    {
        cout<<0 ;  
        return ; 
    }
    pre[0] ="1";
    for(int i= 1;i<=n-1;i++)
    {
        for(int j=n-j;j>=i;j--)
        {
            f[j]=(f[j]+f[j-i]);
        }
    }
    cout<<f[n];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}