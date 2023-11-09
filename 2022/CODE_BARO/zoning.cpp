#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =1e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int  n  ;
ll  x ; 
int res = 0 ; 
ll s[N] , a[N] ; 
void inp()
{
    cin>> n >> x ;
    int res= 0 ; 
    for(int i =1;i<=n;i++)cin>>a[i],s[i]=s[i-1]+a[i];
    int l =0 ; 
    for(int i= 1;i<=n;i++)
    {

        while(s[i]-s[l]>x)
        {
            l++ ; 
        }
        if(s[i]-s[l]==x)
        {
            res++; 
        }
    }  
    if(res==0)
    {
        cout<<"HUHU"<<"\n"; 
    }
    else 
    {
        cout<<res<<"\n";
    }
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