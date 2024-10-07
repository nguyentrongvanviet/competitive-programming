#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 
int n;  
int a[N] , b[N] ;
vector<int>pos[N] ;
#define FOR(i,a,b) for(int i=a;i<=b;i++) 
int st[4*N] ; 
void build(int id, int l, int r )
{
    if(l==r)
    {
        st[id] = a[l] ;
        return ; 
    }
    int mid =(l+r)>>1 ;
    build(id<<1,l,mid) ; 
    build(id<<1|1,mid+1,r) ; 
    st[id] = min(st[id<<1],st[id<<1|1]) ;
}
int get(int id ,int l, int r ,int t, int p)
{
    if(t<=l&&r<=p)return st[id] ; 
    if(r<t||p<l)return oo ; 
    int mid = (l+r)>>1 ;
    return min(get(id<<1,l,mid,t,p),get(id<<1|1,mid+1,r,t,p)) ; 
}
void up(int id, int l, int r ,int pos,int val)
{
    if(r<pos||pos<l)return ; 
    if(l==r)
    {
        st[id] = val; 
        return ; 
    }
    int mid = (l+r)>>1 ;
    up(id<<1,l,mid,pos,val) ;
    up(id<<1|1,mid+1,r,pos,val) ; 
    st[id] = min(st[id<<1],st[id<<1|1]) ; 
}
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int t ; cin>>t ; 
    while(t--)
    {
        cin>> n; 
        FOR(i,1,n)cin>>a[i] ; 
        FOR(i,1,n)cin>>b[i]; 
        for(int i=n;i>=1;i--)
        {
            pos[a[i]].push_back(i) ; 
        }
        build(1,1,n) ;
        bool ok = 0 ; 
        FOR(i,1,n)
        {
            if(pos[b[i]].empty())
            {
                ok = 1 ; 
                cout<<"NO"<<'\n' ; 
                break;
            }
            else
            {
                int t = pos[b[i]].back() ; 
                pos[b[i]].pop_back() ; 
                int val = get(1,1,n,1,t) ; 
                if(val<b[i])
                {
                    ok = 1 ; 
                    cout<<"NO"<<'\n';
                    break; 
                } 
                else
                {
                    up(1,1,n,t,oo) ;
                }
            }
        }       
        if(ok==0)cout<<"YES"<<'\n' ; 
        FOR(i,1,n)pos[i].clear() ; 
    }
}