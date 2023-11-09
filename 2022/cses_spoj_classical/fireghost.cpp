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

int n ; 
ll a[N],b[N] ; 
vector<ll>u ; 
vector<ll>v;  
void inp()
{
    u.clear() ; 
    v.clear() ; 
    cin>> n ; 
    for(int i= 1;i<=n;i++)cin>>a[i] ; 
    ll s= 0 ;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i] ; 
        s+=b[i]*2; 
        if(a[i]==1)
        {
            u.pb(b[i]) ; 
        }
        else 
        {
            v.pb(b[i]) ; 
        }
    }
    if(u.size()==0)
    {
        cout<<s/2<<"\n"; 
        return ;  
    }
    else if(v.size()==0)
    {
        cout<<s/2<<"\n"; 
        return ; 
    }
    sort(u.begin(),u.end() ); 
    sort(v.begin(),v.end()) ;
    if(u.size()==v.size())
    {
        cout<<s-min(u[0],v[0])<<"\n"; 
        return ; 
    } 
    if(u.size()>v.size())
    {
        swap(u,v); 
    }
    for(int i=0;i<v.size()-u.size();i++)
    {
        s-=v[i] ;    
    }
    cout<<s<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int test ;
    cin>>test; 
    while(test--)inp();
    return 0;
}