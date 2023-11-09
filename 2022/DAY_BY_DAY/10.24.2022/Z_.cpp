#include<bits/stdc++.h>
using namespace std;
#define TASK 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =2e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n ; 
string s ;

vector<int> z_function(string s) {
	int n = (int) s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min (r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}
void doc()
{
 	string s;  
 	cin>>  s;	
 	n =s.size();
 	s="#"+s ;
 	vector<int>z=Z_(s,n); 
 	for(int i= 0 ;i<z.size();i++)
 	{
 		cout<<z[i]<<" ";
 	}
 	// vector<int>q ; 
 	// for(int i=1 ;i<=n;i++)
 	// {	
 	// 	q.pb(z[i]); 
 	// }	
 	// int m ; cin>> m;  
 	// while(m--)
 	// {
 	// 	int l ; cin>> l ; 
 	//  	int id = upper_bound(all(q),l)-q.begin();
 	//  	cout<<id<<"\n";
 	// }
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