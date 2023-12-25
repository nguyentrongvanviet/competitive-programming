#define TASK  "text"
#include<bits/stdc++.h>
const int T  = 1000 ; 
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
    int n =100  , m =100 , k=rd(1,20)  , q= rd(1,20); 
    cout<<n<<" "<<m<<" "<<k<<" "<<q<<el; 
    FOR(i,1,k)
    {
    	cout<<rd(1,n)<<" "<<rd(1,m)<<el;
    }
    FOR(i,1,q)
    {
    	cout<<rd(1,n)<<" "<<rd(1,m)<<el;
    }
    cout.close();
}

signed main()
{   
    srand(time(0)) ; 
    FOR(i,1,T)
    {
        create(); 
        system("GRFLRS""_trau.exe");
        system("GRFLRS"".exe"); 
        if(system("fc " TASK ".OUT " TASK ".ANS")!=0)
        {   
            cout<<"Test "<<i<<" WA"<<"\n";
            return  0 ; 
        }
        cout<<"Test "<<i<<" AC"<<"\n";
    }
}