/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "recovery"

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

struct MT
{
	// vector<vi>mt;
	ll mt [100][100];
	int n , m ; 
};
MT nhan(MT a, MT b )
{
	int n = a.n ; 
	int m=  a.m ;
	int p= b.n ; 
	int q= b.m;
	MT ans ; 
	ans.n = n ; 
	ans.m= q; 
	// ans.mt=vector<vi>(n,vi(q,0));
	FORN(i,0,ans.n)
	{
		FORN(j,0,ans.m)
		{
			ll tmp = 0  ;
			FORN(u,0,m)
			{
				tmp+=a.mt[i][u]*b.mt[u][j]%sm;
				tmp%=sm;
			}
			ans.mt[i][j] =tmp; 
		}
	}
	return ans;
}
MT pw(MT a , int n )
{
	if(n==1)
	{
		return a ;
	}
	MT b = pw(a,n/2) ; 
	if(n&1)
	{
		return nhan(a,nhan(b,b));
	}
	else 
	{
		return nhan(b,b);
	}
}
int n  , k;  
void doc()
{
	MT K  ;
 	cin>> n >> k;
 	K.n = k ; 
 	K.m = k ; 
 	// K.mt= vector<vi>(k,vi(k,0));
 	FORN(j,0,k)
 	{
 		FORN(i,0,k)
 		{	
 			if(i==j)K.mt[i][j]=1 ; 
 			else if(i==(j-1+k)%k||i==(j-2+k)%k)
 			{
 				K.mt[i][j]= 3 ;
 			}
 			else 
 			{
 				K.mt[i][j] =0 ; 
 			}
 		}
 	}   
 	K=pw(K,n) ;
 	MT res ; 
 	res.n= 1 ; 
 	res.m= k ;
 	res.mt[0][0] =1 ;
 	res=nhan(res,K); 
 	cout<<(res.mt[0][0]-1+sm)%sm; 
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