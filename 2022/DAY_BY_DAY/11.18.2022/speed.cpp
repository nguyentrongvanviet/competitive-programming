#include<bits/stdc++.h>
using namespace std;

#define TASK "speed"

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

const int N =1e4+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
struct E 
{
	int u  ,v,  c; 
	bool operator <(const E& a)const
	{
		return c<a.c; 
	}
};
int n , m ; 
E edge[N]; 
vector<int>value ;
int tplt= 0 ;  
int tp = 0 ;
int pa[N] ; 
int goc(int u)
{
    return pa[u] == u ? u : pa[u]  = goc(pa[u]) ; 
}
void hop(int u , int v )
{
    int chau = goc(u) ; 
    int chav = goc(v) ; 
    if(chau==chav)return ; 
    pa[chau] = chav ;  
    tp--;
}
int la_min_r = 1   ; 
int res = oo , smin , smax ; 
void check(int id  , int value)
{
    // cout<<id<<" "<<res<<" "<<smin<<" "<<smax<<endl;
    FOR(i,1,n)pa[i] = i;
    tp = n ; 
    FOR(i,id,la_min_r)
    {
        hop(edge[i].u,edge[i].v); 
        if(tp==1)
        {
            if(res>edge[i].c-value)
            {
                res=edge[i].c-value ; 
                smin = value ; 
                smax= edge[i].c; 
                
            }
            return ;
        }
    }
    ++la_min_r ;
    while(la_min_r<=m)
    {
        int i=  la_min_r ; 
        hop(edge[i].u,edge[i].v);
        if(tp==1)
        {
            if(res>edge[i].c-value ) 
            {
                res= edge[i].c-value ; 
                smin =value;
                smax= edge[i].c ; 
            }
            return ;
        }
        la_min_r++;  
    }
}
void doc()
{
 	cin>> n >>m;
 	FOR(i,1,m)
 	{
 		int u ,v ,c ; cin>>u>>v>>c; 
 		edge[i]={u,v,c} ;
 	}
    sort(edge+1,edge+m+1) ;
    FOR(i,1,m)
    {
        if(la_min_r>m)
        {
            break; 
        }
        check(i,edge[i].c) ;
    }
    cout<<smin<<" "<<smax;
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
    // cin>>t ; 
    while(t--)
    {
        doc();
    }
}