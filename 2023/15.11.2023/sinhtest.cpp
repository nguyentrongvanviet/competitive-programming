#define TASK  "tabishop"
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
   	int n = 200 , m =rd(0,100) ,k=rd(1,n*n-m); 
   	cout <<n<<" "<<m<<" "<<k<<el; 
   	map<pair<int,int>,int>exist; 
   	FOR(i,1,m)
   	{
   		while(1)
   		{
	   		int  x= rd(1,n) ; 
	   		int y =rd(1,n) ; 
	   		if(exist.count({x,y}))continue ;
	   		exist[{x,y}] = 1;
            cout<<x<<" "<<y<<el;
            break; 
   		}
   	}
   	FOR(i,1,k)
   	{
	   	while(1)
   		{
	   		int  x= rd(1,n) ; 
	   		int y =rd(1,n) ; 
	   		if(exist.count({x,y}))continue ;
	   		exist[{x,y}] = 1; 
            cout<<x<<" "<<y<<el;
       		   break;
        }	
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