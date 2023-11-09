#include <bits/stdc++.h>
using namespace std;

#define TASK "p9queue"

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
    ofstream cout(TASK".INP");

    int n= rd(1,1000);  
    cout<<n<<" "<<rd(1,n)<<"\n";
    FOR(i,1,n)
    {
    	cout<<rd(1,n)<<" ";
    }
    cout.close();
}

int main()
{
    fast
    srand(time(0));
    FOR(i,1,T)
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