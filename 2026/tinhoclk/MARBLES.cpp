#include<bits/stdc++.h>
using namespace std ;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n ;  cin>> n; 
    int x = (-1+sqrt(1+8*n))/2  ; 
    if(x*(x+1)/2==n)cout<<"Yes."; 
    else cout<<"No.";
}