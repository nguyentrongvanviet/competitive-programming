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

int n , k ;
ll a[N] , s[N] ; 
unordered_map<ll,int>cnt; 
void inp()
{
    cin>> n>> k ; 
    for(int i= 1;i<=n;i++)
    {
        cin>>a[i] ;
        a[i]-=k;   
        s[i]=s[i-1]+a[i] ; 
    }
    cnt[0]=1; 
    ll res=0  ; 
    for(int i =1;i<=n;i++)
    {       
        res+=cnt[s[i]] ; 
        cnt[s[i]]++; 
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