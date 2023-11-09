#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,l,r) for(ll i= l;i<=r;i++)
const ll N =1e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

vector<ll>digit;
ll f[20][5][3];
ll dd[20][5][3];
ll tinh(ll pos , ll sl , ll d )
{
    if(pos==digit.size())return 1;
    if(dd[pos][sl][d]==1)return f[pos][sl][d];
    dd[pos][sl][d]=1;
    ll tmp= 0 ;
    if(sl==3)
    {
        tmp = tinh(pos+1,sl,d|(digit[pos]>0));
    }else
    {
        if(d==0)
        {
            tmp+=tinh(pos+1,sl+(digit[pos]!=0),d);
            for(ll i= 0 ;i<digit[pos];i++)
            {
                tmp+=tinh(pos+1,sl+(i>0),1);
            }
        }else
        {
            for(ll i=0;i<=9;i++)
            {
                tmp+=tinh(pos+1,sl+(i>0),1);
            }
        }
    }
    return f[pos][sl][d]=tmp ;
}
ll ex(ll x)
{
    digit.clear();
    memset(f,0,sizeof(f));
    memset(dd,0,sizeof(dd));
    while(x)
    {
        digit.pb(x%10);
        x=x/10 ;
    }
    reverse(digit.begin(),digit.end());
    return tinh(0,0,0);
}
void inp()
{
    ll l , r ;
    cin>>l>>r;
    cout<<ex(r)-(l==1?1 : ex(l-1))<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    ll test ;
    cin>>test ;
    while(test--)inp();
}
