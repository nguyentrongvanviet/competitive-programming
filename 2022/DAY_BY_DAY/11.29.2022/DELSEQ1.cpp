#include<bits/stdc++.h>
using namespace std;

#define TASK "DELSEQ1"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =2e2+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ; 
int a[10000] ;
ll val[10000] ; 
bool dd[N][N][N] ;
ll f[N][N][N];
void doc()
{
    cin>>n;
    FOR(i,1,n)
    {
    	char x ; cin>>x ; 
    	a[i]  = {x=='1'}; 
    }
    FOR(i,1,n)cin>>val[i]; 

}
// f[l][r][k] chi phi lon nhat khi xoa va con lai k thang giong voi a[r] 
ll tinh(int l ,int r ,int k )
{
    if(dd[l][r][k])return f[l][r][k] ; 
    dd[l][r][k] =1 ;
    if(l>r)
    {
        if(k==0)return f[l][r][k]  = 0 ; 
        return f[l][r][k]= -inf ;
    }
    if(l==r)
    {
        if(k==1)return f[l][r][k]=0;
        else if(k==0)return f[l][r][k]=val[1] ; 
        return f[l][r][k]=-inf ;
    }
    if(k==0)
    {
        FOR(i,1,(r-l+1))
        {
            f[l][r][0] = max(f[l][r][0],tinh(l,r,i)+val[i]);
        }
        return f[l][r][0] ; 
    }
    else if(k==1)
    {
        return f[l][r][k] = tinh(l,r-1,0);
    }
    FOR(i,l,r-1)
    {
        if(a[i]==a[r])
        {
            f[l][r][k]= max(f[l][r][k],tinh(l,i,k-1)+tinh(i+1,r-1,0)); 
        }
    }
    return f[l][r][k] ; 
}
void xuly()
{
    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            FOR(k,0,n)
            {
                f[i][j][k] = -inf ; 
            }
        }
    }
    // cout<<tinh(1,1,0)<<endl;
    cout<<tinh(1,n,0);
}
ll d[N] ; 
int main()
{
    IOS();  
    doc(); 
    if(n<=100)xuly();
    else 
    {
        FOR(i,1,n)
        {
            FOR(j,1,i)
            {
                d[i] = max(d[i] , d[i-j]+val[j]) ; 
            }
        }
        cout<<d[n];
    }
    return 0 ;
}