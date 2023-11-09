#include <bits/stdc++.h>
using namespace std;

#define TASK "PFTREE"

const int T = 100;

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
#define ll long long 
#define pb push_back 
#define pk pop_back 
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i =a;i>=b;i--)

ll rd(ll l , ll r )
{
    return l +1LL*rand()%(r-l+1);
}
void create()
{
    
    // freopen("PFTREE.INP","w",stdout);
    ofstream cout(TASK".INP"); 
    int n , q ;  
    cin>> n >>q ;
    cout<<n<<" "<<q<<"\n"; 
    FOR(i,1,n-1)
    {   
        int u ,v ; 
        cin>>u >> v; 
        cout<<u<<" "<<v<<endl;
    }
    FOR(i,1,q)
    {
        cout<<rd(0,1)<<" "<<rd(0,1)<<"\n";
    }
    cout.close();
}

int main()
{
    freopen("tmp.INP","r",stdin) ;
    fast
    srand(time(0));
    FOR(i,1,1)
    {
        create(); 
        system(TASK"_trau.exe");
        system(TASK".exe");
        if(system("fc " TASK ".ANS " TASK ".OUT")!=0)
        {   
            cout<<"Test "<<i<<" WA"<<"\n";
            return  0 ; 
        }
        else 
        {
            cout<<"Test "<<i<<" AC"<<"\n";
        }
    }
    return 0;
}