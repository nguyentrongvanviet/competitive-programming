#include<bits/stdc++.h>
using namespace std;

#define TASK "bishop"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =2e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;
ll n , x,  y,  u , v ;

void doc()
{
 	cin>> n; 
 	cin>>x>>y>>u>>v ; 
    int a = ((x+y)%2==0); 
    in
    t b = ((u+v)%2==0);
    if(a!=b)
    {
        cout<<"no"; 
    }
    else
    {
        cout<<"yes";
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