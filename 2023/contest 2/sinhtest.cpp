#define TASK  "Tree_Queries"
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
    ofstream cout("text.INP");
    int n= 1e6 , q= 1e6 ; 
    cout<<n<<" "<<q<<el;
    FOR(i,1,n-1)
    {
    	cout<<i<<" "<<rd(i+1,n)<<el; 
    }
    while(q--)
    {
    	int TYPE = rd(1,2) ;
    	cout<<TYPE<<" "<<rd(1,1e6)<<el;
    }
    cout.close();
}

signed main()
{   
    srand(time(0)) ; 
    FOR(i,1,T)
    {
        create(); 
        // system(TASK"_trau.exe");
        system(TASK".exe"); 
        // if(system("fc " TASK ".OUT " TASK ".ANS")!=0)
        // {   
        //     cout<<"Test "<<i<<" WA"<<"\n";
        //     return  0 ; 
        // }
        // cout<<"Test "<<i<<" AC"<<"\n";
    }
}