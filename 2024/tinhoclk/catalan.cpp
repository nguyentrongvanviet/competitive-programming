#include<bits/stdc++.h>
using namespace std ; 
string bracket ; 
const long long sm = 1e9+7 ; 
const int N = 2e5+5 ;  
vector<vector<long long >> fk,fk_1 ;
int n  , k;
int a[N] ; 
void add(long long &a , long long b)
{
    a+=b; 
    if(a>=sm)a-=sm ;
}
void sub(long long &a , long long b)
{
    a-=b; 
    if(a<0)a+=sm; 
}
long long tinh(int pos , int sum , int k , vector<vector<long long>>&f)
{
    if(sum<0||sum>k)return 0 ; 
    if(pos==n+1)return sum==0; 
    long long &val = f[pos][sum] ; 
    if(val!=-1)return val; 
    return val=(3*tinh(pos+1,sum+1,k,f)+tinh(pos+1,sum-1,k,f))%sm ;
}
void func1()
{
    fk.resize(n+2,vector<long long>(k+2,-1)) ; 
    fk_1.resize(n+2,vector<long long>(k+2,-1)) ;
    int sum = 0 , ok = 0 ;
    long long pos = 1 ; 
    for(int i=1;i<=n;i++)
    {
        for(int j=-3;j<min(0,a[i]);j++)
        {
            add(pos,tinh(i+1,sum+1,k,fk));
            if(sum+1!=k&&ok==0)
                sub(pos,tinh(i+1,sum+1,k-1,fk_1));
        }
        if(a[i]<0)
        {
            add(pos,tinh(i+1,sum-1,k,fk)) ;
            if(ok==0)
                sub(pos,tinh(i+1,sum-1,k-1,fk_1)) ;
        }
        if(a[i]<0)sum++ ;   
        else sum-- ; 
        ok|=(sum==k) ; 
    }   
    // for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    // cout<<endl;
    cout<<pos ;
}
void func2()
{
    exit(-1) ; 
}
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;
    }
    cin>> bracket ;  
    int sum = 0 ;
    map<char,int> num ={{'(',-3},{'[',-2},{'{',-1},{')',0},{']',1},{'}',2}} ; 
    for(auto x : bracket)
    {
        a[++n] = num[x] ; 
        if(a[n]<0)++sum ; 
        else --sum ;
        k=max(k,sum) ;      
    } 
    if(n<=1e3)func1() ; 
    else func2() ;
    cerr<<"ok" ;
    return 0 ;
}