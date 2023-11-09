#include<bits/stdc++.h>
using namespace std;

#define TASK "mfish"

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

struct bg 
{
    int pos ; 
    int d ;
    bool operator<(const bg& a )const
    {
        return pos<a.pos;  
    }
};
int n  , m ;  
vector<int>g[N] ; 
ll s[N] ; 
ll a[N] ;  
bg x[N] ; 
ll f[N] ; 
void doc()
{
 	cin>> n ;  
 	for(int i=1 ;i<=n;i++)
 	{
 		cin>>a[i] ; 
 		s[i] =s[i-1]+a[i] ;
 	}   
 	cin>> m; 
 	for(int i= 1;i<=m;i++)
 	{
 		int b  ,d ; 
 		cin>>b>>d ;
        x[i] = {b,d} ; 
 	}	
    sort(x+1,x+m+1) ; 
 	f[0] = 0 ;
 	int j=  0 ; 
    for(int i=1 ;i<=n;i++)
 	{
 		f[i] =f[i-1] ;
        if(x[j+1].pos<=i&&j<m)
        {
            j++;
        }
        if(i-x[j].d>=x[max(0,j-1)].pos&& i-x[j].d+1<=x[j].pos)
        {
            f[i] =max(f[i],f[i-x[j].d]+s[i]-s[i-x[j].d]);
        }
        // cout<<j<<" "<<f[i]<<"\n";
 	}
 	cout<<f[n];
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