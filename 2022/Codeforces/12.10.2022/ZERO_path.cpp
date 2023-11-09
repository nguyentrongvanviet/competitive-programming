// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "ZERO_path"

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

const int N =2e3+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n  ,m  ; 
int mi[N][N] , ma[N][N] ;
int a[N][N] ;
void doc()
{
    cin>>n >> m; 
    FOR(i,1,n)FOR(j,1,m)cin>>a[i][j] ; 
    if((n+m-1)&1)
    {
    	cout<<"NO"<<'\n';
    	return ; 
    }
    FOR(i,0,n+1)FOR(j,0,m+1)mi[i][j]=oo,ma[i][j]=-oo;
    FOR(i,1,n)
    {
    	FOR(j,1,m)
    	{
    		if(i==1&&j==1)
    		{
    			mi[i][j] =ma[i][j] =a[i][j]; 
    		}
    		else
    		{
    			ma[i][j]=  max(ma[i-1][j],ma[i][j-1])+a[i][j] ; 
    			mi[i][j]= min(mi[i-1][j],mi[i][j-1])+a[i][j] ;  
    		}
    	}
    }
    // cout<<mi[n][m]<<" "<<ma[n][m]<<endl;
    if(mi[n][m]<=0&&0<=ma[n][m])
    {
    	cout<<"YES"<<'\n';
    }
    else 
    {
    	cout<<"NO"<<'\n';
    }
}
void xuly()
{
    
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
    } 

}