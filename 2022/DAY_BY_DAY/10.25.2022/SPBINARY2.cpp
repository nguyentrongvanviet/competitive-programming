#include<bits/stdc++.h>
using namespace std;

#define TASK "SPBINARY2"

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
const ll sm = 1e9,cs=330 ,inf = LLONG_MAX;

int n , k ; 
ll s[N]  ,f[N]; 
void doc()
{
    cin>> n>> k;
   	s[0] = 1; 
  	f[1] = 1 ; 
  	s[1]= 2; 
   	for(int i=2;i<=n;i++)
   	{
   		f[i]  =(s[i-1]-(i-k-1<0?0:s[i-k-1])+sm)%sm;
   		s[i] = (s[i-1]+f[i])%sm;
   	}
   	// for(int i=1 ;i<=n;i++)cout<<f[i]<<" ";cout<<"\n";
    cout<<2*f[n]%sm;
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