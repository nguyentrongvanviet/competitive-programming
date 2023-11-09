// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "FIXBRACKET"

#define fast 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define vi vector<int> 
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
void IOS()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
    srand(time(0)) ;
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =1e6+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct DL
{
	int len ;
	int head ; 
}st[4*N] ;
int n ,q ; 
int a[N]; 
void doc()
{
	cin>> n>>q;  
    FOR(i,1,n)
    {
    	char x; 
    	cin>>x ;
    	a[i] = (x=='('||x==')') ; 
    }
}
DL combine(DL a  ,DL b )
{	
	if(a.len==0)return b ; 
	else if(b.len==0)return a; 
	int lasta =a.head; 
	if(a.len%2==0)lasta=1-lasta;
	if(lasta!=b.head)
	{
		return {a.len+b.len,a.head};  
	}
	if(a.len>=b.len)
	{
		return {a.len-b.len,a.head} ; 
	}
	int headb= b.head; 
	if(a.len%2==1)
	{
		headb= 1-headb ; 
	}
	return {b.len-a.len,headb};
}
void build(int id , int l, int r )
{
	if(l==r)
	{
		st[id]={1,a[l]} ; 
		return ;  
	}
	int mid = (l+r)>>1; 
	build(id*2,l,mid) ; 
	build(id*2+1,mid+1,r) ;
	st[id]= combine(st[id*2],st[id*2+1]) ;
}
DL get(int id , int l , int r ,int t, int p  )
{
	if(r<t||p<l)return {0,0} ;
	if(t<=l&&r<=p)return st[id] ; 
	int mid = (l+r)>>1; 
	return combine(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p));
}
void xuly()
{
    build(1,1,n);
    while(q--)
    {
    	int l , r ; 
    	cin>>l>>r ; 
    	auto tmp = get(1,1,n,l,r) ; 
    	cout<<tmp.len/2<<'\n';
    }
}
int main()
{
    IOS();  
    int test ;
    cin>>test; 
    while(test--)
    {
        doc(); 
    	xuly();
    }

}