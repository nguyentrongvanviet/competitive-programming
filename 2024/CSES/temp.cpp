#include<bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define vll vector<ll> 
#define PB push_back
ll mex(vll v)
{
    set<ll> s;
    for(int i=0;i<v.size();i++)
    {
        s.insert(v[i]);
    }
    for(int i=0;i<1000001;i++)
    {
        if(s.count(i)==0) return i;
    }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll limit=2000;
    ll dp[limit];
    dp[0]=dp[1]=dp[2]=0;
    for(int i=3;i<limit;i++)
    {
        vll v;
        for(int j=1;2*j<i;j++)
        {
            v.PB(dp[j]^dp[i-j]);
        }
        dp[i]=mex(v);
    }
    ll t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        ll n;
        cin>>n;
        if(n>=limit) cout<<"first";
        else if(dp[n]==0) cout<<"second";
        else cout<<"first";
        cout<<"\n";
    }
}