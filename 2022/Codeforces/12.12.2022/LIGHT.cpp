/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "LIGHT"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
#define pii pair<int,int>
#define vi vector<int> 
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
void IOS()
{
    fast 
    srand(time(0)) ;
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =4e3+2 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct DL
{
    int l , r , p ; 
}a[N/2] ; 
struct ke 
{
    int v; 
    int cost;  
};
int n ,  T ,s , t ;
int cap[N][N];
vector<ke>g[N] ; 
ll d[N] ; 
int in[N],out[N] , pre[N];
bool inq[N] ; 
ll res =0 ; 
bool intersect(int i ,int j)
{
    return a[j].l<=a[i].r&&a[i].l<=a[j].r;  
}
void add(int u , int v, int ca,int c)
{   
    // cout<<u<<" "<<v<<" "<<ca<<" "<<c<<endl;
    g[u].pb({v,c}) ;
    g[v].pb({u,-c}) ;
    cap[u][v] =ca; 
    cap[v][u] =0 ; 
}
void doc()
{
    cin>> n >> T ; 
    FOR(i,1,n)
    {
        int t ,h ; 
        cin>>t>>h>>a[i].p ;
        a[i].l=t-h , a[i].r=t+h ;
        in[i] = i*2; 
        out[i] = i*2+1; 
        add(in[i],out[i],1,0);
    }
    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            if(i==j)continue ;
            if(intersect(i,j))
            {   
                add(out[i],in[j],1,a[j].p);
            }
        }
    }
    s = 0 ;
    t = 2*n+2 ; 
    FOR(i,1,n)
    {
        if(a[i].l<=0)
        {
            add(s,in[i],1,a[i].p);
        }
        if(a[i].r>=T)
        {
            add(out[i],t,1,0);
        }
    }
}
void ford(int s, int t )
{
    queue<int>q;
    FOR(i,1,2*n+2)d[i] = inf ;
    FOR(i,1,2*n+2)inq[i]=0 ;    
    d[s] = 0 ;
    inq[s] =1 ;
    q.push(s) ;
    while(!q.empty())
    {
        int u = q.front(); 
        q.pop() ; 
        inq[u] =0  ; 
        for(auto it : g[u])
        {
            int v =it.v;
            int c= it.cost;
            if(cap[u][v]>0&&d[v]>d[u]+c)
            {
                d[v]= d[u]+c;
                pre[v]= u ;
                if(!inq[v])
                {
                    inq[v] =1 ;
                    q.push(v) ;
                }
            }
        }
    }
}
void solve(int s ,int t )
{
    int flow =0 ;
    FOR(i,1,2)
    {
        ford(s,t);
        res+=d[t];
        for(int v= t ;v!=s;v=pre[v])
        {
            int u =pre[v] ; 
            cap[u][v]--;
            cap[v][u]++;
        }
    }   
    cout<<res; 
}
void xuly()
{
    solve(s,t) ;
}
int main()
{
    IOS();  
    doc(); 
    xuly();
    return 0 ;
}