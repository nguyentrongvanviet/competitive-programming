#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 

signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int n; cin>> n;
    set<int>s ; 
    multiset<int>dis ; 
    for(int i=1;i<=n;i++)
    {
        int val; cin>>val; 
        if(s.empty()||s.count(val))s.insert(val) ;
        else 
        {
            auto r = s.lower_bound(val) ; 
            if(r==s.end())
            {
                dis.insert(val-*s.rbegin()); 
            }
            else if(r==s.begin())
            {
                dis.insert(*s.begin()-val) ; 
            }
            else 
            {
                auto l = prev(r) ; 
                dis.erase(dis.find(*r-*l));
                dis.insert(*r-val) ; 
                dis.insert(val-*l) ; 
            }
            s.insert(val) ; 
        }
        if(dis.empty())cout<<0<<'\n';
        else cout<<*dis.rbegin()<<'\n';
    }
}