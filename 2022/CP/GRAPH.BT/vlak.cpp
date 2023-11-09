#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =2e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll n   , m ;
string a[N] , b[N];
ll T[N][26] ;
ll d1[N] , d2[N];
ll node =1;
void up1(string s)
{
    ll r =1 ;
    for(ll i= 0 ;i<s.size();i++)
    {
        ll j = s[i] -'a';
        if(T[r][j]==0)
        {
            T[r][j]=++node  ;
        }
        r=T[r][j];
        d1[r]=1;
    }
}
void up2(string s)
{
    ll r =1 ;
    for(ll i= 0 ;i<s.size();i++)
    {
        ll j = s[i] -'a';
        if(T[r][j]==0)
        {
            T[r][j]=++node  ;
        }
        r=T[r][j];
        d2[r]=1;
    }
}
ll tinh(ll r , ll t )
{
//    cout<<r<< " "<<t<<endl;
    if(t==1)
    {
        for(ll i=  0;i<26;i++)
        {
            ll nr = T[r][i];
            if(d1[nr]==1){
                if(tinh(nr,t^1)==0)
                {
                    return 1 ;
                }
            }
        }
        return 0 ;
    }
    else
    {
        for(ll i=  0;i<26;i++)
        {
            ll nr = T[r][i];
            if(d2[nr]==1)
            {
                if(tinh(nr,t^1)==0)
                {
                    return 1 ;
                }
            }
        }
        return 0 ;
    }
}
void inp()
{
    cin>>n ;
    for(ll i =1 ;i<=n;i++)cin>>a[i],up1(a[i]);
    cin>> m ;
    for(ll i = 1;i<=m;i++)
    {
        cin>>b[i],up2(b[i]);
    }
    if(tinh(1,1)==1)cout<<"Nina";
    else cout<<"Emilija";
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
