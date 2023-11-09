#include<bits/stdc++.h>

#define TASK "text"
const bool multitest = false; 
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));
#pragma GCC target("popcnt")
#define ll long long 
#define db long double  
#define pb push_back
#define int long long 
#define pk pop_back
#define pii pair<int,int>
#define vi vector<int>
#define ve vector 
#define str string 
#define pll pair<ll,ll>
#define fi first 
#define se second
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++) 
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b)  a/gcd(a,b)*b 
using namespace std;
const int N =2e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n  ,q ; 
int a[N] ; 
int node =1 ; 
int T[N*33][2], f[N*33]; 
ll po[35] ; 
void add(int bit )
{
	int r =1;  
	FORD(i,31,0)
	{
		int j= (bit>>i&1) ;
		// int j= (bit>>i&1) ;
		if(T[r][j]==0)
		{
			T[r][j]=++node; 
		}
		r=T[r][j] ; 
		f[r]++ ;
	}
}
int get(int bit)
{
	int r = 1; 
	FORD(i,31,0)
	{	
		int j= (bit>>i&1) ; 
		if(T[r][j]==0)return 0 ;
		r=T[r][j]; 
	}
	return r ; 
}
void del(int bit)
{
	int r= get(bit) ; 
	if(r==0||f[r]==0)return ;
	r = 1; 
	FORD(i,31,0)
	{
		int j= (bit>>i&1) ;
		r=T[r][j] ; 
		f[r]-- ; 	
	}
}
void clear(int bit)
{

	int r = get(bit) ; 
	int sl=f[r];  
	if(r==0||f[r]==0)return ;
	r= 1; 
	FORD(i,31,0)
	{
		int j= (bit>>i&1) ;
		r = T[r][j]; 
		f[r]-=sl;
	}
}
int findkth( int k )
{
	int r= 1; 
	int ans = 0 ; 
	FORD(i,31,0)
	{
		int left = f[T[r][0]] ; 
		int right = f[T[r][1]] ;
		if(left>=k)
		{
			r=T[r][0]; 
		}
		else
		{
			k-=left;
			r=T[r][1];
			ans^=(1<<i);
		}
	}
	return ans ;
}	
int amount(int bit)
{
	int ans =0 ;
	int r= 1;  
	FORD(i,31,0)
	{	
		int j= (bit>>i&1) ;
		if(j==1)
		{
			ans+=f[T[r][0]];
			r=T[r][1] ; 
		}
		else
		{
			r=T[r][0] ;
		}
	}
	ans+=f[r]; 
	return ans ; 
}
void read()
{
    cin>> n;
    po[0] = 1;
    FOR( i , 1 , 33) po[i] = po[i - 1 ] * 2;  
    FOR(i,1,n)cin>>a[i], a[i]+=1e9,add(a[i]) ; 
}
void process()
{
	
    
	ll sum=0  ;
	cin>>q;
	FOR(i,1,q)
	{	
		int t; cin>>t ; 
		if(t<=3)
		{
			int s; cin>>s;  
			int x= abs(sum+s)%((int)2e9+1);
			if(t==1)add(x); 
			if(t==2) del(x);
			if(t==3)clear(x);
		}
		else
		{
			int ans  ;  
			if(t==4)
			{
				int k ; cin>> k; 
				ans= findkth(k); 
				cout<<(int)ans-(int)1e9<<'\n'; 
				sum+=(int)ans-(int)1e9;
			}
			else
			{
				int l , r ; cin>>l>>r ; 
				l+=1e9 ; 
				r+=1e9;
				ans = amount(r) - amount(l-1) ; 
				cout<<ans<<'\n'; 
			} 
		}
	}
}
void print()
{

}
signed main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout); 
    }
    int test = 1;  
    if(multitest)cin>>test; 
    while(test--)
    {
        read() ; 
        process();
        print() ; 
    }
}