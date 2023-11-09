#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n   ,q ;
multiset<int> l , r ; 
void input()
{

 	cin>> q; 
 	int n = 0 ;
 	for(int i=1 ;i<=q;i++)
 	{
 		string s; 
 		cin>> s; 
 		if(s=="IN")
 		{
 			int u ;  
 			cin>> u ;
 			++n; 
 			if(l.empty())
 			{
 				l.insert(u) ; 
 				continue ; 
 			}
 			else if(r.empty()&&*l.rbegin()<=u) 
 			{
 				r.insert(u);
 			}
 			else if(!l.empty()&&u<=*l.rbegin()){l.insert(u);}
 			else
 			{
 				r.insert(u);
 			}
 			while(l.size()<r.size())
 			{
 				l.insert(*r.begin()) ; 
 				r.erase(r.find(*r.begin())) ; 
 			}
 			while(l.size()>r.size()+1)
 			{
 				r.insert(*l.rbegin());
 				l.erase(l.find(*l.rbegin())) ; 
 			}
 		}
 		else if(s=="OUT")
 		{
 			--n; 
 			int u;
 			cin>> u ; 
 			if(l.find(u)!=l.end())
 			{
 				l.erase(l.find(u));
 				if(l.size()<r.size())
 				{
 					l.insert(*r.begin()) ;
 					r.erase(r.find(*r.begin()));
 				}
 			}
 			else  
 			{
 				r.erase(r.find(u)) ; 
 				while(l.size()>r.size()+1)
	 			{
	 				r.insert(*l.rbegin());
	 				l.erase(l.find(*l.rbegin())) ; 
	 			}
 			}
 		}
 		else
 		{
 			if(n&1)
 			{
 				cout<<*l.rbegin()<<"\n";
 			}
 			else 
 			{
 				cout<<(double)(*l.rbegin()+*r.begin())*0.5<<"\n";
 			}
 		}
 	}   
}
void output()
{
    
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}