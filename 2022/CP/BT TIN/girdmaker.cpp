#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N= 1e6+6 , INF = 1e17  , C =330 , sm = 1e9+7  ;
ll l ,  r,  m , k ;
void sub1()
{
    ll t = 0 ;
    string s="";
    while(t+9<=l)
    {
        s="9"+s;
        t=t+9;
    }
    if(t==l)cout<<s<<"\n";
    ll cl =l-t;
    s=to_string(cl)+s;
    cout<<s<<"\n";
}
void inp()
{
    cin>> l>>r>>m>>k  ;
    if(m==1)
    {
        sub1();
    }else if(r==1)
    {
        if(l==0)
        {
            if(k%m==0)cout<<"0"<<"\n";
        }else
        {

        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin) ;
//    freopen("o.txt","w",stdout) ;
    ll t ;
    cin>>t ;
    while(t--)
    {
        inp();
    }
}
