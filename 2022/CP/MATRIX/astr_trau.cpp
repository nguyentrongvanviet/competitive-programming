/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "astr"
#define int long long 
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

const int N= 10+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 111539786,cs=330 ,inf = 1e17  ;  

struct MT 
{
	int n  , m ; 		
	int mt[N][N] ;
};
MT nhan(MT a, MT b )
{
	MT ans ; 
	ans.n=a.n ; 
	ans.m=b.m;  
	int t = a.m  ; 
	FOR(i,0,ans.n) 
	{
		FOR(j,0,ans.m)
		{
			ll tmp = 0 ; 
			FOR(x,0,t)
			{
				tmp+= a.mt[i][x]*b.mt[x][j]%sm; 
				tmp%=sm;
			}
			ans.mt[i][j] = tmp ;
		}
	}
	return ans ; 
}

MT mu(MT a, int n )
{	
	if(n==1)return a ;
	MT b = mu(a,n/2) ; 

	if(n&1)
	{
		return nhan(nhan(b,b),a)  ;
	}
	return nhan(b,b) ;
}
ll pw(ll a, ll  n)
{
	if(n==0)return 1 ; 
	ll b = pw(a,n/2) ; 
	if(n&1)return (b*b)%sm*a%sm ; 
	return b*b%sm ;
}
MT X ,K ; 
int n , k; 
string s ;
int ok[N][N];
void doc()
{
	k =s.size() ; 
	K.n=  k  ; 
	K.m=  k ; 
}
void xuly()
{
	memset(ok,0,sizeof(ok));
	ok[0][0]=1;
	ok[0][1]=1;
    FORN(i,1,k)
    {		
   		FOR(c,0,1)
   		{
   			string tmp = s.substr(0,i) + char(c+'0') ; 
   			while(tmp!=""&&tmp!=s.substr(0,tmp.size()))
   			{
   				tmp.erase(0,1) ;
   			}
   			ok[i][tmp.size()]=1; 
   		}	
    }	
   	ok[k][k]=2;
   	FOR(i,0,k)
   	{
   		FOR(j,0,k)
   		{
   			K.mt[i][j]=ok[i][j] ; 
   		}
   	}
   	FOR(i,0,10)
   	{
   		FOR(j,0,10)
   		{
   			X.mt[i][j] =0 ; 
   		}
   	}
   	X.n=1 , X.m=k ,X.mt[0][0]=1;
   	X= nhan(X,mu(K,n));
   	cout<<(pw(2,n)-X.mt[0][k]+sm)%sm<<'\n';
}	
main()
{
    IOS();  
    while(cin>>n>>s)
   	{
   		doc(); 
    	xuly();
    }
}