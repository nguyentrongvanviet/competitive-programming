#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
typedef vector<ll> vll;
typedef vector <vll> vvll;
typedef pair <ll,ll> pll;
typedef vector <pll> vpll;
 #define TASK "SHLGOOD"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back
#define sep '#'
#define forl(i,k,n) for(ll i=k;i<n;i++)
#define MOD 1000000007 //10^9 + 7
#define all(x) x.begin(),x.end()
#define VALUE(x) cout << #x << " : " << x << '\n' 

// C++ template to print container elements 
template <typename T, typename S> 
ostream& operator<<(ostream& os, const pair<T, S>& v) { 
    os << '('<< v.first <<' '<< v.second<<')';
    return os; 
} 
template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) { 
    int cnt=0;
    for (auto it : v)  
    {    cnt != v.size()-1? os << it << ' ':os << it; cnt++;}            
    return os;  
} 
template <typename T> 
ostream& operator<<(ostream& os, const set<T>& v) {     
    int cnt=0;
    for (auto it : v)  
    {    cnt != v.size()-1? os << it << ' ':os << it; cnt++;}            
    return os;  
} 
template <typename T, typename S> 
ostream& operator<<(ostream& os, const map<T, S>& v) { 
    int cnt=0;
    for (auto it : v)  
    {    cnt != v.size()-1? os << it << ' ':os << it; cnt++;}            
    return os;  
} 
template <typename T, typename S> 
ostream& operator<<(ostream& os, const unordered_map<T, S>& v) { 
    int cnt=0;
    for (auto it : v)  
    {    cnt != v.size()-1? os << it << ' ':os << it; cnt++;}            
    return os;  
} 

//templated functions to print vector and for doing something like this print(a,b,c...)
template<typename T>
void print(T var1)
{   cout<<var1<<'\n';}
template<typename T,typename... Types>
void print(T var1,Types...var2)
{   cout<<var1<<' ';print(var2...); }

//templated functions to take Max or min of any no of elements
template<typename T>
T Max(T x)
{   return x; }
template<typename T,typename... Types>
T Max(T var1,Types...var2)
{   return var1>=Max(var2...)?var1:Max(var2...); }

template<typename T>
T Min(T x)
{   return x; }
template<typename T,typename... Types>
T Min(T var1,Types...var2)
{   return var1<=Min(var2...)?var1:Min(var2...); }

ll INF = 1000000000000000005LL;

void solve(); 
int main() { 
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1; 
    //cin>>t; 
    while(t--){
        solve();     
    } 
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs\n";return 0; 
} 


void preprocess
    (
        vll &a,
        vll &right_adj_big_cnt,
        vll &right_small_cnt,
        vll &right_big_cnt,
        ll n
    )
{
    stack<ll>s1,s2,s3;

    forl(i,0,n)
        right_adj_big_cnt[i] = n-i-1;

    forl(i,0,n)
    {
        ll top1=0,top2=0,top3=0;

        if(!s1.empty())
            top1 = s1.top();

        while(a[top1]>a[i] && !s1.empty())
        {
            right_adj_big_cnt[top1] = i-top1-1;
            right_small_cnt[top1] = n-i;
            s1.pop();
            s2.push(top1);
            if(!s1.empty())
                top1 = s1.top();
        }

        if( !s2.empty() )
            top2 = s2.top();

        while(!s2.empty() && a[i]>a[top2])
        {
            right_small_cnt[top2] = i-top2-1 - right_adj_big_cnt[top2];
            right_big_cnt[top2] = n-i;
            s2.pop();
            s3.push(top2);
            if(!s2.empty())
                top2 = s2.top();
        }

        if( !s3.empty() )
            top3 = s3.top();

        while(!s3.empty() && a[i]<a[top3])
        {
            right_big_cnt[top3] = i-top3-1 - right_adj_big_cnt[top3]-right_small_cnt[top3];         
            s3.pop();
            if(!s3.empty())
                top3 = s3.top();
        }

        s1.push(i);
            
    }


}
void solve() 
{
    // if(fopen(INPUT,"r"))
    // {
    //     freopen(INPUT ,"r",stdin) ;
    //     freopen(OUTPUT,"w",stdout);
    // }
    // else if(fopen("text.INP","r"))
    // {
    //     freopen("text.INP","r",stdin) ; 
    //     freopen("text.ANS","w",stdout) ;   
    // }
    ll n,ans=0;
    cin>>n;
    vll a(n),a_rev(n,0);
    vll right_adj_big_cnt(n,0);
    vll right_big_cnt(n,0);
    vll right_small_cnt(n,0);
    vll left_adj_big_cnt(n,0),left_adj_big_cnt_rev(n,0);
    vll left_small_cnt(n,0),left_small_cnt_rev(n,0);
    vll left_big_cnt(n,0);vll left_big_cnt_rev(n,0);
    forl(i,0,n)cin>>a[i];
    forl(i,0,n)a_rev[i] = a[n-i-1];
    preprocess(a,right_adj_big_cnt,right_small_cnt,right_big_cnt,n);
    preprocess(a_rev,left_adj_big_cnt_rev,left_small_cnt_rev,left_big_cnt_rev,n);
    forl(i,0,n)
    {
        left_small_cnt[i] = left_small_cnt_rev[n-i-1];
        left_adj_big_cnt[i] = left_adj_big_cnt_rev[n-i-1];
        left_big_cnt[i] = left_big_cnt_rev[n-i-1];
    }
    ans=0;
    forl(i,0,n)
    {
        ll ans1=0,ans2=0,ans3=0,ans4=0,ans5=0;
        if(right_adj_big_cnt[i]+1<=right_small_cnt[i])
        {
            ll val1 = right_adj_big_cnt[i]+1;
            ll val2 = min(right_adj_big_cnt[i]+left_adj_big_cnt[i]+1,right_small_cnt[i]-1);
            if(val2>=val1)
                ans1 = (val2-val1)+1;
            ll rem = right_small_cnt[i]-1-right_adj_big_cnt[i];
            if(rem>=0)
            {
                val1 = rem - min(rem,right_big_cnt[i]);
                val2 = min(rem,left_adj_big_cnt[i]);
                if(val2>=val1)
                    ans2 = val2-val1+1;
            }           
        }
        if(left_adj_big_cnt[i]+1<=left_small_cnt[i])
        {
            ll val1 = left_adj_big_cnt[i]+1;
            ll val2 = min(right_adj_big_cnt[i]+left_adj_big_cnt[i]+1,left_small_cnt[i]-1);
            if(val2>=val1)
                ans3 = (val2-val1)+1;
            ll rem = left_small_cnt[i]-1-left_adj_big_cnt[i];
            if(rem>=0)
            {
                val1 = rem - min(rem,left_big_cnt[i]);
                val2 = min(rem,right_adj_big_cnt[i]);
                if(val2>=val1)
                    ans4 = val2-val1+1;
            }
        }
        if(1+right_adj_big_cnt[i]+left_adj_big_cnt[i]<=right_small_cnt[i]+left_small_cnt[i])
        {
            ll val1,val2;
            ll rem = right_small_cnt[i]+left_small_cnt[i] -1 - right_adj_big_cnt[i] - left_adj_big_cnt[i];
            rem = 1+right_adj_big_cnt[i] + left_adj_big_cnt[i];
            
            val1 = rem - min(rem-1,right_small_cnt[i]);
            val2 = min(rem-1,left_small_cnt[i]);
            if(val2>=val1)
                ans5 = val2-val1+1;
        }   
        ans= ans+ans1+ans2+ans3+ans4+ans5;
    }
    print(ans);
} 
