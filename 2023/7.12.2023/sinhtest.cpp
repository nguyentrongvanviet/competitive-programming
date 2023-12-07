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
    int n =1e5 , m =2e5 , q=2e5  ;
    cout<<n<<" "<<m<<" "<<q<<el; 
    FOR(i,1,n-1)
    {
    	cout<<i<<" "<<rd(i+1,n)<<el;
    }
    m-=(n-1) ;
    FOR(i,1,m)
    {
    	int u= rd(1,n) ;
    	int v =rd(1,n) ;
    	cout<<u<<" "<<v<<el; 
    }
    cout<<el;
    FOR(i,1,q)
    {
    	int l = rd(1,n) ;
    	int r =rd(l,n) ;
    	cout<<l<<" "<<r<<el;
    }
    cout.close();
}

signed main()
{   
    srand(time(0)) ; 
    FOR(i,1,T)
    {
        create(); 
        // system("tree_3""_trau.exe");
        system("tree_3"".exe"); 
        // if(system("fc " TASK ".OUT " TASK ".ANS")!=0)
        // {   
        //     cout<<"Test "<<i<<" WA"<<"\n";
        //     return  0 ; 
        // }
        // cout<<"Test "<<i<<" AC"<<"\n";
    }
}