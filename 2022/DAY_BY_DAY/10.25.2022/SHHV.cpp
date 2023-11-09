#include<bits/stdc++.h>
using namespace std;

#define TASK "CH"

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

int n   ; 
ll x; 
int a[N] ;
ll fac[N];
void doc()
{
	int u ;
 	while(cin>>u)
 	{
 		a[++n] =u; 
 	} 
 	x=a[n];
 	n-=1;  
}
int dd[123];
void xuly()
{
	fac[0] =1;  
	for(int i= 1 ;i<=n;i++)
	{
		fac[i] =fac[i-1]*i; 
	}
	ll res =0 ;
	for(int i=1 ;i<=n;i++)
	{
		int cnt =0  ;
		for(int j= 1;j<a[i];j++)
		{
			if(dd[j]==0)
			{
				cnt++ ;
			}
		}
		dd[a[i]]=1;
		res+=cnt*fac[n-i];
	}
	cout<<res+1<<"\n";
	x--;
	for(int i=1;i<=n;i++)dd[i]= 0;
	for(int i= 1;i<=n;i++)
	{
		for(int j= 1;j<=n;j++)
		{
			if(dd[j]==0)
			{
				if(fac[n-i]<=x)
				{
					x-=fac[n-i];
				}
				else 
				{
					cout<<j<<" ";
					dd[j]=1;
					break ;
				}
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
        xuly();
    }
    return 0;
}