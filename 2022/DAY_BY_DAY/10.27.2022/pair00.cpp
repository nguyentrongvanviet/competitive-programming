#include<bits/stdc++.h>
using namespace std;

#define TASK "pair00"

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
	string tmp = "1" ; 
	for(int i=1 ;i<=11;i++)
	{
		string ans ="" ; 
		for(int  j= 0 ;j<tmp.size();j++)
		{
			if(tmp[j]=='0')
			{
				ans+="10" ; 
			}
			else 
			{
				ans+="01";
			}
		}
		ll x= 0 ;
		for(int j=1;j<ans.size()-1;j++)
		{
			if(ans[j]=='0'&&ans[j-1]=='0')
			{
				x++;  
			}
		}
		cout<<x<<"\n";
		tmp =ans ;
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