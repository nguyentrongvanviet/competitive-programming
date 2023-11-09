#define TASK  "store"
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
const int N = 1e5+5 ;
int a[N] ; 
void create()
{
    ofstream cout(TASK".INP");
    int n = 1e5; 
    cout<<n<<el;
    FOR(i,1,n)a[i] =rd(1,1e3) ; 
    sort(a+1,a+n+1) ; 
    FORD(i,n,1)cout<<a[i]<<" ";
    cout<<el;
    int q = 1e5; 
    cout<<q<<el ;
    FOR(i,1,q)
    {	
    	if(i<=q/2)cout<<1<<" ";
    	else cout<<2<<" ";
    	// cout<<2<<" ";
        cout<<rd(1,n)<<" "<<rd(1,1e3)<<el;
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