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
	int a[5] ; 
	fin.read((char*)a,5*4) ; 
	for(int i=0;i<5;i++)cout<<a[i]<<" ";
}