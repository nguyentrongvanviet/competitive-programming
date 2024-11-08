#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define ve vector
#define vi vector<int>
#define vll vector<ll>

struct poly
{
    vll a;
    poly(){} 
    poly(vll a):a(a){} 
    void print() 
    {
        cout<<"Coef: " ; 
        for(auto x : a)cout<<x<<" "; 
        cout<<'\n' ; 
    }
    void normalize()
    {
        while(a.back()==0)a.pop_back() ;
    }
    int deg()
    {
        return a.size()-1 ; 
    }
    void mod_xk(int k)
    {
        while(deg()>=k)a.pop_back() ; 
    }
    
}; 
signed main()
{   
    poly p({1,2,3,4}) ; 
    p.print() ; 
}
