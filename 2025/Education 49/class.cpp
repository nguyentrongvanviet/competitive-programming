#include<bits/stdc++.h>
using namespace std ; 

class A 
{
    public : 
        int a ;  
        ~A()
        {
            cout<<"A"<<endl;
        }
} ; 
class B 
{
    public  : 
        int b ; 
        ~B()
        {
            cout<<"B"<<endl;
        }
}; 

signed main()
{
    B b ; 
    B c ; 
    A a ; 
}