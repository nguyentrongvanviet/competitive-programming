#include<bits/stdc++.h>
using namespace std;

const int N =2e5+5;  
int n , m ,q ; 
int a[N] , b[N] ; 
struct DL
{
    int val , pos ; 
    DL(int _val = 0 ,int _pos = 0 )
    {
        val = _val ;
        pos = _pos ; 
    }
} ;
struct cmp
{
    bool operator()(const DL&a , const DL&b)const
    {
        return a.pos<b.pos ; 
    } 
} ;
set<DL,cmp>s ;
set<int>P[N] ; 
int init[N] ; 
int wrong = 0 ;
bool check(int val1 ,int val2)
{
    if(init[val1]+1!=init[val2])return 1 ; 
    return 0 ; 
}
void add(int val ,int pos)
{
    if(!s.empty())
    {
        auto it = s.lower_bound({val,pos}) ;
        if(it==s.begin())
        {
            wrong+=check(val,(*it).val) ; 
        }
        else if(it==s.end())
        {
            wrong+=check((*prev(it)).val,val) ; 
        }
        else
        {
            wrong-=check((*prev(it)).val,(*it).val) ; 
            wrong+=check(val,(*it).val) ; 
            wrong+=check((*prev(it)).val,val) ; 
        }
    }
    s.insert(DL(val,pos)) ; 
}
void erase(int val , int pos )
{
    s.erase(DL(val,pos)) ; 
    if(!s.empty())
    {
        auto it = s.lower_bound({val,pos}) ;
        if(it==s.begin())
        {
            wrong-=check(val,(*it).val) ; 
        }
        else if(it==s.end())
        {
            wrong-=check((*prev(it)).val,val) ; 
        }
        else
        {
            wrong+=check((*prev(it)).val,(*it).val) ; 
            wrong-=check(val,(*it).val) ; 
            wrong-=check((*prev(it)).val,val) ; 
        }
    }
}
void del(int val , int pos)
{
    P[val].erase(pos) ; 
    if(!P[val].empty()&&pos>(*P[val].begin()))return ; 
    erase(val,pos) ; 
    if(!P[val].empty())add(val,*P[val].begin()) ; 
}
void ins(int val ,int pos)
{
    if(!P[val].empty()&&pos>(*P[val].begin()))
    {
        P[val].insert(pos) ; 
        return ; 
    } 
    if(!P[val].empty())erase(val,*P[val].begin()) ;
    P[val].insert(pos) ;    
    add(val,pos) ; 
}
bool OK()
{
    return wrong == 0  && (*s.rbegin()).val== a[int(s.size())]; 
}
signed main()
{   
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int test; cin >> test;
    while (test--)
    {
        cin>> n >> m >>q ; 
        for(int i=1;i<=n;i++)
        {
            cin>>a[i] ; 
            init[a[i]] = i ; 
        }
        for(int i=1;i<=m;i++)
        {
            cin>>b[i];
            ins(b[i],i) ; 
        }
        cout<<(OK() ? "YA" : "TIDAK")<<'\n'; 
        for(int i=1;i<=q;i++)
        {
            int pos , val ; cin>>pos>>val; 
            del(b[pos],pos) ; 
            ins(b[pos]=val,pos) ; 
            cout<<(OK() ? "YA" : "TIDAK")<<'\n'; 
        }
        s.clear() ; 
        wrong = 0  ;
        for(int i=1;i<=n;i++)P[i].clear() ; 
    }
}