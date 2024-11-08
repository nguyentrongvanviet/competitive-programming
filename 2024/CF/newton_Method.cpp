#include<iostream>
#include<vector> 
using namespace std; 
struct poly
{
    vector<double> coef; 
    poly(){}
    poly(vector<double>coef):coef(coef) {} 
    int deg() 
    {
        return coef.size()-1 ;
    }
    poly deri()
    {
        vector<double>a ; 
        for(int i=1;i<=deg();i++)
        {
            a.push_back(coef[i]*i) ;
        }
        return a ; 
    }
    double eval(double x)
    {
        double res = 0 ; 
        for(int i=deg();i>=0;--i)
        {
            res = res*x+coef[i] ; 
        }
        return res ; 
    }
} ;
signed main()
{
    int n; 
    vector<double>a ; 
    cout<<"nhap so luong he so cua da thuc "; 
    cin>> n  ;
    for(int i=1;i<=n;i++)
    {
        double x ; cin>>x ; 
        a.push_back(x) ;
    }
    poly f(a) ; 
    int MAXLOOP  = 100000 ; 
    double TOL ; 
    cout<<"Enter the tolerance: " ;
    cin>>TOL;
    cout<<endl; 
    cout<<"Enter the initial guess: " ;
    double x0 ;
    cin>>x0 ;
    double x1 = 1e9 ; 
    while(MAXLOOP--)
    {
        if(abs(x0-x1)<TOL)
        {
            cout<<"The root is "<<x0 ;
            return 0 ;
        } 
        x1=  x0 ; 
        x0 = x0-f.eval(x0)/f.deri().eval(x0) ;
    }
    cout<<"cannot find the root";
    return 0 ;
}