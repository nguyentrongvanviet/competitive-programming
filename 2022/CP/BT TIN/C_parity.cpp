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
void inp()
{   
    cin>> n ; 
    for(int i= 1 ;i<=n;i++)
    {
        cin>>a[i] ; 
    }
    vector<pii>v;  
    for(int i =1;i<=n-1;i++)
    {
        if(a[i]<=a[i+1])continue ; 
        v.pb({i,i+1}) ; 
        if((a[i]+a[i+1])%2==1)
        {
            a[i+1]=a[i] ; 
        }
    }
    cout<<v.size()<<"\n" ; 
    for(auto it :v)
    {
        cout<<it.X<<" "<<it.Y<<"\n" ; 
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