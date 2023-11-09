#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define mp make_pair 
#define fi first 
#define se second  
#define tct template<typename T>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
const int N = 2e5+5  , oo = 2e9 , LO =__lg(N); 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ;
int n , k ; 
int a[N] ; 
int f[N] ; 
int pos[N] ; 
struct DL
{
    int val; 
    int id ; 
    bool operator<(const DL&other)const
    {
        return val<other.val||(val==other.val&&id<other.id) ; 
    }
};  
ve<DL> value ;
int st[4*N];
void build(int id, int l, int r)
{
 if(l==r)
 {
     st[id] = a[l] ;
     return ; 
 } 
 int mid=(l+r)/2; 
 build(id*2,l,mid); 
 build(id*2+1,mid+1,r) ; 
 st[id] = max(st[id*2],st[id*2+1]) ; 
}
void up(int id, int l ,int r ,int  pos , int val)
{
 if(l==r&&l==pos)
 {
     st[id] = val; 
     return ; 
 }    
 if(r<pos||pos<l)return ; 
 int mid = (l+r)/2 ;
 up(id*2,l,mid,pos,val) ; 
 up(id*2+1,mid+1,r,pos,val);
 st[id] = max(st[id*2],st[id*2+1]) ;  
}
int get(int id, int l, int r ,int t, int p)
{
 if(t<=l&&r<=p)return st[id] ;
 if(r<t||p<l)return 0 ; 
 int mid = (l+r)/2 ;
 return max(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)) ;
} 

void doc()
{
 	cin>> n >> k;  
 	FOR(i,1,n)cin>>a[i],value.pb({a[i],i}) ;    
}       
int np1(int val)
{
    int l =1 ;
    int r= n ; 
    int ans  = 0 ;
    while(l<=r)
    {
        int mid =(l+r)/2 ;
        if(value[mid-1].val>=val)ans=mid,r=mid-1; 
        else l=mid+1; 
    }
    return ans;  
}
int np2(int val)
{
    int l = 1; 
    int r =n ; 
    int ans =0  ; 
    while(l<=r)
    {
        int mid =(l+r)/2 ; 
        if(value[mid-1].val<val)ans=mid,l=mid+1; 
        else r=mid-1;  
    }
    return ans ; 
}
void xuly()
{
	sort(all(value)) ; 
    FOR(i,1,n)
    {
        pos[value[i-1].id] =  i ;  
    }
    FOR(i,1,n)
    {
        int u  = np1(a[i]-k) ;
        int v=  np2(a[i]);    
        f[i] = get(1,1,n,u,v)+1;  
        up(1,1,n,pos[i],f[i]);  
    }
    int res=0 ; 
    FOR(i,1,n)maxi(res,f[i]) ; 
    cout<<res; 
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test =1;
    if(multitest)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Time: "<<clock()<<"ms"<<el;
}