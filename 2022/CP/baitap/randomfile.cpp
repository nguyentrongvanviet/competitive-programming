#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back 
#define pk pop_back 
#define pii pair<int,int> 
#define X first 
#define Y second 

const int N =2e5+5 , oo = 1e9 ; 
const ll inf = 1e17 , cs = 330 , sm = 1e9+7 ; 

int n ; 

ll Ran(ll l , ll r)
{
	return l+rand()%(r-l+1);
}
void inp()
{ 
	
	int n = 10 ; 
	cout<<n<<" "<<3<<" ";
	for(int i=1;i<=n;i++)
	{
		cout<<Ran(1,1000)<<" "; 
	} 
}
void solve()
{
	
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0) ; 
//	freopen("i.txt","r",stdin) ;  
	freopen("i.txt","w",stdout) ; 
	int t = 1; 
	while(t--)
	{
		inp() ; 
		solve() ; 
	}
}
