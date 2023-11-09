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
    int n= rd(2,100) , q = rd(1,1000) ; 
    cout<<n<<" "<<q<<el; 
    FOR(i,1,q)
    {
    	int x =rd(1,n-1) ; 
    	int y =rd(x,n-1) ; 
    	int u = rd(y+1,n) ; 
    	int v =rd(u,n) ; 
    	cout<<x<<" "<<y<<" "<<u<<" "<<v<<" "<<rd(-5,5)<<el;
    }
    cout.close();
}

signed main()
{   
    srand(time(0)) ; 
    FOR(i,1,T)
    {
        create(); 
        system("mst""_trau.exe");
        system("mst"".exe"); 
        if(system("fc " TASK ".OUT " TASK ".ANS")!=0)
        {   
            cout<<"Test "<<i<<" WA"<<"\n";
            return  0 ; 
        }
        cout<<"Test "<<i<<" AC"<<"\n";
    }
}