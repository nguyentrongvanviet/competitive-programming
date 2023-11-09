#define TASK "FCWATER"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define ll long long 
#define db double 
#define int long long 
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
const int N = 1e6+5  , oo = 2e9 , LO =__lg(N); 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ;
int n ; 
ll a[N] ; 
void doc()
{
	cin>> n; 
	FOR(i,1,n)cin>>a[i] ;
}       
int maL[N] , maR[N] ;
ll tinh() 
{
	ll ans =0 ; 
	FOR(i,1,n)
    {
    	maL[i] = maL[i-1] ; 
    	if(a[i]>=a[maL[i]])maL[i]=i ;
    } 
    FORD(i,n,1)
    {       
    	maR[i] = maR[i+1] ; 
    	if(a[i]>=a[maR[i]])maR[i]= i ; 
    } 
    FOR(i,2,n-1)
    {
        ans+=min(a[maL[i]],a[maR[i]])-a[i];
    }
    return ans;  
}
int L[N] , R[N] ; 
stack<int>st ; 
void xuly()
{ 
	ll res=  tinh() ; 
    FOR(i,1,n)
    {
        while(!st.empty()&&a[st.top()]<=a[i])st.pop() ;
        if(st.empty())L[i] = i ;  
        else L[i] = st.top() ;
        st.push(i) ;  
    }
    while(!st.empty())st.pop() ; 
    FORD(i,n,1)
    {
        while(!st.empty()&&a[st.top()]<=a[i])st.pop() ; 
        if(st.empty())R[i] = i; 
        else R[i] = st.top() ; 
        st.push(i) ; 
    }
    int ma = 0 ; 
    FOR(i,1,n)
    {
        int u = L[i] ; 
        int v = R[i] ; 
        if(u==i&&v==i)continue ;
        if(u!=i&&v!=i)continue ;  
        if(v==i)ma=max(ma,i-u-1);
        else ma=max(ma,v-i-1) ;
        // cout<<u<<" "<<i<<" "<<v<<" "<<ma<<el;
    }
    cout<<res+ma ; 
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