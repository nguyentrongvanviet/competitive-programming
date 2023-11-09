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

int n ; 
ll res= 0 ;  
bool check(int val )
{
	while(val)
	{
		int la = val%10 ; 
		if(la>7)return 0 ; 
		val/=10;
	}
	return 1  ;
}
int ts (int val )
{
	return val+val%10+val/10%10;
}
void input()
{
	vector<int>q; 
 	for(int  i=10 ;i<=99;i++)
 	{
 		if(check(i))
 		{
 			cout<<i<<" ";
 			q.pb(i) ; 
 		}
 	}
 	for(int i= 0 ;i<q.size();i++)
 	{
 		for(int  j =i+1;j<q.size();j++)
 		{
 			for(int t =j+1;t<q.size();t++)
 			{
 				if((ts(q[i])+ts(q[j])+ts(q[t]))%100==0)
 				{
 					res++ ; 
 				}
 			}
 		}
 	}
 	cout<<res;
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