#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vi vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =1e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n , m , k ; 
vector<int>r[N];
int bit[N] ; 
void up(int idx,int val )
{
    for(int i=idx;i<=n+1;i+=i&-i)
    {
        bit[i]+=val; 
    }
}
int get(int idx )
{
    int ans =0 ; 
    for(int i=idx;i;i-=i&-i)
    {
        ans+=bit[i];
    }
    return ans ; 
}
int res[N] ; 
vector<pii>q[N]; 
vi query[N];
void input()
{
    cin>>n>> m>>k ;
    for(int i=1 ;i<=m;i++)
    {
        int a , b ; 
        cin>>a>>b ; 
        r[b].pb(a) ; 
    }       
    for(int i= 1;i<=k;i++)
    {
        int sl ; cin>>sl ;
        int la = 1 ;
        query[i].pb(0);
        for(int j= 1  ;j<=sl;j++)
        {
            int u ; 
            cin>> u ; 
            query[i].pb(u) ;
            q[u].pb({i,j});
        }
        query[i].pb(n+1);
        q[n+1].pb({i,sl+1});
    }
    for(int i=1 ;i<=n+1;i++)
    {
        for(int j = 0 ;j<q[i].size();j++)
        {
            int id = q[i][j].fi; 
            int pos =q[i][j].se; 
            int pre=query[id][pos-1];
            res[id]+=get(i)-get(pre);
        }
        for(int j = 0;j<r[i].size();j++)
        {
            up(r[i][j],1);
        }
    }
    for(int i=1 ;i<=k;i++)
    {
        cout<<res[i]<<"\n";
    }
}
void output()
{
    
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    // freopen("i.txt","r",stdin); 
    // freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}