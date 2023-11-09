#include<bits/stdc++.h>
using namespace std;

#define TASK "sseq"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#pragma CPP target("popcnt")
const int N =1e6+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
const int GH = 1e6 ;
struct R 
{
	int l , r  ; 
	ll val ; 
    bool operator<(const R&a)const
    {
        return r<a.r;
    }
};
int n ;
vector<int>q;
R a[N] ;
ll st[8*N] , lazy[8*N] ;   
void dolazy(int id )
{
    st[id]+= lazy[id]; 
    lazy[id*2]+=lazy[id] ; 
    lazy[id*2+1]+=lazy[id] ; 
    lazy[id]= 0 ;
}
void up(int id , int l , int r, int t , int p ,ll val )
{
    dolazy(id) ;
    if(t<=l&&r<=p)
    {
        st[id] +=val; 
        lazy[id*2]+=val ; 
        lazy[id*2+1]+=val;
        return ; 
    }
    if(r<t||p<l)return  ;
    int mid =(l+r)/2 ;
    up(id*2,l,mid,t,p,val) ; 
    up(id*2+1,mid+1,r,t,p,val) ; 
    st[id] = min(st[id*2],st[id*2+1]) ; 
}
ll get(int id , int l, int r,  int t , int p)
{   
    dolazy(id) ; 
    if(t<=l&&r<=p)
    {
        return st[id] ; 
    }	
    if(r<t||p<l)return inf ; 
    int mid =(l+r)/2;
    return min(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p));
}
void doc()
{
	cin>> n ;
	FOR(i,1,n)cin>>a[i].l>>a[i].r>>a[i].val;     
    sort(a+1,a+n+1) ; 
    FOR(i,1,n)q.pb(a[i].r) ; 
    q.resize(unique(q.begin(),q.end())-q.begin());
    int it = 1 ;
    ll res= 0 ; 
    ll tmp  = 0 ;
    for(int value : q)
    {
        while(a[it].r==value&&it<=n)
        {
            tmp+=a[it].val;
            up(1,1,GH,a[it].l,GH,a[it].val) ; 
            ++it;
        }
        res=max(res,tmp);
        res=max(res,tmp-get(1,1,GH,1,value));
    }
    cout<<res;
}
int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}