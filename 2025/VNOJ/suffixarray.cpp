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
ll gcd(ll a,ll b){return __gcd(a,b);} n
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};


const double PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e6+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

string a ; 
string b[N] ; 


struct SuffixArray {
    std::string s;
    int n;
    std::vector<int> sa, rank, lcp;

    SuffixArray(const std::string& _s) {
        s = _s + char(0); // Use char(0) as a unique sentinel
        n = s.length();
        sa.resize(n);
        rank.resize(n);
        lcp.resize(n);
        buildSA();
        buildLCP();
        // Adjust for the original string (remove sentinel info)
        n--; 
        sa.erase(sa.begin());
    }

private:
    void buildSA() {
        // Initial sort (k=0) by single characters
        std::iota(sa.begin(), sa.end(), 0);
        std::sort(sa.begin(), sa.end(), [&](int a, int b) {
            return s[a] < s[b];
        });

        // Compute initial ranks
        rank[sa[0]] = 0;
        for (int i = 1; i < n; ++i) {
            rank[sa[i]] = rank[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
        }

        // --- CORRECTED RADIX SORT LOGIC ---
        for (int k = 1; k < n; k <<= 1) {
            std::vector<int> p(n), c(n);
            std::vector<int> count(n, 0);

            // Create pairs for sorting based on (rank[i], rank[i+k])
            // p[i] will store the suffix index i, sorted by its second half
            for (int i = 0; i < n; ++i) p[i] = (sa[i] - k + n) % n;

            // Counting sort on the first halves (using p as the order)
            for (int i = 0; i < n; ++i) count[rank[p[i]]]++;
            for (int i = 1; i < n; ++i) count[i] += count[i-1];
            for (int i = n - 1; i >= 0; --i) sa[--count[rank[p[i]]]] = p[i];

            // Update ranks
            c[sa[0]] = 0;
            for (int i = 1; i < n; ++i) {
                int r_prev1 = rank[sa[i-1]];
                int r_prev2 = rank[(sa[i-1] + k) % n];
                int r_curr1 = rank[sa[i]];
                int r_curr2 = rank[(sa[i] + k) % n];
                c[sa[i]] = c[sa[i-1]] + (r_curr1 != r_prev1 || r_curr2 != r_prev2);
            }
            rank = c;
            if (rank[sa[n-1]] == n - 1) break; // Optimization
        }
    }

    void buildLCP() {
        int h = 0;
        for (int i = 0; i < n; ++i) {
            if (rank[i] == 0) continue; // rank of first suffix in sorted order is 0
            if (h > 0) h--;
            int j = sa[rank[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h]) {
                h++;
            }
            lcp[rank[i]] = h;
        }
        lcp.erase(lcp.begin()); // Remove LCP of sentinel
    }
};
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
    int n  ; cin>> n; 
    assert(n!=0);
    for(int i=1;i<=n;i++)
    {
        cin>>b[i] ; 
    }
    cin>>a ;    
    string s ; 
    s = a ;
    s+='#' ; 
    for(int i=1;i<=n;i++)
    {
        s+=b[i] ; 
        s+='#' ; 
    }
    SuffixArray s_array(s) ; 
    vector<int>res(s_array.n,1); 
    int lcs= 0 ; 
    bool exist = 0 ; 
    for(int i=1;i<s_array.n;i++)
    {
        if(exist)lcs=min(lcs,s_array.lcp[i]) ; 
        if(s_array.sa[i]<int(a.size()))
        {
            res[i] = lcs+1; 
        }   
        else
        {
            exist = 1 ; 
            lcs = 1e9 ; 
        }
    }
    exist = 0 ; 
    lcs = 0 ; 
    for(int i=s_array.n-1;i>=0;i--)
    {
        if(s_array.sa[i]<int(a.size()))
        {
            res[i] =  max(res[i],lcs+1) ; 
            if(exist)lcs = min(lcs,s_array.lcp[i]) ;    
        }
        else
        {
            exist = 1; 
            lcs = s_array.lcp[i] ; 
        }
    }
    int pos = -1 ; 
    for(int i=0;i<s_array.n;i++)
    {
        if(s_array.sa[i]<int(a.size()))
        {
            if((pos==-1||(res[pos]>res[i]))&&s_array.sa[i]+res[i]-1<a.size())
            {
                pos = i ; 
            }
        }
    }
    assert(pos!=-1) ; 
    cout<<a.substr(s_array.sa[pos],res[pos])<<'\n';
    cerr<<"\n[Finished in "<<clock()<<"ms]\n";

}

// I'm old now
