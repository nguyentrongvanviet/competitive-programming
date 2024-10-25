#include<iostream>
#include<fstream>
using namespace std ;


int main()
{
	for(int i=0;i<256;i++)
	{
		cout<<i<<" "<<char(i)<<endl;
	}
	int k; cin>> k; 
	char c ; cin>>c ; 
	cout<<char('A'+(c+k-'A')%26)<<endl ;

}