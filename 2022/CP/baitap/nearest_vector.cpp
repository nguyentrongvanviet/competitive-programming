#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back 
#define pk pop_back 
#define pii pair<int,int>  
#define ld long double 
#define X first 
#define Y second
const  int N = 2e5+5 , oo =1e9 ; 
const ll inf = 1e17 , cs = 330 , sm = 1e9+7 ; 
int n ; 
vector<pair<long double,int>> v ;
	int x, y; 

void inp()
{
	cin>> n  ;
	for(int i=1 ;i<=n;i++)
	{
		int x ,y ; 
		cin>>x>>y; 
		v.pb({atan2(y,x),i});
	} 
	sort(v.begin(),v.end()) ;
	ld mi = 1000000;
	for(int i=0 ;i<n;i++)
	{
		ld tmp = (v[(i+1)%n].X-v[i].X) ;
		cout<<v[i].X<<endl; 
		// cout<<tmp<<endl;
		if(tmp<0)
		{
			tmp+=2*acos(-1);
		}
		if(tmp<mi)
		{
			mi=tmp ;
			x = v[i].Y ; 
			y= v[(i+1)%n].Y ;  
		}
	}
	cout<<x<<" "<<y;
}
int main()
{
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	freopen("i.txt","r",stdin) ;  
	freopen("o.txt","w",stdout) ; 
	inp() ; 

}