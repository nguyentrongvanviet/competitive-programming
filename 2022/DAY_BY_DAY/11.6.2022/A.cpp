#include<bits/stdc++.h>
using namespace std;

#define TASK "A"

#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b) for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i = b;i>=a;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n ; 
int a[N] ; 
void doc()
{
    cin>>n ; 
    for(int i= 1;i<=n;i++)
    {
    	cin>>a[i] ; 
    }
    if(a[1]==1)
    {
    	cout<<"Yes"<<"\n";
    }
    else 
    {
    	cout<<"No"<<"\n";
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
    cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}