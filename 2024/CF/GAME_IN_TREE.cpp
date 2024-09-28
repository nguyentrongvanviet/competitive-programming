    /***************************************************************
    *             Author : Nguyen Trong Van Viet                   *
    *                        Age : 17                              *
    *      School : 12T2 Le Khiet High School for the Gifted       *
    *            Hometown :  Quang Ngai , Viet Nam .               *
    * Khanh An is my lover :) the more I code  , the nearer I am   *
    ****************************************************************/
    #define TASK "text"
    #define INPUT TASK".INP" 
    #define OUTPUT TASK".OUT"

    bool mtt = 1 ;
    int test = 1 ;  

    #include<bits/stdc++.h>
    using namespace std; 

    #define             ll  long long 
    #define             db  double 
    #define             ve  vector 
    #define             vi  vector<int>
    #define            vll  vector<ll>
    #define            str  string
    #define             pb  push_back
    #define             pk  pop_back
    #define             el  '\n'
    #define            pii  pair<int,int>
    #define            pll  pair<ll,ll>
    #define             mp  make_pair 
    #define             fi  first 
    #define             se  second
    #define         uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin()) 
    #define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
    #define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
    #define    FORN(i,a,b)  for(int i=(int)(a);i<(int)(b);i++)
    #define         all(a)  a.begin(),a.end()  
    #define           btpc  __builtin_popcountll
    #define             LB  lower_bound
    #define             UB  upper_bound 
    #define            tct  template<class T>
    #define     BIT(msk,i)  (msk>>(i)&1)

    ll lg(ll a){return __lg(a);}
    ll sq(ll a){return a*a;}  
    ll gcd(ll a,ll b){return __gcd(a,b);} 
    ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
    ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}

    #define prt(a,n) FOR(i,1,n)cout<<a[i]<<" ";cout<<el;
    #define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

    tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
    tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

    int xx[] = {0,0,-1,0,1}; 
    int yy[] = {0,-1,0,1,0};

    const db PI = acos(-1) , EPS = 1e-9;
    const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
    const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

    int n; 
    vi g[N] ; 
    int s ,t ; 
    void doc()
    {
        cin>> n; 
        FOR(i,1,n-1)
        {
            int u ,v ; cin>> u >> v; 
            g[u].pb(v) ;
            g[v].pb(u) ; 
        }
        cin>> s >> t ;
    }

    namespace sub1
    {
        vector<int>node ; 
        bool dfs(int u ,int p)
        {
            if(u==s)
            {
                node.push_back(u) ;
                return 1 ; 
            }
            for(auto v:g[u])if(v!=p)
            {
                if(dfs(v,u))
                {
                    node.push_back(u) ; 
                    return 1 ; 
                } 
            }
            return 0 ; 
        }   
        int dd[N] ; 
        int ma[N] ; 
        void DD(int u ,int p)
        {
            ma[u] = 0 ; 
            for(auto v :g[u])if(v!=p&&dd[v]==0)
            {
                DD(v,u) ;
                ma[u] = max(ma[u],ma[v]+1) ; 
            }
        }
        void xuly()
        {
            dfs(1,0) ;
            reverse(all(node)) ; 
            for(auto u : node)
            {
                dd[u] = 1;               
            }
            vector<int>value ; 
            for(auto u : node)
            {
                DD(u,0) ;         
                value.push_back(ma[u]) ; 
            }
            multiset<int>s1 , s2 ;
            for(int i=0;i<value.size();i++)
            {
                if(i!=value.size()-1)s1.insert(value[i]+i);
                if(i!=0)s2.insert(value[i]+value.size()-1-i) ; 
            }
            int turn = 0 ;
            int l =0 ;
            int r = value.size()-1 ;
            while(l<r)
            {
                if(turn == 0 )
                {
                    if(value[l]+l>*(s2.rbegin()))
                    {
                        cout<<"Alice"<<el;
                        break;
                    } 
                    else
                    {
                        if(l+1==r)
                        {
                            cout<<"Bob"<<el;
                            break;
                        }
                        s1.erase(s1.find(value[l]+l)) ; 
                        ++l; 
                        s2.erase(s2.find(value[l]+value.size()-1-l)) ; 
                    }
                }
                else
                {
                    if(value[r]+value.size()-1-r>=*(s1.rbegin()))
                    {
                        cout<<"Bob"<<el; 
                        break; 
                    } 
                    else
                    {
                        if(r-1==l)
                        {
                            cout<<"Alice"<<el; 
                            break;
                        }
                        s2.erase(s2.find(value[r]+value.size()-1-r)) ;
                        --r;
                        s1.erase(s1.find(value[r]+r)); 
                    }
                }
                turn = 1-turn ; 
            }
            node.clear() ; 
            FOR(i,1,n)ma[i]=dd[i]=0,g[i].clear() ; 
        }
    }

    /*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

    signed main()
    {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
        if(fopen(INPUT,"r"))
        {
            freopen(INPUT ,"r",stdin);
            freopen(OUTPUT,"w",stdout);
        }
        if(mtt)cin>>test;

        FOR(i,1,test)
        {
            doc() ; 
            sub1::xuly() ; 
        }
        cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
    }