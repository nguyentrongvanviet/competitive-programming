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

	ofstream fout("text.bin",ios::binary) ;  
	int n =3 ; 	 
	a[1] = student{"1923799","phuoc","ha noi",4.3} ; 
	a[2] = student{"2000100","ton","lao",4.2} ; 
	a[3] = student{"5023102","viet","uc",3.6} ; 
	fout.write((char*)&n,sizeof(n)) ;  
	for(int i=1;i<=n;i++)
	{	
		fout.write((char*)a[i].studentID,8); 
		fout.write(a[i].fullname,100); 
		fout.write(a[i].homeaddress,50); 
		fout.write((char*)&a[i].GPA,4); 
	}
}