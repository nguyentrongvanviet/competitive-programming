#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ,cs=330 ;
const ll mod = 1e9+7 ,inf = 1e17;
int n ; 
int a[N] ; 
void inp(){
    cin>> n ; 
    int t= 0 ;  
    for(int i = 1 ;i<=n;i++)
    {
        cin>>a[i] ;
        if(a[i]>1)t = 1;  
    }
    int s = 0;  
    for(int i =1;i<=n;i++)
    {
        s^=a[i] ; 
    }
    if(t==0)
    {
        cout<<(s==0? 1 : -1 )<<"\n";
    }else cout<<(s==0?-1:1)<<"\n";
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