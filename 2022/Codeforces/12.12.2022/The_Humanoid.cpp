/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "The_Humanoid"

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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n, h ; 
ll a[N] ; 
ll f[N][3][2] ; 
void doc()
{
    cin>> n >>h ; 
    FOR(i,1,n)cin>>a[i];
    sort(a+1,a+n+1) ; 
    FOR(i,0,n)FOR(j,0,2)FOR(k,0,1)f[i][j][k] =0  ;
    f[0][2][1]= h ; 
    FOR(i,1,n)	
    {
    	FOR(j,0,2)
    	{
    		FOR(k,0,1)
    		{
    			FOR(prej,j,2)
    			{
    				FOR(prek,k,1)
    				{	
    					if(f[i-1][prej][prek]&&f[i-1][prej][prek]*pow(2,prej-j)*pow(3,prek-k)>a[i])
    					{
    						f[i][j][k]= max(f[i][j][k],f[i-1][prej][prek]*(ll)pow(2,prej-j)*(ll)pow(3,prek-k)+a[i]/2);
    					}
    				}
    			}
    		}
    	}	
    } 
    FORD(i,n,1)
    {
    	if(f[i][0][0])
    	{
    		cout<<i<<'\n';
    		return ; 
    	}
    }
    cout<<0<<'\n';
}
void xuly()
{
    
}
int main()
{
    IOS();  
    int test ;
    cin>>test ;
    while(test--)
    {
        doc(); 
    	xuly();
    }

}