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

    int n= rd(1,5) , q= rd(1,3) ;
    cout<<n<<" "<<q<<el; 
    FOR(i,2,n)cout<<rd(1,i-1)<<" " ;
    cout<<el;
    FOR(i,2,n)cout<<rd(1,n)<<" " ;
    cout<<el;
    FOR(i,1,q)
    {
        int val = rd(1,n) ;
        int sl =rd(1,val) ;
        cout<<sl<<" "<<val<<el;
    }
    cout.close();
}

signed main()
{   
    srand(time(0)) ; 
    FOR(i,1,T)
    {
        create(); 
        system("d13apegamev""_trau.exe");
        system("d13apegamev"".exe"); 
        if(system("fc " TASK ".OUT " TASK ".ANS")!=0)
        {   
            cout<<"Test "<<i<<" WA"<<"\n";
            return  0 ; 
        }
        cout<<"Test "<<i<<" AC"<<"\n";
    }
}