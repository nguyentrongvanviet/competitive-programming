#include<iostream> 
using namespace std ; 


int main()
{
	// "81276487126487126484"
	string NUMBER 
	cin>> NUMBER ;  
	int sum = 0 ; 
	// '8'-'0' 
	int mi = 9 ; 
	int ma = 0 ; 
	for(auto c : NUMBER)
	{
		sum+=c-'0' ;
		mi = min(mi,c-'0') ; 
		ma = max(ma,c-'0') ; 
	}
	cout<<sum<<endl;
}