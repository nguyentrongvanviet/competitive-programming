#include<bits/stdc++.h>
using namespace std ;

class D ;
class Inter ; 
class B
{
    public : 
    int a; 
    B()
    {
        a  = 5 ; 
        cout<<"B::Constr"<<endl; 
    }
    B(const B&other)
    {
        cout<<"B::CopyConstr"<<endl;  
    }
    virtual void show()const
    {
       cout<<"B::Show"<<endl;   
    }
    virtual ~B()
    {
        cout<<"B::Destr"<<endl; 
    }
} ; 
class Inter : public B{
    public: 
        int b = 10 ; 
        Inter()
        {
            cout<<"Inter::Constr"<<endl;  
        }
        Inter(const Inter&o):B(o)
        {
            cout<<"Inter::CopyConstr"<<endl;
        }
        void show()
        {
            cout<<"Inter::Show"<<endl;
        }
        ~Inter()
        {
            cout<<"Inter::Destr"<<endl;
        }
}; 

class D : public Inter{
    public : 
    int c = 4 ; 
    D()
    {
        cout<<"D::Constr"<<endl;
    }
    D(const D&o):Inter(o)
    {
        cout<<"D::Copystr"<<endl; 
    }
    void show()
    {
        cout<<"D::Show"<<endl;
    }
    ~D()
    {
        cout<<"D::Destr"<<endl;
    }
} ; 
void callByvalue(B obj)
{
    cout<<"byValue"<<endl;
    obj.show() ; 
}
void callByRef(B*obj)
{
    cout<<"byRef"<<endl; 
    obj->show() ; 
}
int main(){
    cout<<"Create d1:"<<endl;
    D d1  ; 
    cout<<endl<<"Calling"<<endl; 
    callByvalue(d1) ; 
    callByRef(&d1) ; 
    cout<<endl<<"End of main"<<endl; 
    return 0 ; 
}