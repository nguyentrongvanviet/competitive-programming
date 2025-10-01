#include<bits/stdc++.h>
using namespace std ;
#define ll long long 

const int tier = 2 ; 
signed main()
{
	srand(time(0)) ; 
	vector<string> ten[tier] ; 
	for(int i=0;i<tier;i++)
	{
		cout<<"TIER "<<i+1<<endl; 
		while(1)
		{
			string s ; cin>>s ; 
			if(s=="0")
			{
				break; 
			}
			ten[i].push_back(s) ;
		}
	}
	random_shuffle(ten[0].begin(),ten[0].end()) ; 
	random_shuffle(ten[1].begin(),ten[1].end()) ; 
	int first = ten[0].size()/2 ; 
	cout<<"TEAM "<<1<<endl; 
	for(int j=0;j<first;j++)
	{
		cout<<ten[0].back()<<" ";
		ten[0].pop_back() ; 
	}
	for(int j=0;j<5-first;j++)
	{
		cout<<ten[1].back()<<" ";
		ten[1].pop_back() ;
	}
	cout<<"TEAM "<<2<<endl; 
	for(auto x :ten[0])
	{
		cout<<x<<" ";
	}
	cout<<endl; 
	for(auto x: ten[1])
	{
		cout<<x<<" "; 
	}
	cout<<endl; 
}