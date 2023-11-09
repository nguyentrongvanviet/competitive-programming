#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define int long long 
#define pii pair<int,int>
#define X first 
#define Y second
const int N =1000+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
struct pt 
{
    ll x, y;  
};  
int n ;
map<pii,int>dd1;
map<pii,int>dd;
pt a[N] ; 
pt p[N] ;    
int sl = 0 ; 
ll dis(pt a, pt b )
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y); 
}
vector<pii>mid[5000000];
void inp()
{
    cin>> n ; 
    for(int i =1;i<=n;i++)
    {
        cin>>p[i].x>>p[i].y;
        if(dd1[{p[i].x,p[i].y}])continue ; 
        dd1[{p[i].x,p[i].y}]=1; 
        a[++sl] =p[i] ; 
    }  
    int u = 0; 
    for(int i= 1 ;i<=sl-1;i++)
    {
        for(int j= i+1;j<=sl;j++)
        {
            pt x = {a[i].x+a[j].x,a[i].y+a[j].y}; 
            if(dd[{x.x,x.y}]==0)
            {
                dd[{x.x,x.y}]=++u; 
            }
            mid[dd[{x.x,x.y}]].pb({i,j});
        }
    }
    double res= 0 ; 
    for(int i= 1;i<=u;i++)
    {
        for(int j= 0 ;j<mid[i].size();j++)
        {
            for(int t=j+1;t<mid[i].size();t++)
            {
                int x =  mid[i][j].X; 
                int y = mid[i][j].Y ; 
                int v = mid[i][t].X; 
                if(dis(a[x],a[y])-dis(a[x],a[v])-dis(a[v],a[y])==0)
                {
                    res=max(res,sqrt(dis(a[x],a[v]))*sqrt(dis(a[v],a[y]))); 
                }
            }
        }
    }
    if(res==0)
    {
        cout<<0  ; 
        return ; 
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