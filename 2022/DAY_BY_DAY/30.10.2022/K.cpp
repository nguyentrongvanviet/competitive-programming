#include<bits/stdc++.h>
using namespace std;

#define TASK "K"

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

int n ; 
ll mod = 1e9+7;
string l ,r ;  
ll mu[N],R[N];
void doc()
{	
    cin>>l>>r ; 
    int n = r.size() ; 
    mu[0] =1 ; 
    for(int i =1 ;i<=n;i++)mu[i] = mu[i-1]*9%sm;
    R[0]=r[0]-'0';
    for(int i= 1 ;i <r.size();i++)
    {
    	R[i] = R[i-1]*(r[i]-'0')%mod;
    }
    // for(int i=0;i<r.size();i++) cout<<mu[i]<<" ";
    // cout<<endl;
    ll res =mu[r.size()-1];
    for(int  i= 1  ;i<r.size();i++)
    {
    	if(r[i-1]>l[i-1])
    	{
    		ll u = (r[i]-'0')*(r[i-1]-'0');
    		ll v = (r[i-1]-'0'-1)*9;
    		// cout<<u<<" "<<v<<endl;
    		if(v>u)
    		{	
    			if(i==1) res = max(res,(1*v)%mod*mu[r.size()-i-1]%mod);
    			else res = max(res,(R[i-2]*v)%mod*mu[r.size()-i-1]%mod);
    			cout<<res<<endl;
    			return;
    		}
    	}
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