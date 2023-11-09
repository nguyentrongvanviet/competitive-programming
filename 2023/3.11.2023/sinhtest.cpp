#define TASK  "light5"
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
    int n =rd(2,500) ; 
    int m = rd(1,5000) ; 
    int q =rd(1,50) ;
    cout<<n<<" "<<m<<" "<<q<<el; 
    FOR(i,1,m)
    {
    	int u =rd(1,n-1) ; 
    	int v= rd(u+1,n) ; 
    	cout<<u<<" "<<v<<" "<<rd(0,1)<<el; 
    }
    FOR(i,1,q)cout<<rd(1,n)<<" ";
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