#include<bits/stdc++.h>
using namespace std;

#define TASK "bangmau"

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

const int N =1e3+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n  , m  , x,  y;  
int a[N][N] ; 
int black[N] ; 
int white[N] ;
int s0[N] , s1[N];
int f[N][2]; 
void doc()
{
    cin>>n>>m>>x>>y;
    FOR(i,1,n)
    {
    	FOR(j,1,m)
    	{
    		char x; cin>>x ; 
    		a[i][j] = {x=='#'};
    	}
    }  
    FOR(i,1,m)
    {
    	FOR(j,1,n)
    	{
    		black[i]+=(a[j][i]==0); 
    	}
    	white[i] = n -black[i] ; 
    }
    FOR(i,1,m)
    {
        s0[i] =s0[i-1]+black[i] ; 
        s1[i] = s1[i-1]+white[i];
    }
    FOR(i,1,m)
    {   
        f[i][1]=f[i][0]=oo;
    }
    FOR(i,1,m)
    {
    	FOR(j,x,min(i,y))
    	{
    		f[i][0] = min(f[i][0],f[i-j][1]+s0[i]-s0[i-j]);
            f[i][1] = min(f[i][1],f[i-j][0]+s1[i]-s1[i-j]);
    	}
    }
    cout<<min(f[m][0],f[m][1]);
}	
void xuly()
{
    
}
int main()
{
    IOS();  
    doc(); 
    // cout<<"G";
    xuly();
}