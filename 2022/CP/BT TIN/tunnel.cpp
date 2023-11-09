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
struct pt
{
    int id;  
    int x, y , z;  
};
struct edge
{
    int u ,  v , w; 
    bool operator<(edge x)
    {
        return w<x.w; 
    }
};
bool cmp1(pt a , pt b )
{
    return a.x<b.x;  
}
bool cmp2(pt a , pt b )
{
    return a.y<b.y;
}
bool cmp3(pt a , pt b )
{
    return a.z<b.z;
}
int pa[N] ; 
int goc(int u )
{
    return (pa[u]==u? u  : pa[u]=goc(pa[u]));
}
vector<edge>q; 
pt a[N] ;
int res= 0 ; 

int n  ;
void inp()
{
    cin>>n;
    for(int i= 1 ;i<=n;i++)
    {
        a[i].id= i ; 
        cin>>a[i].x>>a[i].y>>a[i].z;
    }   
    sort(a+1,a+n+1,cmp1) ; 
    for(int i= 2;i<=n;i++)
    {
        q.pb({a[i-1].id,a[i].id,a[i].x-a[i-1].x});
    }
    sort(a+1,a+n+1,cmp2) ; 
    for(int i= 2;i<=n;i++)
    {
        q.pb({a[i-1].id,a[i].id,a[i].y-a[i-1].y});
    }
    sort(a+1,a+n+1,cmp3) ; 
    for(int i= 2;i<=n;i++)
    {
        q.pb({a[i-1].id,a[i].id,a[i].z-a[i-1].z});
    }
    sort(q.begin(),q.end());
    for(int i= 1;i<=n;i++)
    {
        pa[i] = i ; 
    }
    int sl = 0 ;  
    for(int i=0 ;i<q.size();i++)
    {
        if(sl==n-1)
        {
            cout<<res ; 
            return ; 
        }
        int u  = goc(q[i].u); 
        int v= goc(q[i].v) ;
        int chau = goc(u) ;
        int chav = goc(v);  
        if(chau==chav)continue; 
        pa[chau]=chav; 
        sl++;
        res+=q[i].w; 
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