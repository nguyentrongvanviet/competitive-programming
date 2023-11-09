#include<bits/stdc++.h>

#define TASK "Farray"
const bool multitest = false; 
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));
#pragma GCC target("popcnt")
#define ll long long 
#define db long double  
#define pb push_back
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
int n ; 
ve<pair<ll,int>>value; 
int a[N]  ; 
ll s[N];
ll S ; 
int pos[N];
int bit[N] ;
void read()
{
    cin>> n >>S ;
    FOR(i,1,n)cin>>a[i] ,  s[i] = s[i-1] + a[i],value.pb({s[i-1],i-1});   
}
void up(int idx , int val )
{			
	for(int i =idx;i<=n;i+=i&-i)
	{
		bit[i]  = max(bit[i],val) ;
	}
}`
int get(int idx)
{
	int ans= -oo;
	for(int i = idx ; i; i-=i&-i)
	{
		ans= max(ans,bit[i]); 
	}
	return ans; 
}

void process()
{
    sort(all(value)) ;
    FORN(i,0,value.size())pos[value[i].se] =i+1;
    FOR(i,1,n)bit[i] = -oo;
    int res= oo; 
    FOR(i,1,n)
    {
    	up(pos[i-1],i-1);
        int l = 1 ;
        int r=  n;
        int ans=0 ; 
        while(l<=r)
        {
            int mid =(l+r)/2;
            if(value[mid-1].fi<=s[i]-S)
            {
                ans= mid; 
                l=mid+1; 
            }  
            else
            {
                r=mid-1;
            }
        }
    	res=min(res,i-get(ans)) ; 
    }
    if(res==oo)cout<<-1;
    else cout<<res;
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