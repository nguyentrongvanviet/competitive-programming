#include<iostream>
#include<fstream> 
#include<cstring> 
using namespace std ; 


struct student
{
	char studentID[8]; 
	char fullname[100] ; 
	char homeaddress[50];
	float GPA ; 
} ; 
// write the number N of studentst first 
// then for every student we write the studentId first then fullname then homeaddress then GPA the going to the next stdudent
const int N =  84 ; 
student a[N] ; 
signed main()
{

	
	ifstream fin("text.bin",ios::binary) ;  
	int n;  
	fin.read((char*)&n,sizeof(n)) ;  
	for(int i=1;i<=n;i++)
	{	
		// fin.read((char*)&a[i],162) ; 
		fin.read(a[i].studentID,8); 
		fin.read(a[i].fullname,100); 
		fin.read(a[i].homeaddress,50); 
		fin.read((char*)&a[i].GPA,4); 
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i].studentID<<" "<<a[i].fullname<<" "<<a[i].homeaddress<<" "<<a[i].GPA<<endl; 
	}
}