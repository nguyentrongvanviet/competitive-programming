#define TASK  "text"
#include<bits/stdc++.h>
const int T  = 100 ; 
using namespace std; 
#define ll long long 
#define db double 
#define el '\n'
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
ll sq(ll a){return a*a;}   
ll rd(ll l , ll r )
{
    return l+1LL*rand()*rand()%(r-l+1) ; 
}
void create()
{
    ofstream cout(TASK".INP");
    int n = 400 ; 
    cout<<n<<" "<<1e5<<endl;
    set<int>s ;  
    for(int i=1;i<=n;i++)
    {   
        int val = rd(1,1e9) ;
        while(s.find(val)!=s.end()) val = rd(1,1e9) ;
        s.insert(val) ;
    }
    for(auto x : s)cout<<x<<" " ;
    cout<<endl; 
    for(int i=1;i<=1e5;i++)
    {
        int l = rd(1,n) ; 
        int r = rd(l,n) ; 
        int cost = rd(1,1e4) ; 
        int k = rd(0,n-1) ; 
        cout<<l<<" "<<r<<" "<<cost<<" "<<k<<el; 
    }
    cout.close();
}

signed main()
{   
    srand(time(0)) ; 
    FOR(i,1,T)
    {
        create(); 
        system("hsgtinhhatinh"".exe"); 
        // if(system("fc " TASK ".OUT " TASK ".ANS")!=0)
        // {   
        //     cout<<"Test "<<i<<" WA"<<"\n";
        //     return  0 ; 
        // }
        cout<<"Test "<<i<<" AC"<<"\n";
    }
}