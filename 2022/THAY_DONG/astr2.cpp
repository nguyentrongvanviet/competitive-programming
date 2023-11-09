#include<bits/stdc++.h>

#define TASK "astr2"
const bool multitest = false; 

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
#define pii pair<int,int>
#define vi vector<int>
#define ve vector
#define str string  
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b)  a/gcd(a,b)*b 
using namespace std;
template<typename U>
void print(U arr) {
    for(auto element: arr) {
        cout << element << " ";
    }
    cout << endl;
}
const int N =2e2+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 111539786,cs=330 ,inf = 1e17; 
const double PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n, k ;
str a[N] ; 
int T[N*20][CH]  , End[N*20];
int node= 1 ; 
int Next[N*20][2];
ll F[N][N*20] ; 
str s ; 
void up(string s)
{
    int r = 1; 
    FORN(i,0,s.size())
    {
        int j = s[i]-'0'; 
        if(T[r][j]==0)
        {
            T[r][j] = ++node; 
        }
        r=T[r][j] ; 
    }
    End[r] = 1; 
}
int get(string s )
{
    int r = 1; 
    FORN(i,0,s.size())
    {
        int j=  s[i]-'0' ; 
        if(T[r][j]==0)
        {
            return 1; 
        }
        r=T[r][j] ; 
    }
    return r ;  
}
void read() 
{
    cin>> n >> k; 
    FOR(i,1,k)
    {
    	cin>>a[i] ; 
    	up(a[i]) ;
    } 
}

ll tinh(int pos , int node )
{
    cout<<pos<<" "<<node<<endl;
    if(F[pos][node]!=-1)return F[pos][node] ; 
    if(pos==n+1)
    {
        return F[pos][node]=1 ; 
    }
    ll tmp = 0 ;
    FOR(j,0,1)
    {
        int nnode = Next[node][j];
        if(End[nnode]||End[T[node][j]])continue; 
        tmp+=tinh(pos+1,nnode); 
        tmp%=sm;  
    }
    return F[pos][node] = tmp ;
}
void process()
{
	FOR(i,1,k)
    {
        int r= 1 ; 
        FOR(j,1,a[i].size())
        {
            str s = a[i].substr(0,j) ;
            int node= get(s);
            s.erase(0,1);
            FOR(c,0,1)
            {
                str tmp =s+(char)(c+'0') ; 
                while(tmp.size()&&get(tmp)==1)
                {
                    tmp.erase(0,1);
                }
                Next[node][c] = get(tmp); 
            } 
            FOR(x)
        }
    } 
    FOR(c,0,1)
    {
        str tmp = to_string(c);
        Next[1][c]= get(tmp);
    }
    FOR(i,0,n+1)
    {
        FOR(j,1,node)
        {
            F[i][j] = -1 ; 
        }
    } 
}
void print()
{   
    ll res= tinh(1,1); 
    cout<<res;
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