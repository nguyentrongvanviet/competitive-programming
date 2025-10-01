/*
Name   :   Nguyen Trong Van Viet
Age    :   18                              
School :   VNUHCM - University Of Science                                 
*/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

#include<bits/stdc++.h>
using namespace std; 

typedef long long ll ;
typedef double db ; 
typedef string str ; 
typedef vector<int> vi ;
typedef vector<ll> vll ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ; 
#define ve vector 
#define pb push_back
#define pk pop_back
#define el '\n'
#define mp make_pair 
#define fi first 
#define se second
#define uni(a) a.resize(unique(all(a))-a.begin()) 
#define FOR(i,a,b) for(int i=(int  )(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end()  
#define btpc __builtin_popcountll
#define LB lower_bound
#define UB upper_bound 
#define BIT(msk,i) ((msk)>>(i)&1)
#define MSK(i) (1ll<<(i))
#define tct template<class T>
tct T sq(T a){return a*a;}  
ll lg(ll a){return __lg(a);}
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
tct void prt(T a[],int n){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a){for(auto v:a)cout<<v<<" "; cout<<el;} 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}


int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};


const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 1e9+5 , LO = 17 , CH = 26 ; 


void up(int &a , int &b ,int c)
{
	if(a>=c)
	{
		b=a ; 
		a=c ; 
	}
	else if(b>c)
	{
		b=c ; 
	}
}
struct DL
{
	int mi1 , mi2 ; 
	DL(int val=oo)
	{
		mi1 = val;  
		mi2 = oo ; 
	}  
	friend DL operator+(DL a, DL b)
	{
		up(a.mi1,a.mi2,b.mi1) ; 
		up(a.mi1,a.mi2,b.mi2) ; 
		return a;  
	}
} ;
struct IT
{
	vector<DL>st ; 
	IT(int n=0)
	{
		st.resize(4*n) ; 
	}
	void up(int id ,int l, int r ,int pos , int val)
	{
		if(r<pos||pos<l)return ; 
		if(l==r)
		{
			st[id] = DL(val) ; 
			return ; 
		}
		int mid =(l+r)>>1 ;
		up(id<<1,l,mid,pos,val) ; 
		up(id<<1|1,mid+1,r,pos,val) ; 
		st[id] = st[id<<1]+st[id<<1|1] ; 
	}
	DL get(int id ,int l ,int r ,int t ,int p )
	{
		if(r<t||p<l)return DL() ;  
		if(t<=l&&r<=p)return st[id] ; 
		int mid =(l+r)>>1 ; 
		return get(id<<1,l,mid,t,p) + get(id<<1|1,mid+1,r,t,p) ; 
	}
}T[11]  ; 
int n; 
void UP(int pos ,int val)
{
	int D = val;  
	FOR(i,1,10)
	{
		if(D%10)
		{
			T[i].up(1,1,n,pos,val) ; 
		}
		else 
			T[i].up(1,1,n,pos,oo)  ;
		D/=10 ; 
	}

}
void GET(int l, int r)
{
	int res = 2*oo ;
	FOR(i,1,10)
	{
		DL val = T[i].get(1,1,n,l,r) ; 
		if(val.mi2!=oo)mini(res,val.mi1+val.mi2) ; 
	}
	if(res==2*oo)
	{
		cout<<-1<<el; 
	}
	else cout<<res<<el;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    
    if(fopen(INPUT,"r")){
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ; 
    }

    int m ; 
    cin>> n >> m;
    vector<int>a(n+1) ; 
    FOR(i,1,n)
    {
    	cin>>a[i] ; 
    }
    FOR(i,1,10)
    {
    	T[i]=IT(n) ; 
    }
    FOR(i,1,n)UP(i,a[i]) ; 
    while(m--)
    {
    	int type  ; cin>>type  ;
    	if(type==1)
    	{
    		int pos , val ; cin>>pos>>val;
    		UP(pos,val) ; 
    		a[pos] = val; 
    	}
    	else
    	{
    		int l ,r ; cin>> l >>r ;
    		GET(l,r) ; 
    	}
    }
    cerr<<el<<"[Finished in "<<clock()<<"ms]"<<el;
}



