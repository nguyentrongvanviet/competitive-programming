#define TASK  "text"
#include<bits/stdc++.h>
const int T  = 100 ; 
using namespace std; 
#define ll long long 
#define db double 
#define el '\n'
#define mp make_pair 
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
    int n = 100 , m = 110;
    int A = rd(1,1e9) ;
    int B =rd(1,1e9) ;
    int C =rd(1,2) ; 
    cout<<n<<" "<<m<<" "<<A<<" "<<B<<" "<<C<<el;
    map<pair<int,int>,int>dd;
    FOR(i,1,n-1)
    {
    	int u = i ;
    	int v= rd(i+1,n) ;
    	cout<<u<<" "<<v<<el;
    }
    FOR(i,1,m-(n-1))
    {
    	while(1)
    	{
	    	int u= rd(1,n) ;
	    	int v =rd(1,n) ;
    		if(u>v)swap(u,v) ; 
    		if(u!=v&&dd.count(mp(u,v))==0)
    		{
    			dd[mp(u,v)]=1;
    			cout<<u<<" "<<v<<el;
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