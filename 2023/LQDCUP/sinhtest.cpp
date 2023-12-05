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
    int n = rd(3,100); 
    int q = rd(1,300	) ; 
    int w = 100 ; 
    cout<<n<<" "<<q<<" "<<w<<el;
    FOR(i,1,n-1)
    {
    	cout<<i<<" "<<rd(i+1,n)<<" "<<rd(1,10)<<el;
    } 
    while(q--)
    {
    	int d =rd(1,n-1) ;
    	int e = rd(1,w) ; 
    	cout<<d<<" "<<e<<el;
    }
    cout.close();
}

signed main()
{   
    srand(time(0)) ; 
    FOR(i,1,T)
    {
        create(); 
        system("TRAVEL""_trau.exe");
        system("TRAVEL"".exe"); 
        if(system("fc " TASK ".OUT " TASK ".ANS")!=0)
        {   
            cout<<"Test "<<i<<" WA"<<"\n";
            return  0 ; 
        }
        cout<<"Test "<<i<<" AC"<<"\n";
    }
}