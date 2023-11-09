#include<bits/stdc++.h>
using namespace std;

#define TASK "ORDSET"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".ANS","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int q ; 
set<int>s ;
void doc()
{
	cin>>q;  
	FOR(i,1,q)
	{
		char t ; cin>>t ; 
		int val ; cin>>val ;
		if(t=='I')
		{
			if(s.find(val)==s.end())s.insert(val) ;
		}
		else if(t=='D')
		{
			if(s.find(val)!=s.end())s.erase(val) ; 
		}
		else if(t=='K')
		{
			int x = 0 ; 
			if(s.size()<val)
			{
				cout<<"Invalid"<<"\n";
				continue ;
			}
			for(auto value: s)
			{
				++x ; 
				if(x==val)
				{
					cout<<value<<"\n";
					break; 
				}
			}
		}
		else if(t=='C')
		{
			int res= 0 ;
			for(auto x : s)
			{
				if(x<val)
				{
					res++; 
				}
			}
			cout<<res<<"\n";
		}
	}
}
void xuly()
{
    
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}