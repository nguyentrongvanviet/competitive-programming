#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

struct bg 
{
    int x , y ; 
};
int n ,c;  
bg a[N]; 
int b[5]; 
int f[N] ;
int solve(int b[])
{   
    int pos[5];
    for(int i= 1 ;i<=c;i++)
    {
        pos[b[i]] = i; 
    }
    int x[N];
    for(int  i= 1;i<=n*c;i++)
    {
        x[i] = pos[a[i].x]*1000+a[i].y;
    }
    int res=  0 ; 
    for(int i =1 ;i<=n*c;i++)
    {
        f[i] =1 ; 
        for(int j = 1;j<=i-1;j++)
        {
            if(x[i]>x[j])
            {
            f[i] = max(f[i],f[j]+1);
            }
        }
        res=max(res,f[i]);
    }
    return n*c-res; 
}
void inp()
{
    cin>>c;  
    cin>>n;
    for(int i=1;i<=n*c;i++)
    {
        cin>>a[i].x>>a[i].y;  
    }
    for(int i = 1;i<=c;i++)
    {
        b[i] = i ; 
    }
    int res= oo ; 
    do
    {
        res=min(res,solve(b)) ; 
    } while (next_permutation(b+1,b+c+1));
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