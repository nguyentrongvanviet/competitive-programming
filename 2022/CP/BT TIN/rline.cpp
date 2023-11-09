#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =6e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
#define int long long 

struct range
{
    int l , r ; 

};
struct point
{
    int pos  ; 
    int t  ; 
    int id  ; 
};
int n ; 
bool cmp(point a,  point b )
{
    return (a.pos<b.pos)||(a.pos==b.pos&&a.t>b.t) ; 
}
vector<point>pos ; 
set<int>s ;
range a[N] ;  
int f[N] ;
void pho()
{
    for(int i= 1 ;i<=n;i++)
    {
        pos.pb({a[i].l,1,i}) ; 
        pos.pb({a[i].r,-1,i}) ; 
        f[i] =0;
    }
    int cnt = 0 ;
    sort(pos.begin(),pos.end(),cmp);
    int res= 0;  
    for(int i= 0 ;i<pos.size();i++) 
    {
        int x = pos[i].pos;
        int id=  pos[i].id; 
        int t = pos[i].t;   
        if(t==1)
        {  
            if(cnt>0)
            {
                res+=x-pos[i-1].pos; 
            } 
            if(cnt==1)
            {
                f[*s.begin()]+=x-pos[i-1].pos; 
            }
            cnt++; 
            s.insert(id) ; 
        }
        else 
        {   
            if(cnt>0)
            {
                res+=x-pos[i-1].pos; 
            }
            if(cnt==1)
            {
                f[*s.begin()]+=x-pos[i-1].pos; 
            }
            cnt--; 
            s.erase(id) ; 
        }
    } 
    int ans= inf ;  
    for(int i= 1 ;i<=n;i++)
    {
        ans=min(ans,f[i]) ; 
    }
    cout<<res-ans; 
} 
void inp()
{
    cin>> n  ; 
    for(int i= 1 ;i<=n;i++)
    {
        cin>>a[i].l>>a[i].r ;
    }
    pho();
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}