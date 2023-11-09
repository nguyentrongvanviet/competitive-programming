#include<bits/stdc++.h>
using namespace std ;
#define TASK "MEET_IN_MIDDLE"
#define ll long long 

const int TEST = 100  ; 
ll Rand(ll l , ll r )
{
    return l +1LL*rand()%(r-l+1) ; 
}

void create() 
{
    ofstream cout (TASK".INP");
    int n =4  , m  = 3 ; 
    cout<<n<<"\n";
    cout<<m<<"\n";
    for(int i= 1;i<=n;i++)
    {
        cout<<Rand(1,3)<<" ";
    }
    cout.close();
}
int main()
{
    srand(time(0)) ;
    for(int i= 1  ;i<=TEST;i++)
    {
        create() ;

        system(TASK"_trau.exe") ; 
        system(TASK".exe");

        if(system("fc " TASK".ANS " TASK".OUT"  )!=0)
        {
            cout<<"TEST "<<i<<" sai cmnr !!!";
            return 0 ;
        }
        else 
        {
            cout<<"TEST "<<i<< " " <<"AC";
        }
    }    
}