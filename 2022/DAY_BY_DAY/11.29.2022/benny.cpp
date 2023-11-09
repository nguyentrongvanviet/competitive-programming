#include<bits/stdc++.h>
using namespace std;

#define TASK "benny"

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

const int N =1e3+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ,  k ; 
int a[N] , b[N] ;
vector<int>pos[N];
int f[N][N][2];

void doc()
{
	cin>>n >>k;
	FOR(i,1,n)cin>>a[i] ;     
	FOR(i,1,n)
	{
		cin>>b[i] ; 
		pos[b[i]].pb(a[i]);
	}
	FOR(i,1,(int)1e3)sort(all(pos[i]));
}
void xuly()
{
	FOR(i,0,(int)1e3)
	{
		FOR(j,1,k)
		{
			f[i][j][0]=f[i][j][1]=oo;
		}
	}
    FOR(i,1,(int)1e3)
    {
    	FOR(j,1,k)
    	{
    		f[i][j][0]=f[i-1][j][0] ; 
    		f[i][j][1] =f[i-1][j][1]; 
    		for(int it = 0 ;it<pos[i].size();it++)
    		{
    			if(j-(it+1)<0)break; 
    			f[i][j][0] = min(f[i][j][0],f[i-1][j-(it+1)][0]+2*pos[i][it]);
    			f[i][j][1] = min({f[i][j][1],f[i-1][j-(it+1)][1]+2*pos[i][it],f[i-1][j-(it+1)][0]+pos[i][it]});
    		} 
    	}
    }
    cout<<f[(int)1e3][k][1]<<"\n";;
}	
void clear()
{
	FOR(i,1,(int)1e3)pos[i].clear();
}
int main()
{
    IOS();  
    int test ; 
    cin>>test; 
    while(test--)
    {
        doc(); 
   		xuly();	
   		clear();
    }

}