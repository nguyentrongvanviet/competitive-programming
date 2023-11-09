#include<bits/stdc++.h>
using namespace std;

#define TASK "SUBKGCD"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =3e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n , k ;
int a[N]  ; 
bool check(int value)
{
	for(int i= 1;i<=n;i++)
	{
		if(a[i]-a[i]/value*value>k)return 0 ;
	}
	return 1;  
}
void doc()
{	
    cin>> n>> k ; 
    for(int i= 1;i<=n;i++)
    {
    	cin>>a[i] ; 
    }
    sort(a+1,a+n+1) ; 
    for(int  value =a[1];value>=1;value--)
    {   
    	if(check(value))
    	{
    		cout<<value ; 
    		return ; 
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