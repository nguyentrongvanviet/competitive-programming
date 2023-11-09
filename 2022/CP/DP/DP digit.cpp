#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back
#define int long long
const ll N =1e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll a, b , k ;
vector<int>digit;
int res= 0 ,sz;
int f[11][100][100][2];
int dd[11][100][100][2];

int tinh(int pos ,int val , int sum ,int d)
{
    if(pos==sz)
    {
        if(val==0&&sum==0)return 1 ;
        return 0 ;
    }
    if(f[pos][val][sum][d]!=-1)return f[pos][val][sum][d];
    int tmp = 0 ;
    if(d==1)
    {
        for(int i = 0 ;i<=9;i++)
        {
            tmp+=tinh(pos+1,(val*10+i)%k,(sum+i)%k,d);
        }
    }
    else
    {
        tmp+=tinh(pos+1,(val*10+digit[pos])%k,(sum+digit[pos])%k,d);

        for(int i =0  ;i<digit[pos];i++)
        {
            tmp+=tinh(pos+1,(val*10+i)%k,(sum+i)%k,1);
        }
    }
    return f[pos][val][sum][d]=tmp;
}
ll ex(ll x)
{
    digit.clear();
    while(x)
    {
        digit.pb(x%10);
        x/=10;
    }
    reverse(digit.begin(),digit.end());
    memset(f,-1,sizeof f);
    sz= digit.size();
    return  tinh(0,0,0,0);
}
void inp()
{
    res= 0 ;
    cin>>a>>b>>k;
    if(k>=83)
    {
        cout<<0<<"\n" ;
    }else cout<<ex(b)-(a==1?1 : ex(a-1))<<"\n";
}
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    ll test ;
    cin>>test ;
    for(ll i= 1;i<=test;i++)
    {
        cout<<"Case "<<i<<": ";
        inp();
    }
}

