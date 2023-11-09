#include<bits/stdc++.h>
using namespace std;

#define TASK ""
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
const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n ; 
int a[N],f[N],s[N] ; 
ll ans= 0 ;
struct bg  
{
    int h, id;  x
};
bg c[1000005];
int mi[N] , ma[N] ; 
bool cmp(bg x,bg y)
{
    if(x.h==y.h) return x.id>y.id;
    else return x.h<y.h;
}
// vector<int> a ;


void doc()
{
 	cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        c[i]={a[i],i};
    }   
    sort(c,c+n+1,cmp);
    mi[0] = oo ;    
    FOR(i,1,n)
    {
        mi[i] = min(mi[i-1],c[i].id);
    }
    ma[n+1]=-oo ; 
    FORD(i,n,1)
    {
        ma[i] =max(ma[i+1],c[i].id);
    }
    int res= -1 ;  
    FOR(i,1,n-1)
    {
        res=max(res,ma[i+1]-mi[i]);
    }
    cout<<res;
}

int main()
{
    // fast 
    // if(fopen(TASK".INP","r"))
    // {
    //     freopen(TASK".INP","r",stdin); 
    //     freopen(TASK".OUT","w",stdout); 
    // }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}