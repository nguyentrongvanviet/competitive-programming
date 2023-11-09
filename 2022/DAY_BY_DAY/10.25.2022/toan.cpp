#include<bits/stdc++.h>
using namespace std;

#define TASK "LCA"

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

void doc()
{
	int res=0  ; 
 	for(int i =100;i<=999;i++)
 	{
 		if(i%5==0)continue ;
 		int x= i ;
 		vector<int>dd(10,0);  
 		int ok = 1; 
 		int su =0;
 		while(x)
 		{
 			if(dd[x%10])ok=0 ;
 			dd[x%10]=1;
 			su+=x%10;
 			x/=10; 
 		} 
 		res+=(ok&&su%3==0);
 		// if(ok)cout<<i<<" ";
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