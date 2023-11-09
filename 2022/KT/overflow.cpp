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

struct bg 
{
    int val ;
    int pos ;   
    int id ; 
    
};
bool cmp(bg a , bg b )
{
    if(a.val==b.val)
    {
        return a.id<b.id; 
    }
    return a.val<b.val ; 
}
int n , m ; 
vector<bg>q ; 
int res[N] ; 
int a[N] , b[N] ;
void inp()
{
    cin>> n>> m ;
    for(int i= 1 ;i<=n;i++)
    {
        cin>>a[i] ;
        q.pb({a[i],i,1}) ;  
    }
    for(int i = 1 ;i<=m;i++)
    {
        cin>>b[i] ; 
        q.pb({b[i],i,2}) ; 
    }
    sort(q.begin(),q.end(),cmp) ; 
    vector<int>c; 
    for(int  i= q.size()-1;i>=0;i--)
    {
        if(q[i].id==1)
        {
            if(c.empty())
            {
                res[q[i].pos] = -1; 
            }
            else
            {
                res[q[i].pos] = c.back(); 
                c.pk();
            }
        }
        else
        {
            c.pb(q[i].pos); 
        }
    }
    for(int i= 1 ;i<=n;i++)
    {
        cout<<res[i]<<"\n"; 
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}