#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define NAME "dora"
const int TEST = 100 ; 
#define FOR(i,a,b) for(int i = a ; i<= b ; i++) 
ll rd(ll  a , ll b )
{
	return a+1LL*rand()%(b-a+1);
}
void create()
{
	ofstream cout(NAME".INP");
	cout<<rd(100,1230);
	cout.close();
}
int main()
{
	srand(time(0)); 
	// FOR(i,1,TEST)
	{
		create();
		system(NAME".exe") ; 
		system("temp.exe") ; 
		if(system("fc " NAME".OUT " "TEMP.OUT")!=0)
		{
			cout<<"WA";
			return 0 ;
		}
		else 
		{
			cout<<"AC";
		}
	}
}