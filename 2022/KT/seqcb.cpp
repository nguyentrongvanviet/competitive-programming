#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
int a[N] ; 
int l =  0 ; 
void inp()
{
    cin>> n ;
    for(int i= 1 ;i<=n;i++)
    {
        cin>>a[i] ; 
    }
    int res= 1;  
    int l = 1 ;
    for(int i=2 ;i<=n;i++)
    {
        while(a[i]<(i-l+1))
        {
            l++ ; 
        }
        res=max(res,i-l+1); 
    }
    cout<<res; 
}   

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}