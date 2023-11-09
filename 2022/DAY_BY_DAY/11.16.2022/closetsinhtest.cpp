#include <bits/stdc++.h>
using namespace std;

#define TASK "closet"

const int T = 40;

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

    int n= 1000;
    cout<<n<<" ";
    map<pair<int,int>,int>dd;
    FOR(i,1,n)
    {
    	int x= rd(1,1000) ; 
    	int y= rd(1,1000)  ;
    	while(dd.find({x,y})!=dd.end())x=rd(1,1000),y=rd(1,1000);
    	cout<<x<<" "<<y<<"\n"; 
    	dd[{x,y}]= 1 ;
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