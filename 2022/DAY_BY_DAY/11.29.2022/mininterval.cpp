#include<bits/stdc++.h>
using namespace std;
    
#define TASK "mininterval"
        
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
#define all(a) a.begin(),a.end()
void IOS()
{   
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}
#define int long long 
const int N =5e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n , m , k ;
int a[N] ; 
unordered_map<int,int>pos ; 
vector<int>vitri[N] ;
vector<int>node[N] ;
vector<int>value; 
ll res =0  ;
int pa[N] ; 
int dd[N] ; 
int val[N] ; 
int temp = 0 ;
void doc()
{
    cin>> n >>k ;
    FOR(i,1,n)cin>>a[i],value.pb(a[i]),val[i] = a[i];
    FOR(i,1,n)
    {
        if(3*a[i]<=k)res++;
    } 
}  
void init()
{
    FOR(i,1,n)
    {
        pa[i] =i ; 
        node[i].pb(val[i]) ;
    }
}
int goc(int u )
{
    return pa[u]== u ? u : pa[u] = goc(pa[u]) ;
}
void hop(int u ,int v ,int mi )
{
    u = goc(u); 
    v = goc(v) ;

    if(node[u].size()<node[v].size())
    {
        swap(u,v) ;
    } 
    // cout<<u<<" "<<v<<endl;
    for(auto x : node[v])
    {
        int sl  = upper_bound(all(node[u]),k-mi-x)-node[u].begin();
        temp+=sl;
    }
    int it1 = 0 ; 
    int it2 = 0 ; 
    vector<int>tmp ;
    while(it1<(int)node[u].size()&&it2<(int)node[v].size())
    {
        if(node[u][it1]<node[v][it2])
        {   
            tmp.pb(node[u][it1]);
            ++it1; 
        }
        else
        {
            tmp.pb(node[v][it2]);
            ++it2; 
        }
    }
    while(it1<(int)node[u].size())
    {
        tmp.pb(node[u][it1]); 
        ++it1;  
    }
    while(it2<(int)node[v].size())
    {
        tmp.pb(node[v][it2]); 
        ++it2; 
    }
    node[u] = tmp ; 
    pa[v]= u;
} 
void xuly()
{
    init();
    sort(value.begin(),value.end()); 
    value.resize(unique(all(value))-value.begin()) ;
    int m=  value.size();
    FOR(i,1,m)
    {
        pos[value[i-1]]= i;  
    }   
    FOR(i,1,n)
    {
        a[i]=pos[a[i]];         
        vitri[a[i]].pb(i);
    }
    FORD(i,m,1)
    {
        temp  = 0 ;
        for(auto x : vitri[i])
        {
            dd[x] =1 ; 
            if(dd[x-1])
            {
                hop(x-1,x,val[x]) ; 
            }
            if(dd[x+1])
            {
                hop(x+1,x,val[x]);  
            }
        }
        // cout<<temp<<"\n";
        res+=temp ; 
    }
    cout<<res;
}
main()
{
    IOS();  
    doc();
    // cout<<"G";
    xuly();
}