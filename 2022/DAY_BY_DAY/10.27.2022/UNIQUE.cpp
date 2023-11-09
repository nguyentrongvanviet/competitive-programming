	#include<bits/stdc++.h>
	using namespace std;

	#define TASK "UNIQUE"

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
	int a[N] ;
	map<int,int>sl ; 
	void doc()
	{
	 	cin>> n;    
	 	for(int i =1 ;i<=n;i++)
	 	{
	 		cin>>a[i] ; 
	 		sl[a[i]]++;
	 	}
	 	for(auto it : sl)
	 	{
	 		int x = it.second ; 
	 		if(x==1)
	 		{
	 			for(int i=1 ;i<=n;i++)
	 			{
	 				if(a[i]==it.first)
	 				{
	 					cout<<i;
	 					return ; 
	 				}
	 			}
	 		}
	 	}
	 	cout<<-1; 
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