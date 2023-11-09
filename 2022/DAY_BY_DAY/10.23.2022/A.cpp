#include<bits/stdc++.h>
using namespace std;
#define TASK "A"
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =2e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n ; 

void doc()
{
    cin>> n; 
    int x= 0 ; 
    int q= 0  ; 
    for(int i=1;i<=n;i++)
    {
    	char x ; cin>>x ; 
    	if(x=='A')
    	{
    		q-- ; 
    		q=max(q,0) ; 
    	}
    	else 
    	{
    		q++ ;
    	}
    }
    if(q==0)cout<<"Yes\n";
    else cout<<"No\n";
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