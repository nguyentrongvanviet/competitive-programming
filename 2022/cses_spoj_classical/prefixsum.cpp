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

int n  , k ; 
ll s[N] , a[N] ; 
void inp()
{
    cin>> n ;
    cin>>k ; 
    for(int i =1 ;i<=k;i++)
    {
        cin>>s[i ]; 
    }  
    if(n==1||k==1)
    {
        cout<<"Yes"<<"\n" ;
        return ; 
    }
     
    a[k]= s[k]-s[k-1] ; 
    for(int i =k-1;i>=2;i--)
    {   
        a[i] =s[i]-s[i-1]; 
        if(a[i]>a[i+1])
        {
            cout<<"No"<<"\n" ; 
            return ; 
        }
    }
    if(n==k)
    {
        a[1]= s[1] ; 
        if(a[1]>a[2])
        {
            cout<<"No"<<"\n"; 
        }
        else 
        {
            cout<<"Yes"<<"\n";
        }
        return ; 
    }
    if((n-k+1)*a[2]<s[1])cout<<"No"<<"\n";
    else cout<<"Yes"<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int test ;
    cin>>test ; 
    while(test--)inp();
    return 0;
}