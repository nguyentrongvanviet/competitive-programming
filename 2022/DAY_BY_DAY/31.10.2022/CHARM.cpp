#include<bits/stdc++.h>
using namespace std;

#define TASK "HOLIDAY"

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

int n  , W ; 
int w[N] , d[N]  ;
int pre[N] , now[N] ; 
void doc()
{	
    cin>> n>>W;  
    for(int i= 1;i<=n;i++)cin>>w[i]>>d[i];
   	int res = 0  ;
    for(int i =1 ;i<=n;i++)
    {
    	for(int j=1;j<=W;j++)
    	{
    		now[j] = pre[j] ; 
    		if(j>=w[i])now[j] = max(now[j],pre[j-w[i]]+d[i]) ;
    	}	
    	for(int j= 1 ;j<=W;j++)
    	{
    		pre[j] = now[j]; 
    		res=max(res,now[j]);
    	}
    }
    cout<<res;
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