#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define mp make_pair 
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout) ;
    }
}
const int N = 1e3+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};


int n; 	
int a[N][N], A2[N][N] , A5[N][N] ; 
bool ok = 0; 
int PT(int a,int x )
{
	int ans = 0 ; 
	while(a%x==0)++ans,a/=x; 
	return ans;  
}
int x , y  ;
void doc()
{
	cin>>n; 
	FOR(i,1,n)FOR(j,1,n)
	{
		cin>>a[i][j];
		if(a[i][j]==0)
		{
			ok=1 ;
			a[i][j] = 10 ;
			A2[i][j] = PT(a[i][j],2);
			A5[i][j] = PT(a[i][j],5);
			x = i ; 
			y = j ;
			continue ; 
		}
		A2[i][j] = PT(a[i][j],2) ; 
		A5[i][j] = PT(a[i][j],5) ;
	}
}	
int f2[N][N] ;
int f5[N][N] ; 
void xuly()
{				
	int res=0 ; 
	if(ok)res= 1;
	memset(f2,0x3f,sizeof f2);
	memset(f5,0x3f,sizeof f5);
	FOR(i,1,n)FOR(j,1,n)
	{
		if(i==1&&j==1)f2[i][j] =A2[i][j] , f5[i][j]=A5[i][j];
		if(i>1)
		{
			f2[i][j] = min(f2[i][j],f2[i-1][j]+A2[i][j]);
			f5[i][j] = min(f5[i][j],f5[i-1][j]+A5[i][j]);
		}
		if(j>1)
		{
			f2[i][j] = min(f2[i][j],f2[i][j-1]+A2[i][j]);
			f5[i][j] = min(f5[i][j],f5[i][j-1]+A5[i][j]);
		}
	}
	int u = min(f2[n][n],f5[n][n]) ;
	if(ok)
	{
		if(u>=1)
		{
			cout<<1<<el;
			FOR(i,1,x-1)cout<<"D";
			FOR(i,1,y-1)cout<<"R";
			FOR(i,x,n-1)cout<<"D";
			FOR(j,y,n-1)cout<<"R";
			return ;
		}
	}
	cout<<u<<el;
	if(u==f2[n][n])
	{
		str res="";
		int i = n , j = n; 
		while(!(i==1&&j==1))
		{
			// cout<<i<<" "<<j<<el;
			if(i>1)
			{
				if(f2[i-1][j]+A2[i][j]==f2[i][j])
				{
					i=i-1;res+='D';
					continue; 
				}
			}
			j=j-1;
			res+='R';
		}
		reverse(all(res)) ; 
		cout<<res;
		return ; 
	}
	if(u==f5[n][n])
	{ 
		str res="";
		int i = n , j = n; 
		while(!(i==1&&j==1))
		{
			if(i>1)
			{
				if(f5[i-1][j]+A5[i][j]==f5[i][j])
				{
					i=i-1;res+='D';
					continue; 
				}
			}
			j=j-1;
			res+='R';
		}
		reverse(all(res)) ; 
		cout<<res;
		return ;
	}
}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        doc(); 
        xuly();
    }
}