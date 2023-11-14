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
    ofstream cout(TASK".INP") ; 
    int n = 5 , m =5 , q= 1 , k = 1; 
    cout<<n<<" "<<m<<" "<<q<<" "<<k<<el; 
    FOR(i,1,n)
    {
    	FOR(j,1,m)cout<<rd(1,10)<<" ";
    	cout<<el;
    }
    FOR(i,1,q)cout<<rd(1,n)<<" "<<rd(1,m)<<el;
    FOR(i,1,k)
    {
    	int val = rd(1,10) ; 
    	int L = rd(1,2*n) ; 
    	int R = rd(L,2*n) ; 
    	cout<<val<<" "<<R<<" "<<L<<" "<<rd(1,n)<<" "<<rd(1,m)<<el;
    }
    cout.close();
}

signed main()
{   
    srand(time(0)) ; 
    FOR(i,1,T)
    {
        create(); 
        system("SSTORM""_trau.exe");
        system("SSTORM"".exe"); 
        if(system("fc " TASK ".OUT " TASK ".ANS")!=0)
        {   
            cout<<"Test "<<i<<" WA"<<"\n";
            return  0 ; 
        }
        cout<<"Test "<<i<<" AC"<<"\n";
    }
}