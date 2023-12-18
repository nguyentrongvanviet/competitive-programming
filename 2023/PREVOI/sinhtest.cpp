#define TASK  "GCDIX"
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
    int n = 5 , q=  rd(0,n-1) ;
    cout<<n<<" "<<q<<el;
    FOR(i,1,n)cout<<2*3*5*rd(1,n)<<" ";
    cout<<el; 
    FOR(i,1,n-1)
    {
        cout<<i<<" "<<i+1<<el; 
    }
    FOR(i,1,q)
    {
        int type = rd(1,2) ;
        int u =rd(1,n) ;
        int v =rd(1,min(u+3,n)) ; 
        cout<<type<<" "<<u<<" "<<v<<" ";
        if(type==1)
        {
            cout<<rd(1,n)<<el;
        }
        cout<<el;
    }
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