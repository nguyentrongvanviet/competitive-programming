#include<bits/stdc++.h>
using namespace std; 
#define TASK "temp"
struct DL
{
    int val;  
}; 
struct cmp
{
    bool operator()(const DL& a, const DL& b)const
    {
        return a.val<b.val; 
    }
} ; 
#define el '\n' 
signed main()
{
    freopen(TASK".INP","r",stdin) ;
    freopen(TASK".OUT","w",stdout) ; 
    multiset<DL,cmp>s;  
   	for(int i= 1;i<=4;i++)s.insert({i/2});
    auto tmp = *prev(s.upper_bound({2})) ; 
    auto i = s.upper_bound({2}) ; 
    ++i
    auto it =*i;
    cout<<tmp.val<<" "<<it.val<<el;
}