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

const int N =1e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 111539786,cs=330 ,inf = 1e17  ;  

int n , m ; 
string s ;
void doc()
{
 	cin>> n>>s ; 
}	
ll pw(ll a, ll n )
{
	if(n==0)return 1;
	if(n==1)return a; 
	ll b= pw(a,n/2) ; 
	if(n&1)return b*b%sm*a%sm;
	return b*b%sm; 
}
ll f[N][6];
int Next[N][2] ;
ll tinh(int pos , int len)
{
	if(f[pos][len]!=-1)return f[pos][len] ; 
	if(pos==n+1)return f[pos][len] =(len==m) ;
	ll res= 0 ;
	FOR(i,0,1)
	{
		res+=tinh(pos+1,Next[len][i]);
		res%=sm; 
	}
	return f[pos][len]=res;
}
 
void build()
{
	FOR(i,0,1)Next[0][i]=(s[0]==i+'0');
	FOR(i,1,m-1)
	{
		FOR(j,'0','1')
		{
			string tmp = s.substr(0,i)+(char)j;
			while(tmp!=""&&tmp!=s.substr(0,tmp.size()))
			{
				tmp.erase(0,1); 
			}
			Next[i][j-'0'] =tmp.size();
		}
	}
	Next[m][0]=Next[m][1]=m; 
}
void xuly()
{
    memset(f,-1,sizeof(f)) ;
    build();
    cout<<(pw(2,n)-tinh(1,0)+sm)%sm<<'\n';
}
int main()
{
    IOS();  
    while(cin>>n>>s)
	{
		m = s.size() ; 
		xuly();
	}
    
}