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

int n  ,k ;  
ll a[N] , b[N] , c[N]  ,sb=0 ,sc=0 ; 
void inp()
{
    cin>> n >> k ; 
    for(int i= 1;i<=n;i++)
    {
        cin>>a[i] ; 
    }   
    sort(a+1,a+n+1) ;
    for(int i= 1;i<=n;i++)
    {
        if(a[i]>0)c[++sc]=a[i] ; 
    }
    for(int i =n;i>=1;i--)
    {
        if(a[i]<0)b[++sb]=abs(a[i]) ; 
    }
    ll res= 0 ; 
    for(int  i = sb;i>=1;i-=k)
    {
        res+=2*b[i]; 
    }
    for(int i =sc;i>=1;i-=k)
    {
        res+=2*c[i] ; 
    }
    // cout<<res<<endl; 
    res-=max(b[sb],c[sc]);
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