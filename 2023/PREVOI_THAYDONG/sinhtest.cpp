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
    int n =200 ; 
    cout<<n<<" "<<rd(1,100)<<el; 
    FOR(i,1,n)
    {
    	int type =rd(1,2) ;
    	if(type==1)
    	{
    		cout<<rd(-1e9,0)<<" ";
    	}
    	else cout<<rd(0,1e9)<<" ";
    }
    cout<<el; 
    FOR(i,1,n)
    {
    	int type =rd(1,2) ;
    	if(type==1)
    	{
    		cout<<rd(-1e9,0)<<" ";
    	}
    	else cout<<rd(0,1e9)<<" ";
    }
    cout<<el;
    cout.close();
}

signed main()
{   
    srand(time(0)) ; 
    FOR(i,1,T)
    {
        create(); 
        system("FROG""_trau.exe");
        system("FROG"".exe"); 
        if(system("fc " TASK ".OUT " TASK ".ANS")!=0)
        {   
            cout<<"Test "<<i<<" WA"<<"\n";
            return  0 ; 
        }
        cout<<"Test "<<i<<" AC"<<"\n";
    }
}