#include<bits/stdc++.h>
using namespace std;

#define TASK ""

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
const ll sm = 998244353,cs=330 ,inf = LLONG_MAX;

int n ; 
int mi = oo;  
int a[N] ; 
void doc()
{
 	cin>> n;  
 	for(int i=1 ;i<=n;i++)cin>>a[i] ,mi =min(mi,a[i]) ; 
 	for(int i=1 ;i<=n;i++)
 	{
 		
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