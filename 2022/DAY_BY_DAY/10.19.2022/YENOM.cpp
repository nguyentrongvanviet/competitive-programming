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

int n  ,T ;

void input()
{	
	cin>> n >> T;
	vector<int>f(T+1,0);
	vector<int>a(n+1,0);
	for(int i=0 ;i<n;i++)
	{
		cin>>a[i] ;  
	}
	sort(a.begin(),a.end());
	// a.resize(unique(a.begin(), a.end()) - a.begin());
	f[0]=1  ;
	for(int i=1 ;i<=T;i++)
	{
		for(int j= 0 ;j <a.size();j++)
		{
			int u = a[j]; 
			if(i-u>=0&&f[i-u]==1)
			{
				f[i] =1 ; 
				break ;
			}
		}
	}
	ll res=0  ;
	for(int i=0;i<=T;i++)
	{
		cout<<f[i]<<" ";
		res+=f[i]==1 ; 
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