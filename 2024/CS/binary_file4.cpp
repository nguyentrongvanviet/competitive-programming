#include<iostream>
#include<fstream> 
#include<cstring> 
#include<vector>
using namespace std ; 


struct Student
{
	char studentID[8]; 
	char* fullname ; 
	char* homeaddress;
	float GPA ; 
} ; 
// write the number N of studentst first 
// then for every student we write the studentId first then fullname then homeaddress then GPA the going to the next stdudent
const int N =  84 ; 
Student a[N] ; 
signed main()
{

	ofstream fout("text.bin",ios::binary) ;  
	int n =5 ; 	
	fout.write((char*)&n,4) ;  

    Student students[5];
    students[0] = Student{"S01", (char *)"Student 1", (char *)"Address 1", 3.5};
    students[1] = Student{"S02", (char *)"Student 2", (char *)"Address 2", 3.6};
    students[2] = Student{"S03", (char *)"Student 3", (char *)"Address 3", 3.7};
    students[3] = Student{"S04", (char *)"Student 4", (char *)"Address 4", 3.8};
    students[4] = Student{"S05", (char *)"Student 5", (char *)"Address 5", 3.9};
	for(int i=0;i<n;i++)
	{	
		fout.write((char*)students[i].studentID,8);
		
		int len = strlen(students[i].fullname)+1 ; 

		fout.write((char*)&len,4) ;  
		fout.write((char*)students[i].fullname,len);

		len = strlen(students[i].homeaddress)+1 ; 
		fout.write((char*)&len,4) ;

		fout.write((char*)students[i].homeaddress,len);
		fout.write((char*)&students[i].GPA,4); 
	}
	fout.close() ; 
}