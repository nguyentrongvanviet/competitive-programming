#include<bits/stdc++.h>
using namespace std;

#define TASK "milktea"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

bool cmp(pair<string,int>a , pair<string,int> b)
{
    return a.se<b.se;
}
int n  , m , p ; 
string a[N] , b[N] ; 
vector<string>val ; 
void doc()
{
	cin>>n>>m>>p ;
    FOR(i,1,n)
    {
        cin>>a[i] ; 
    }  
    FOR(i,1,m)
    {
        cin>>b[i] ;
    }
    vector<pair<string,int>> q ;
    q.pb({"",0});
    FOR(i,1,p)
    {
        vector<pair<string,int>>tmp;
        for(auto it : q)
        {
            string xx=it.fi,yy=it.fi;
            xx+='0'; 
            yy+='1';
            int x = it.se ;
            int y = it.se ; 
            FOR(j,1,n)
            {
                if(a[j][i-1]=='1')
                {
                    x++;
                }
                else 
                {
                    y++;
                }
            }
            tmp.pb({xx,x});
            tmp.pb({yy,y});
        }
        q.clear();
        sort(tmp.begin(),tmp.end(),cmp);
        FOR(i,1,min((int)tmp.size(),101))
        {
            q.pb(tmp[i-1]);
        }
    }
    FOR(i,0,q.size()-1)
    {
        bool ok=1;
        FOR(j,1,m)
        {
            if(b[j]==q[i].fi)
            {
                ok =0 ; 
                break ;
            }
        }
        if(ok)
        {
            cout<<q[i].se<<"\n";
            return ; 
        }
    }
}
void xuly()
{
    
}
int main()
{
    IOS();  
    int test ;
    cin>>test;
    while(test--)
    {
        doc(); 
        xuly(); 
    }
    
}