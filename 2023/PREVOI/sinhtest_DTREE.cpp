#define TASK  "DTREE"
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
const int N =4e5+5; 
int a[N] ;
void create()
{
    ofstream cout(TASK".INP");
    int n = 3e4;
    int q =rd(1,n) ;
    cout<<n<<" "<<q<<el; 
    FOR(i,1,n-1)
    {
        cout<<i<<" "<<i+1<<el;
        // cout<<i<<" "<<rd(i+1,n)<<el;
    }
    // FOR(i,1,n)a[i] = i ;
    // random_shuffle(a+1,a+n+1) ; 
    // FOR(i,1,q)
    // {
    // 	cout<<a[i]<<" ";
    // }
    // FOR(i,1,q)cout<<i<<" ";
    // cout<<el;
    cout.close();
}

signed main()
{   
    srand(time(0)) ; 
    FOR(i,1,T)
    {
        create(); 
        // system(TASK"_trau.exe");
        system("text"".exe"); 
        // if(system("fc " TASK ".OUT " TASK ".ANS")!=0)
        // {   
        //     cout<<"Test "<<i<<" WA"<<"\n";
        //     return  0 ; 
        // }
        // cout<<"Test "<<i<<" AC"<<"\n";
    }
}