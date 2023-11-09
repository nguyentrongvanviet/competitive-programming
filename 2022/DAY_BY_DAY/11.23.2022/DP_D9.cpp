#include<bits/stdc++.h>
using namespace std;

#define TASK "DP_D9"

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

const int N =1000+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  
struct DL
{
	int l , r ; 
	ll c; 
};
struct BG 
{
    int l ; 
    ll c ;
    bool operator <(const BG&a)const
    {
        return l<a.l;
    } 
};
int n , m ,  k ; 
DL a[N] ; 
ll f[N][N] ;
vector<BG>pos[N] ;
void doc()
{
 	cin>>n>>m>>k ; 
 	FOR(i,1,m)
 	{
 		cin>>a[i].l>>a[i].r>>a[i].c ; 
 	}   
}
void sub1()
{
    f[0][0] = 0 ;
    FOR(i,0,n)
    {
        FOR(j,1,k)
        {
            f[i][j] = inf ; 
        }
    }
    FOR(i,1,n)
    {
        FOR(j,1,k)
        {
            f[i][j]=f[i-1][j];
            FOR(t,1,m)
            {
                int l = a[t].l ; 
                int r=  a[t].r ; 
                if(l<=i&&i<=r)
                {
                    f[i][j] = min(f[l-1][j-(i-l+1)]+a[t].c,f[i][j]);
                }
            }
        }
    }
    if(f[n][k]==inf)
    {
        cout<<-1 ; 
        return ;
    }
    cout<<f[n][k];
}
void xuly()
{   
    FOR(i,1,m)
    {
        pos[a[i].r].pb({a[i].l,a[i].c});
    }
    FOR(i,1,n)sort(pos[i].begin(),pos[i].end());
    FOR(i,0,n)
    {
        FOR(j,1,k)
        {
            f[i][j] = inf ; 
        }
    }
    f[0][0] = 0 ; 
    FOR(j,1,k)
    {
        FOR(i,1,n)
        {
            ll mi = inf ;
            int it = 0 ;   
            f[i][j]= f[i-1][j] ; 
            FOR(t,1,i)
            {
                while(it<pos[i].size())
                {
                    if(pos[i][it].l<=t)
                    {
                        mi=min(mi,pos[i][it].c);
                        ++it;  
                        // cout<<it<<endl;
                    }
                    else break;
                }
                f[i][j] = min(f[i][j],mi+f[t-1][max(0,j-(i-t+1))]);
            }
        }
    }
    if(f[n][k]==inf)
    {
        cout<<-1;  
        return ; 
    }
    cout<<f[n][k];
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}