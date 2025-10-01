#include<iostream>
#include<fstream> 
#include<cstring> 
using namespace std ; 


struct student
{
	char studentID[8]; 
	char* fullname ; 
	char* homeaddress;
	float GPA ; 
	// float 4 byte <= maximum= int 
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
	for(int i=0;i<n;i++)
	{	
		fin.read((char*)a[i].studentID,8); 
		int len; 
		fin.read((char*)&len,4) ;
		a[i].fullname = new char[len] ; 
		fin.read((char*)a[i].fullname,len);
		
		fin.read((char*)&len,4) ;
		a[i].homeaddress=new char[len] ;  
		fin.read((char*)a[i].homeaddress,len); 
		fin.read((char*)&a[i].GPA,4); 

	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i].studentID<<" "<<a[i].fullname<<" "<<a[i].homeaddress<<" "<<a[i].GPA<<endl; 
	}
}