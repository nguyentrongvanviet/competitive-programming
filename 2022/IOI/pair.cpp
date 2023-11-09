#define TASK "pair"
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
const int N = 2e5+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int B , n , D ,M ; 
void read()
{
	cin>>B>>n>>D >>M ;
}

void sub1()
{
	vi a(n+1,0) ; 
	FOR(i,1,n)cin>>a[i] ; 
	sort(a.begin()+1,a.begin()+n+1) ;
	int it= 1 ;
	ll res= 0 ; 
	for(int i= 1;i<=n;i++)
	{
		while(a[i]-a[it]>D)++it ;
		res+=abs(i-it);
	}
	cout<<res<<el;
}	
struct DL2
{
	int A , B ;
	bool operator<(const DL2&other)const
	{
		return A<other.A;
	}  
};
int bit1[N] ;
void up1(int idx, int val )
{
	for(int i= idx;i<=150000;i+=i&-i)bit1[i]+=val; 
}
int get1(int idx )
{
	int ans= 0  ;
	for(int i = idx;i;i-=i&-i)ans+=bit1[i] ;
	return ans; 
}
void sub2()
{
	ve<DL2>a(n+1);
	FOR(i,1,n)
	{
		int x , y; 
		cin>>x>>y; 
		a[i] = {x+y,x-y+75000} ; 
	}
	sort(a.begin()+1,a.begin()+n+1);

	int it = 1;
	ll res= 0 ; 
	FOR(i,1,n)
	{
		while((a[i].A-a[it].A)>D)
		{
			up1(a[it].B,-1); 
			++it ;
		}	
		res+=get1(min(150000,a[i].B+D))-get1(max(0,a[i].B-D-1));
		up1(a[i].B,1); 
	} 
	cout<<res ;
}
struct DL3
{
	int A, x , y ,z ; 
	bool operator<(const DL3&other)const
	{
		return A<other.A ;  
	}
};
int bit3[226][226][226];
void up3(int x, int y , int z ,int val)
{
	for(int i=x;i<=225;i+=i&-i)
	{
		for(int j=y;j<=225;j+=j&-j)
		{
			for(int k=z;k<=225;k+=k&-k)
			{
				bit3[i][j][k]+=val;
			}
		}
	}
}
int get3(int x, int y , int z )
{
	int ans= 0 ; 
	for(int i=x;i;i-=i&-i)
	{
		for(int j=y;j;j-=j&-j)
		{
			for(int k=z;k;k-=k&-k)
			{
				ans+=bit3[i][j][k] ; 
			}
		}
	}
	return ans; 
}
void sub3()
{
	ve<DL3>a(n+1) ; 
	for(int i=1 ;i<=n;i++)
	{
		int x, y,z ; 
		cin>>x>>y>>z ; 
		a[i] = {x+y+z,x+y-z+75,x-y+z+75,x-y-z+150};
	}
	sort(a.begin()+1,a.begin()+n+1) ;
	int it = 1 ;
	ll res = 0 ;   
	for(int i= 1;i<=n;i++)
	{	
		while(a[i].A-a[it].A>D)
		{
			up3(a[it].x,a[it].y,a[it].z,-1);
			++it;
		} 
		int x = min(a[i].x+D,225) ;
		int y = min(a[i].y+D,225) ;
		int z = min(a[i].z+D,225) ; 
		int xx = max(a[i].x-D,1) ; 
		int yy = max(a[i].y-D,1) ; 
		int zz = max(a[i].z-D,1) ;
		int A= get3(x,y,z) - get3(xx-1,y,z) - get3(x,yy-1,z) + get3(xx-1,yy-1,z);
		int B = get3(x,y,zz-1) - get3(xx-1,y,zz-1) - get3(x,yy-1,zz-1) + get3(xx-1,yy-1,zz-1);
		res+=A-B;
		up3(a[i].x,a[i].y,a[i].z,1); 
	}
	cout<<res;
}
signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        read(); 
        if(B==1)sub1() ; 
        if(B==2)sub2() ; 
        if(B==3)sub3() ; 
        // solve();
    }
}