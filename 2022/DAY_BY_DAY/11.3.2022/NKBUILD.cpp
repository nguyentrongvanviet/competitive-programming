#include<bits/stdc++.h>
using namespace std;

#define TASK "NKBUILD"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =100+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n , k , m ; 
ll f[1<<10][N] ; 
int id[N] ; 
int a[N] ; 
ll mi[N][N];
void doc()
{
 	cin>> n>> m>> k; 
 	for(int i=0;i<(1<<k);i++)
 	{
 		for(int j=1 ;j<=n;j++)f[i][j] = inf ; 
 	}
    for(int i=1 ;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            mi[i][j] =inf ; 
        }
        mi[i][i] = 0 ; 
    }
 	for(int i= 1 ;i<=k;i++)cin>>a[i],f[1<<(i-1)][a[i]]=0,id[a[i]]=i; 
 	for(int i =1 ;i<=m;i++)
 	{
 		int  u , v ; ll c;  
 		cin>>u>>v>>c; 
 		mi[u][v]= min(mi[u][v],c) ;
        mi[v][u] =min(mi[v][u],c) ;
 	}
    for(int x= 1; x<=n;x++)
    {
        for(int i=1 ;i<=n;i++)
        {
            for(int j= 1;j<=n;j++)
            {
                mi[i][j] =min(mi[i][x]+mi[x][j],mi[i][j]);
            }
        }
    }
 	for(int bit=0;bit<(1<<k);bit++)
 	{
 		for(int i= 1;i<=n;i++)
 		{
            for(int  j=1 ;j<=n;j++)
            {
                if(i==j)continue ;
                if(id[j]==0)
                {
                    f[bit][j]=min(f[bit][j],f[bit][i]+mi[i][j]);
                } 
                else 
                {
                    if(bit&(1<<(id[j]-1)))continue;
                    f[bit|(1<<(id[j]-1))][j] = min(f[bit|(1<<(id[j]-1))][j],f[bit][i]+mi[i][j]);
                }
            }
            for(int nbit= 0 ;nbit<(1<<k);nbit++)
            {        
                f[nbit|bit][i]=min(f[nbit][i]+f[bit][i],f[nbit|bit][i]);
            }
 		}
        for(int i= 1;i<=n;i++)
        {
            for(int nbit= 0 ;nbit<(1<<k);nbit++)
            {        
                f[nbit|bit][i]=min(f[nbit][i]+f[bit][i],f[nbit|bit][i]);
            }
        }
 	}
 	ll res= inf ; 
 	for(int i= 1;i<=n;i++)
 	{
 		res=min(res,f[(1<<k)-1][i]);
 	}
 	cout<<res;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}