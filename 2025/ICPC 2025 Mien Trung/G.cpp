/*
Name   :   Nguyen Trong Van Viet
DoB    :   29 - 10 - 2006                      
School :   VNUHCM - University Of Science         
Donate :   VCB    - 1026950589                         
*/

#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

#include<bits/stdc++.h>
using namespace std; 

typedef long long ll ;

#define fi first 
#define se second
#define uni(a) a.resize(unique(all(a))-a.begin()) 
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

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};


const double PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

struct DL
{
	int id , height , width ; 
} ; 
vector<DL>Q[6] ; 
int res[N] ; 



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
    int n , m , q ;
    cin>> n >> m >> q; 
    vector<vector<int>>a(n,vector<int>(m,0)) ; 
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
        char x ; cin>>x ; 
    	a[i][j] = (x=='#') ; 
    }
    for(int i=0;i<q;i++)
    {
    	int w , h  , k ; cin>> w >> h >> k; 
    	Q[k].push_back({i,w,h}) ; 
    }
    vector<vector<int>>h(n,vector<int>(m)) ; 
    auto solve = [&](int k , vector<DL>& Q)->void
    {

        vector<int>stop(m,0) ; 
        vector<vector<pair<int,int>>>q(n+1) ; 
        for(int j=0;j<m;j++)
        {
            int cnt = (a[0][j]==1) ; 
            while(stop[j]<n&&cnt<=k)
            {
                ++stop[j] ; 
                if(stop[j]<n)cnt+=a[stop[j]][j]; 
            }
            q[stop[j]].push_back({0,j}) ; 
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i-1][j])
                {
                    while(stop[j]<n)
                    {
                        ++stop[j] ; 
                        if(stop[j]>=n||a[stop[j]][j])break ; 
                    }
                }   
                q[stop[j]-i].push_back({i,j})  ; 
            }
        }
        vector<vector<pair<int,int>>>pa(n,vector<pair<int,int>>(m,make_pair(-1,0))) ; 
        vector<int>sum_1(m+1,0) ; 
        vector<int>sum_1_i(m+1,0) ;
        
        // BIT 
        // {    
            auto up = [&](int pos , int sign)->void
            {
                // cout<<"UP "<<pos<<" "<<sign<<endl;
                for(int i=pos;i;i-=i&-i)sum_1[i]+=sign , sum_1_i[i]+=sign*(1+pos) ; 
            }; 
            auto get = [&](int pos)->int 
            {
                int sl =  0 ;
                int sum = 0 ;  
                for(int i=pos;i<=m;i+=i&-i)
                {
                    sl+=sum_1[i]; 
                    sum+=sum_1_i[i] ; 
                }
                return sum-sl*pos ; 
            };
        // }  
        // DSU 
        // {
            auto goc = [&](int x ,int y,auto&& goc_ref) ->int 
            {
                // not exist yet  
                if(pa[x][y].first==-1)return -1 ; 
                return pa[x][y].first== y ? y : goc_ref(x,pa[x][y].first,goc_ref) ;
            };  
            auto hop = [&](int x ,int y)->void 
            {
                int left = (y==0?-1:goc(x,y-1,goc)) ; 
                int right = (y==m-1?-1:goc(x,y+1,goc)) ; 
                pa[x][y]  = make_pair(y,1) ; 
                if(left!=-1)
                {
                    pa[x][left].first = y  ; pa[x][y].second+=pa[x][left].second ; 
                    up(pa[x][left].second,-1) ; 
                }
                if(right!=-1) 
                {
                    pa[x][right].first = y , pa[x][y].second+=pa[x][right].second ;
                    up(pa[x][right].second,-1) ; 
                }
                up(pa[x][y].second,+1) ; 
            };            
        // }

        sort(all(Q),[](const DL&a , const DL&b ){return a.height>b.height;}) ;
        
        int len = n  ;  

        for(auto [id,height,width]:Q)
        {   
            while(len>=height)
            {
                for(auto [x,y]:q[len])
                {
                    hop(x,y) ; 
                }
                --len ; 
            }
            res[id] = get(width) ; 
        }
    }; 

    for(int i=0;i<=5;i++)
    {
    	solve(i,Q[i]) ; 
    }
    for(int i=0;i<q;i++)
    {
        cout<<res[i]<<'\n' ; 
    }
    cerr<<"\n[Finished in "<<clock()<<"ms]\n";

}

// I'm old now 


