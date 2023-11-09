#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

struct ra
{
    int l , r ,id; 
    bool operator < (ra x )
    {
        return l<x.l; 
    }
};
int n  , l , r ; 
ra a[N] ; 
vector<ra>res;  
void inp()
{
    cin>> n >>l>>r; 
    for(int i =1 ;i<=n;i++)
    {
        cin>>a[i].l>>a[i].r;  
        a[i].id=i; 
    } 
    sort(a+1,a+n+1) ; 
    a[0].r=-oo;
    ra ma{0,-oo,0};
    for(int i=1;i<=n;i++)
    {
        // cout<<a[ma].r<<endl;
        if(a[i].l>l)
        {
            if(ma.r<a[i].l)
            {
                cout<<-1; 
                return ; 
            } 
            l=ma.r; 
            res.pb(ma);
        }
        if(ma.r<a[i].r)
        {
            ma=a[i]; 
            if(a[i].r>=r)
            {
                res.pb(a[i]);
                cout<<res.size()<<"\n"; 
                for(auto v : res)   
                {
                    cout<<v.id<<" " ; 
                } 
                return ; 
            } 
        }
    }
    cout<<-1 ; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}