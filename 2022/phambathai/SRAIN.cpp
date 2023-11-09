#include<bits/stdc++.h>

#define TASK "text"
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
const int N =1e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
struct Query
{
	int t , l , r , d ;  
};
struct Node
{
	ll sum ;
	ll  mi ; 
	int sl ; 
	int pos ; 
};
int n ,q ; 
int a[N] , b[N] ; 
Query Q[N] ;
Node st[N*8]  ; 
ll  bit[N] ; 
ll  lazy[N*8]  ;  
void dolazy(int id,ll lazy[] ,  Node st[]) 
{	
	st[id].sum+=lazy[id]*st[id].sl; 
	st[id].mi-=lazy[id];
	lazy[id*2]+=lazy[id]; 
	lazy[id*2+1]+=lazy[id];
	lazy[id] =0 ; 
}
Node cb(Node A , Node B)
{
	int pos = A.pos ; 
	if(A.mi>B.mi)pos=B.pos;
	return Node{A.sum+B.sum,min(A.mi,B.mi),A.sl+B.sl,pos};
}
void build(int id, int l , int r  , Node st[]  )
{
	if(l==r)
	{
		st[id].sum = a[l];
		st[id].sl =  1 ; 
		st[id].mi = b[l] - a[l]; 
		st[id].pos= l ; 
		return ; 
	}
	int mid =(l+r)/2 ; 
	build(id*2,l,mid,st) ; 
	build(id*2+1,mid+1,r,st) ; 	
	st[id]=cb(st[id*2],st[id*2+1]) ; 
}
void update(int id, int l ,int r,  int t, int p , int val  ,  ll lazy[] , Node st[])
{
	dolazy(id , lazy , st) ;
	if(t<=l&&r<=p)
	{	
		lazy[id]+=val;  
		dolazy(id,lazy,st) ;
		return ; 
	}
	if(r<t||p<l)return ; 
	int mid =(l+r)/2 ; 
	update(id*2,l,mid,t,p,val,lazy,st) ; 
	update(id*2+1,mid+1,r,t,p,val,lazy,st) ; 
	st[id]=cb(st[id*2],st[id*2+1]) ;
}

Node get(int id , int l, int r , int t, int p,ll lazy[] , Node st[])
{
	dolazy(id,lazy,st) ; 
	if(t<=l&&r<=p)return st[id] ;
	if(r<t||p<l)return Node{0,-inf,0};
	int mid =(l+r)/2;  
	return cb(get(id*2,l,mid,t,p,lazy,st),get(id*2+1,mid+1,r,t,p,lazy,st));
}
void del(int id, int l ,int r , int pos,ll lazy[] , Node st[])
{
	dolazy(id,lazy,st);
	if(l==r&&l==pos)
	{	
		st[id].sum = 0 ;
		st[id].sl= 0 ;
		st[id].mi=inf ;
		return ; 
	}
	if(pos<l||r<pos)return ; 
	int mid =(l+r)/2; 
	del(id*2,l,mid,pos,lazy,st) ; 
	del(id*2+1,mid+1,r,pos,lazy,st) ; 
	st[id] = cb(st[id*2],st[id*2+1]); 
}
void upbit(int idx , int val)
{
	for(int i = idx ; i<=n ;i+=i&-i)bit[i]+=val; 
}
ll getbit(int idx )
{
	ll ans =0  ;
	for(int i = idx ;i ;i-=i&-i)ans+=bit[i] ; 
	return ans; 
}
void read()
{
    cin>> n;
    FOR(i,1,n)cin>>a[i]>>b[i];
    cin>>q ; 
    FOR(i,1,q )
    {
    	cin>>Q[i].t ; 
    	if(Q[i].t==1)
    	{
    		cin>>Q[i].l>>Q[i].r; 
    	}
    	else if(Q[i].t==0)
    	{	
    		cin>>Q[i].l>>Q[i].r>>Q[i].d;
    	}
    }	
}	
void process()
{
	build(1,1,n,st) ; 
	FOR(i,1,q)
	{
		int t = Q[i].t ; 
		int l =Q[i].l ; 
		int r =Q[i].r ;  
		if(t==1)
		{
			Node ans = get(1,1,n,l,r,lazy,st) ; 
			ll full = getbit(r) -getbit(l-1) ;
			cout<<ans.sum+full<<'\n'; 
		}
		else
		{
			update(1,1,n,l,r,Q[i].d,lazy,st);
			while(st[1].mi<0)
			{
				int pos = st[1].pos ;
				del(1,1,n,pos,lazy,st);
				upbit(pos,b[pos]);
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