#include<bits/stdc++.h>
using namespace std ;
const int N = 5e5+5 ;

int n , MAX ;
struct DL
{
    int val;  
    int sl ; 
    int maxpos ; 
    bool operator<(const DL&a)const
    {
        return sl<a.sl||(sl==a.sl&&maxpos<a.maxpos) ; 
    }
}a[N] ; 

signed main()
{
    ios_base::sync_with_stdio(0) ; 
    cin.tie(0); cout.tie(0) ;
    cin>> n >> MAX ;
    map<int,pair<int,int>>sl; 
    for(int i=1;i<=n;i++)
    {
        int val ; cin>>val; 
        sl[val].first++ ; 
        sl[val].second=i ; 
    }
    int cnt = 0 ; 
    for(auto x :sl)
    {
        a[++cnt] = {x.first,x.second.first,x.second.second} ;  
    }
    sort(a+1,a+cnt+1); 
    for(int i=1;i<=cnt;i++)
    {
        while(a[i].sl--)cout<<a[i].val<<" ";
    }
    return 0 ;
}