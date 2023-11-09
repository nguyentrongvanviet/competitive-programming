#define TASK  "TRAVEL"
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
    int n=rd(7,7); int m=rd(n-1,n-1); int k=rd(1,1);
    cout<<n<<" "<<m<<" "<<k<<el;
    FOR(i,1,n-1){
        cout<<i<<" "<<rd(i+1,n)<<el;
    }
    // FOR(i,n,m) cout<<rd(1,n)<<" "<<rd(1,n)<<el;
    cout.close();
}

signed main()
{   
    srand(time(0)) ; 
    FOR(i,1,T)
    {
        create(); 
        system(TASK"_trau.exe");
        system(TASK".exe"); 
        if(system("fc " TASK ".OUT " TASK ".ANS")!=0)
        {   
            cout<<"Test "<<i<<" WA"<<"\n";
            return  0 ; 
        }
        cout<<"Test "<<i<<" AC"<<"\n";
    }
}