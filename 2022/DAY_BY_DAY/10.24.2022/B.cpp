#include<bits/stdc++.h>
using namespace std;
#define TASK "B"
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =5e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n  ,x ;
int a[N]  ; 
int cnt[N]  ; 
void doc()
{
    cin>> n>>x ; 
    for(int i=1;i<=n;i++)
    {
    	cin>> a[i] ;
    	if(a[i]<x)cnt[a[i]]++; 
    }
    for(int i= 1; i<x;i++)
    {
    	if(cnt[i]%(i+1))
    	{
    		cout<<"No" ; 
    		return ; 
    	}
    	cnt[i+1]+=cnt[i]/(i+1);
    }
    cout<<"Yes";
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