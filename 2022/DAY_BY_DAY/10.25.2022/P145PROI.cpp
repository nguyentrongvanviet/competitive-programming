#include<bits/stdc++.h>
using namespace std;

#define TASK "P145PROI"

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

int n ; 
int s1[N],s2[N] , s3[N] ;
void doc()
{	
    string s ; cin>> s;
   	int n =s.size();
    s="#"+s; 
    ll res= 0 ;
    for(int i= 1;i<=n;i++)
    {
    	s1[i] = s1[i-1]+(s[i]>='0'&&s[i]<='9');
    	s2[i] =s2[i-1]+(s[i]>='A'&&s[i]<='Z') ; 
    	s3[i] =s3[i-1]+(s[i]>='a'&&s[i]<='z'); 
    	ll ans =0 ; 
    	ll l = 1 ; 
    	ll r= i-6+1; 
    	while(l<=r)
    	{
    		ll mid=(l+r)/2 ;
    		if(s1[i]-s1[mid-1]>0&&s2[i]-s2[mid-1]>0&&s3[i]-s3[mid-1]>0)
    		{
    			ans=mid ;
    			l=mid+1; 
    		}
    		else 
    		{
    			r=mid-1 ; 
    		}
    	}
    	res+=ans;	
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