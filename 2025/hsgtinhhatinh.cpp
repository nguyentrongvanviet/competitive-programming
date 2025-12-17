#include<stdio.h> 
#include<vector>
#include<fstream>
#include<time.h>
#include<iostream>
using namespace std; 

const int oo =  1e9+6 ;
const int N = 405 ;  
int f[2][N][N] ; 
int opt[2][N][N] ; 
struct DL
{
    int l , r , cost ;
} ; 
const int SL = 1e5+5 ; 
vector<DL>q[N] ; 
int pos[SL] ;
void sub1()
{
    int S ,F  ,cost  , doxang ; cin >>S >>F>>cost>>doxang ;  
    int l = 0 ; 
    for(int i=  S+1;i<=F;i++)
    {
        l = max(l,pos[i]-pos[i-1]) ; 
    }
    int r =  1e9 ; 
    int ans = 0 ; 
    while(l<=r)
    {
        int mid = (l+r)/2  ; 
        int used = 0 ; 
        int cur = mid ; 
        for(int i= S+1;i<=F;i++)
        {
            int need = pos[i]-pos[i-1] ; 
            cur-=need ; 
            if(cur<0)used++ , cur = mid-need ;  
            if(used>doxang)break; 
        }
        if(used<=doxang)
        {
            ans = mid ; 
            r = mid -1 ; 
        }
        else l = mid +1 ;
    }
    cout<<1ll*cost*ans<<endl; 
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    int n , m ; 
    cin>> n >> m ; 
    for(int i=1;i<=n;i++)
    {
        cin>>pos[i] ; 
    }
    if(n>400)
    {
        sub1() ;
        return 0 ; 
    }
    for(int i=1;i<=m;i++)
    {
        int l , r , cost , k; 
        cin >> l >> r >> cost >> k ;
        q[k+1].push_back({l,r,cost}) ;
    }
    for(int l=1;l<=n;l++)for(int r=1;r<=n;r++)f[0][l][r] = (l==r?0:oo),opt[0][l][r] = r ; 
    long long  res = 0 ;  
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)f[k&1][i][i] = 0, opt[k&1][i][i] = i ; 
        for(int r=n;r>=1;r--)
        {
            int opt = r; 
            for(int l=r-1;l>=1;l--)
            {
                // f[k&1][l][r] = oo ; 
                while(opt>l&&pos[opt]-pos[l]>=f[(k-1)&1][opt][r])
                {
                    --opt;
                }
                f[k&1][l][r] = min(f[(k-1)&1][opt][r],pos[opt+1]-pos[l]) ;

                // for(int nopt=opt[k&1][l][r-1];nopt<=opt[k&1][l+1][r];nopt++)
                // {
                //     if(f[k&1][l][r]>max(pos[nopt]-pos[l],f[(k-1)&1][nopt][r]))
                //     {
                //         f[k&1][l][r] = max(pos[nopt]-pos[l],f[(k-1)&1][nopt][r]) ;
                //         opt[k&1][l][r] = nopt ; 
                //     }
                // }
            }
        }
        for(int i=0;i<q[k].size();i++)
        {
            int l = q[k][i].l ; 
            int r = q[k][i].r ; 
            int cost = q[k][i].cost ; 
            res = max(res,1ll*f[k&1][l][r]*cost) ; 
        }
    }
    cout<<res<<endl;  
    // cerr<<"Time elapsed: " << 1.0 * clock()<< " s.\n";
    return 0 ; 
}