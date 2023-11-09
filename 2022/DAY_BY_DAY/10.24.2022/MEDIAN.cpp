#include<bits/stdc++.h>
using namespace std;
#define TASK "MEDIAN"
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second

#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =1e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;


int n , m ;
int node  =0 ;
pii p[20*N] ;  
int L[20*N] , R[20*N] ;
int  st[20*N] ;
int id[N] ;
void refine (int id )
{
    st[id]= st[L[id]]+st[R[id]];
}
int up(int c,  int l , int r,int pos,int val )
{
    ++node; 
    int cur = node ; 
    if(l==r&&l==pos)
    {    
        st[cur] = val;
        L[cur]= 0 ; 
        R[cur]= 0 ;
        return cur;
    }
    int mid =(l+r)>>1 ; 
    if(pos<=mid)
    {
        R[cur] = R[c] ;
        L[cur] = up(L[c],l,mid,pos,val); 
    }
    else 
    {
        L[cur] = L[c] ;
        R[cur]= up(R[c],mid+1,r,pos,val);
    }
    refine(cur) ;
    return cur; 
}
int get(int cur , int l , int r ,int t , int p )
{
    if(t<=l&&r<=p)return st[cur] ; 
    if(r<t||p<l)return 0 ; 
    int mid =(l+r)>>1; 
    return get(L[cur],l,mid,t,p)+get(R[cur],mid+1,r,t,p);
}
int a[N] ;
void doc()
{
    cin>> n>> m; 
    for(int i=1 ;i<=n;i++)cin>>a[i] ,p[i] ={a[i],i};
    sort(p+1,p+n+1);
    for(int i= 1;i<=n;i++)
    {
        id[i]=up(id[i-1],1,n,p[i].se,1);
    }   
    for(int i=1 ;i<=m;i++)
    {   
        int left , right ;  
        cin>>left>>right ; 
        int l =1 ;   
        int r = n ;
        int ans ;
        while(l<=r)
        {
            int mid =(l+r)/2; 
            int val = get(id[mid],1,n,left,right);
            if(val>=(right-left+2)/2)
            {
                r=mid-1 ;
                ans=mid;
            }
            else 
            {
                l=mid+1;
            }
        }
        cout<<a[p[ans].se]<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
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