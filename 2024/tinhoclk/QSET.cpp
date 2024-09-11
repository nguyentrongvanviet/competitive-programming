#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf  = 1e17+5 , sm = 1e9+7 ; 

signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int n ; cin>>n;
    set<int>s ; 
    for(int i =1;i<=n;i++)
    {
        int val; cin>>val; 
        s.insert(val) ; 
    }
    int q ; cin>>q ; 
    while(q--)
    {
        int type ; cin>>type ; 
        if(type==5)
        {
            cout<<*s.begin()<<" "<<*s.rbegin()<<'\n';
        }
        else
        {
            int val; cin>>val; 
            if(type==1)
            {
                s.insert(val) ;
            }
            else if(type==2)
            {
                s.erase(val) ; 
            }
            else if(type==3)
            {
                auto x = s.upper_bound(val) ; 
                if(x==s.end())cout<<"No"<<'\n';
                else cout<<*x<<'\n';
            }
            else if(type==4)
            {
                auto x = s.lower_bound(val) ;
                if(x==s.begin())cout<<"No"<<'\n'; 
                else cout<<*prev(x)<<'\n';
            }
        }
    }
}