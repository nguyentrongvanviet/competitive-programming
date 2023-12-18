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
    int n = 2e6 ; 
    int m = 2e6 ;
    int k = 40 ; 
    int q = 30 ;
    cout<<n<<" "<<m<<" "<<k<<" "<<q<<el; 
    map<pair<int,int>,int>exist;
    exist[make_pair(1,1)]=1 ;
    FOR(i,1,k)
    {
    	while(1)
    	{
	    	int x = rd(1,n) ;
	    	int y =rd(1,m) ;
	    	if(exist.count(make_pair(x,y))==0)
	    	{
	    		cout<<x<<" "<<y<<el; 
	    		exist[make_pair(x,y)]=1; 
	    		break;
	    	}
    	}
    }
   	FOR(i,1,q)
   	{
   		while(1)
    	{
	    	int x = rd(1,n) ;
	    	int y =rd(1,m) ;
	    	if(exist.count(make_pair(x,y))==0)
	    	{
	    		cout<<x<<" "<<y<<el; 
	    		exist[make_pair(x,y)]=1; 
	    		break;
	    	}
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
        // system("walk_trau.exe");
        system("walk.exe"); 
        // if(system("fc " TASK ".OUT " TASK ".ANS")!=0)
        // {   
        //     cout<<"Test "<<i<<" WA"<<"\n";
        //     return  0 ; 
        // }
        // cout<<"Test "<<i<<" AC"<<"\n";
    }
}