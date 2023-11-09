#include<bits/stdc++.h>
using namespace std;

#define TASK "COUNTN"

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

ll a; 

void doc()
{
	cin>> a ;
	ll res= 0 ; 
 	for(int n=2;n<=(1e5);n++)
 	{
 		int val = a-(n-1)*n/2;
 		if(val<=0)break;
 		if(val%n==0)
 		{
 			res++; 
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