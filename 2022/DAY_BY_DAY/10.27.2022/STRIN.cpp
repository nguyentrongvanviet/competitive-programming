#include<bits/stdc++.h>
using namespace std;

#define TASK "STRIN"

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
ll f[N][5];
void doc()
{	
   	cin>> n;  
   	f[1][0]=f[1][1]=f[1][2]=1; 
   	for(int  i=2 ;i<=n;i++)
   	{
   		f[i][0]=f[i-1][1]+f[i-1][2]+f[i-1][0];
   		f[i][1] =f[i-1][2]+f[i-1][0] ; 
   		f[i][2] =f[i-1][1]+f[i-1][2]+f[i-1][0]; 
   		f[i][1]%=sm; 
   		f[i][0]%=sm; 
   		f[i][2]%=sm;
   	}
  	cout<<(f[n][1]+f[n][2]+f[n][0])%sm;
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