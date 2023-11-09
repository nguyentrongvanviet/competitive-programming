/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "wgamepn"

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

const int N =150+1 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll cs=330 ,inf = 1e17  ;  
ll sm;  
char a[N][N];
int n , m ; 
string s ; 
ll f[N][N][N][2] ; 
int xx1[]={1,0}; 
int yy1[]={0,1}; 
int xx2[]={0,-1}; 
int yy2[]={-1,0};
void doc()
{
    cin>>n>>m>>sm;
    cin>>s; 
    FOR(i,1,n)
    {
    	FOR(j,1,m)
    	{
    		cin>>a[i][j] ; 
    	}
    }
}
ll tinh(int x , int y ,int u ,int ok )
{
	int v = n-u+m-x-y+2;
	cout<<x<<" "<<y<<" "<<u<<" "<<v<<" "<<ok<<endl;
	if(f[x][y][u][ok]!=-1)return f[x][y][u][ok] ; 
	if(abs(x-u)+abs(y-v)<=1)return f[x][y][u][ok]=(ll)ok;
	ll ans =0  ;
	FORN(i,0,2)
	{
		FORN(j,0,2)
		{
			int nx = x+xx1[i] ; 
			int ny = y+yy1[i] ; 
			int nu = u+xx2[j] ; 
			int nv = v+yy2[j] ; 
			// cout<<nx<<" "<<ny<<" "<<nu<<" "<<nv<<endl;
			if(nx<=nu&&ny<=nv&&a[nx][ny]==a[nu][nv]&&a[nu][nv]!='#')
			{
				ans+=tinh(nx,ny,nu,ok|(a[nx][ny]==s[0]));
				ans%=sm;
			}
		}
	}
	return f[x][y][u][ok]=ans;
}
void xuly()
{
    if(a[1][1]!=a[n][m])
    {
    	cout<<0 ; 
    	return ; 
    }
    memset(f,-1,sizeof(f));
    cout<<tinh(1,1,n,a[1][1]==s[0]);
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}