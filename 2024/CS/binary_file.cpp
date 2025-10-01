#include<iostream>
#include<fstream>
using namespace std ;



signed main()
{

	int n=4;
	int a[] = {1, 2, 3, 4};
	ofstream fout;
	fout.open("text.bin", ios::binary);
	if (fout.is_open()) {
		for(int i=0;i<4;i++)
		{
			fout.write((char*)&a[i],4) ; 

		}
		// fout.write((char*)&n, 4);
	}
	fout.close() ; 
	ifstream fin("text.bin",ios::binary); 
	int b[5] ; 
	fin.read((char*)b,n*4) ; 
	for(int i=0;i<4;i++)
	{
		cout<<b[i]<<" " ;
	}
	cout<<endl;
	fout.close();	
}