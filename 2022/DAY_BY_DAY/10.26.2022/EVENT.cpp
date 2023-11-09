#include<bits/stdc++.h>
using namespace std;

#define TASK "EVENT"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =1e6+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int  n  ,q ; 
ll a[N ] , s[N] ; 
ll c[N] , k[N] ; 
void doc()
{
 	cin>> n>> q ; 
 	for(int i= 1;i<=n;i++)cin>>a[i] ;
    sort(a+1,a+n+1,greater<ll>());
    for(int i= 1;i<=n;i++)
    {
        s[i] =s[i-1]+a[i] ; 
    }
    for(int i =1 ;i<=q;i++)
    {
        cin>>c[i]>>k[i]; 
    } 	   
}
void xuly()
{
    for(int i=1 ;i<=q;i++)
    {
        ll u = s[c[i]];
        cout<<u+s[c[i]/(k[i]+1)]<<"\n";
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
        xuly();
    }
    return 0;
}