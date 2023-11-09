/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "BANK"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
#define pii pair<int,int>
#define vi vector<int> 
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
// hiensumi was here
void IOS()
{
    fast 
    srand(time(0)) ;
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n  ; 
int h ; 
int a[N] ;
ll s[N] ;
int st[4*N]; 
void build(int id , int l , int r  )
{
    if(l==r)
    {
        st[id] = a[l]; 
        return ; 
    }
    int mid =(l+r)/2; 
    build(id*2,l,mid) ; 
    build(id*2+1,mid+1,r) ;
    st[id]  = max(st[id*2],st[id*2+1]); 
}
int get(int id , int l, int r , int t, int p)
{
    if(t<=l&&r<=p)return st[id]; 
    if(r<t||p<l)return -oo; 
    int mid =(l+r)/2; 
    return max(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)); 
}
void doc()
{
    cin>>n >> h ;
    FOR(i,1,n)cin>>a[i] , s[i]=s[i-1]+a[i],a[i]-=i ; 
    // build(1,1,n);
    ll res= inf ; 
    deque<int>dq;
    FOR(i,1,n)
    {
        while(!dq.empty()&&a[dq.back()]<=a[i])dq.pk() ;
        dq.pb(i) ; 
        while(dq.front()<=i-h)dq.pop_front() ;
        if(i>=h&&a[dq.front()]+i-h+1<=1)
        {
            res=min(res,1LL*h*(h+1)/2-(s[i]-s[i-h]));
        }
    }
    FOR(i,1,n-h+1)
    {
        // cout<<i+1+get(1,1,n,i,i+h-1)<<endl;
        if(i+get(1,1,n,i,i+h-1)<=1)
        {
            // cout<<i<<endl;
            // cout<<i+1+get(1,1,n,i,i+h-1)<<endl;
            res=min(res,1LL*h*(h+1)/2-(s[i+h-1]-s[i-1]));
        }
    }    
    cout<<(res==inf?-1:res);
}
void xuly()
{
    cin>> n;    
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}