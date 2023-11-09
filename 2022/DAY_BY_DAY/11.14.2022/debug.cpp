#include<bits/stdc++.h>
using namespace std;

#define TASK "div"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#pragma CPP target("popcnt")
const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
const int TEST = 100; 

ll rd(ll l , ll r )
{
	return l+1LL*rand()%(r-l+1);
}
void doc()
{
	ofstream cout(TASK".INP") ;
	int n = 1; 
	cout<<n<<"\n";
	FOR(i,1,n)
	{
		int l = rd(0,10);
		int r = rd(l,100);
		cout<<l<<" "<<r<<"\n";
	}
	cout.close() ;
}

int main()
{
	srand(time(0)); 
	FOR(i,1,TEST)
	{
		doc(); 

		system(TASK"_trau.exe") ; 
		system(TASK".exe") ; 

		if(system("fc " TASK ".ANS " TASK".OUT" )!=0)
		{
			cout<<"TEST "<<i<<" WA"<<"\n";
			return  0 ;
		}
		else 
		{
			cout<<"TEST "<<i<<" AC"<<"\n";	
		}
	}
}