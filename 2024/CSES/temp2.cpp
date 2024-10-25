#include<fstream>
using namespace std ;

signed main()
{
	ifstream IN ; 
	ofstream OUT ;
	IN.open("text.INP");
	OUT.open("text.OUT",ios::app) ; 
	if(OUT.is_open())
	{
		int A ; 
		IN>>A ; 
		OUT<<A+5;
	}
	OUT.close() ;  
}