#include<bits/stdc++.h>
using namespace std;
#define TASK "Baby_string"
#define ll long long 
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vi vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =2e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n ;
string s;  
vector<int>z;
vi z_function(string s )
{
	int n = s.size() ; 
	vi z(n);
	for(int i= 1,l = 0  , r=0;i<n;i++)
	{
		if(i<=r)
		{
			z[i] = min(r-i+1,z[i-l]);
		}
		while(i+z[i]<n&&s[i+z[i]]==s[z[i]])
		{
			++z[i] ;
		}
		if(r<i+z[i]-1)
		{
			r = i+z[i]-1;
			l = i ;
		}
	}
	return z; 
}
void doc()
{
	cin>> s  ;
	n =s.size();
	z = z_function(s); 
	z[0]= n ; 		
}
void sub()
{
	vector<int>q ; 
	for(int i= 0 ;i<n;i++)
	{
		q.pb(z[i]) ; 
	}
	sort(q.begin(),q.end());
	int m ; 
	cin>> m;
	while(m--)
	{
		int l ;  
		cin>> l ; 
		if(z[n-l]!=l)
		{
			cout<<"NO"<<"\n";
		}
		else 
		{
			int sl = lower_bound(q.begin(),q.end(),l)-q.begin();
			if(n-sl<3)
			{
				cout<<"NO"<<"\n";
				continue ;
			}
			cout<<"YES "<< n-sl<<"\n";
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
        sub();
    }
    return 0;
}