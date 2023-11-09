#define TASK "INDEP"
#include<bits/stdc++.h>
using namespace std; 

bool multitest =  false ;
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
#define ll long long 
#define int long long 
#define db long double
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
#define FOR(i,a,b) for(int i =a ;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORN(i,a,b) for(int i= a ;i<b;i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a);
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
#define el '\n' 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(a%b,a);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
    void IOS()
    {
        fast 
        if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
    }
const int N =2e5+5 , maxN=20 , oo = 1e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

struct DL
{
    int A_ , _B , AB , __ ;
};
DL S(DL a, DL b )
{   
    DL tmp  ; 
    tmp.A_ = max( a.A_+b.__ , a.AB+b.A_-1) ; 
    tmp._B = max( a.__+b._B , a._B+b.AB-1) ;
    tmp.AB = max( a.AB+b.AB-1, a.A_+b._B ) ;
    tmp.__ = max( a._B+b.A_-1, a.__+b.__ ) ;
    return tmp  ;
}   
DL P (DL a ,DL b)
{
    DL tmp;
    tmp.A_ = a.A_+b.A_-1;
    tmp._B = a._B+b._B-1;
    tmp.AB = a.AB+b.AB-2; 
    tmp.__ =a.__+b.__;  
    return tmp ; 
}
str s ; 
stack<DL>st ; 
void read()
{
    cin>>s ;  
}
void solve()
{
    int n=  s.size() ;
    s=" "+s ; 
    FORD(i,n,1)
    {

        if(s[i]=='S')
        {
            DL u ,v , tmp  ; 
            
            u =st.top() ; 
            st.pop() ; 
            v = st.top()  ;
            st.pop() ; 
            tmp =S(u,v) ; 
            st.push(tmp) ; 
            // cout<<tmp.A_<<" "<<tmp._B<<" "<<tmp.AB<<" "<<tmp.__<<el;
        }
        if(s[i]=='P')
        {
            DL u, v, tmp ;  
            u = st.top() ; 
            st.pop() ; 
            v = st.top() ; 
            st.pop() ; 
            tmp =P(u,v) ;
            st.push(tmp);
            // cout<<tmp.A_<<" "<<tmp._B<<" "<<tmp.AB<<" "<<tmp.__<<el;
        }
        if(s[i]=='g')
        {
            DL tmp = {1,1,-oo,0};
            st.push(tmp) ;  
            // cout<<tmp.A_<<" "<<tmp._B<<" "<<tmp.AB<<" "<<tmp.__<<el;
        }
    }
    DL tmp = st.top() ; 
    int res = max({tmp.A_,tmp._B,tmp.AB,tmp.__});
    cout<<res;
}
signed main()
{
    IOS() ; 
    int test =1 ; 
    if(multitest)cin>>test;
    while(test--)
    {
        read() ; 
        solve() ;
    }
}