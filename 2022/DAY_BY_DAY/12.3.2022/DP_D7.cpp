// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "DP_D7"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
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

const int N =305 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 998244353,cs=330 ,inf = 1e17  ;  

int n , k ; 
ll f[N][N][(1<<3)]; 
void doc()
{
 	cin>>n>>k;
	FOR(j,0,(1<<2)-1)
	{
		if(btpc(j)==1)f[1][2][j]=1;
		else f[1][1][j]=1 ; 
	}
 	FOR(i,2,n)
 	{
 		FOR(t,10,k)
 		{
 			FOR(tt,0,(1<<2)-1)
 			{
 				FOR(ntt,0,(1<<2)-1)
 				{
 					if((tt==1&&ntt==2)||(tt==2&&ntt==1))
  					{
 						f[i][t][tt]+=f[i-1][max(0,t-2)][ntt] ;
 					}
 					else if((tt==0&&ntt==3)||(tt==3&&ntt==0)||(tt==1&&ntt==3)||(tt=3&&ntt==1))
 					{
 						f[i][t][tt]+=f[i-1][t-1][ntt];
 					}
 					else 
 					{
 						f[i][t][tt]+=f[i-1][t][ntt];
 					}
 					f[i][t][tt]%=sm; 
 				}
 			}
 		}
 	}
 	ll res= 0 ; 
 	FOR(i,0,(1<<2)-1)
 	{
 		res+=f[n][k][i];
 		res%=sm;  
 	} 
 	cout<<res;
}
void xuly()
{

}
int main()
{
    IOS();  
    doc(); 
    xuly();
}