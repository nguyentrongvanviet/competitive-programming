#include<bits/stdc++.h>
using namespace std; 
 

class S 
{
public : 
    char* str ; 
    S()
    {
        str= new char[1] ; 
        str[0] = '\0'; 
    }
    // char& operator[](int index)
    // {
    //     cout<<strlen(str)<<endl;
    //     return str[index] ; 
    // }
    char& operator[](int index)
    {
        return str[index] ; 
    }
    friend ostream& operator<<(ostream& out , const S& other) ; 
} ; 
ostream& operator<<(ostream& out , const S&other)
{
    out<<other.str ;  
    return out ; 
}

int main()
{
    S x ; 
    x.str = new char[100] ; 
    strcpy(x.str,"hello") ; 
    x[0] = '1' ; 
    cout<<x<<endl;  
    // cout<<x<<endl;
}