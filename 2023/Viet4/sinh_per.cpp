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
const int N = 1e5+5 ;
int a[N]  ;
void create()
{
    ofstream cout(TASK".INP");
    int n = rd(1,100) ; 
    int q = 1000 ; 
    cout<<n<<" "<<" "<<q<<el; 
    FOR(i,1,n)a[i] = i ;
    random_shuffle(a+1,a+n+1) ; 
    FOR(i,1,n)cout<<a[i]<<" ";
    cout<<el; 
    random_shuffle(a+1,a+n+1) ; 
    FOR(i,1,n)cout<<a[i]<<" ";
    cout<<el; 
    while(q--)
    {
    	int l =rd(1,n) ;
    	int r =rd(l,n) ;
    	int u =rd(1,n) ;
    	int v =rd(1,n) ;
    	cout<<l<<" "<<r<<" "<<u<<" "<<v<<el;
    }
    cout.close();
}

signed main()
{   
    srand(time(0)) ; 
    FOR(i,1,T)
    {
        create(); 
        system("per""_trau.exe");
        system("per"".exe"); 
        if(system("fc " TASK ".OUT " TASK ".ANS")!=0)
        {   
            cout<<"Test "<<i<<" WA"<<"\n";
            return  0 ; 
        }
        cout<<"Test "<<i<<" AC"<<"\n";
    }
}