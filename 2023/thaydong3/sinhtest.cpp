#define TASK  "text"
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
const int MAX = 5e5;
void create()
{
    ofstream cout(TASK".INP");
    int n = 1e3 , q= 1e3 ; 
    cout<<n<<" "<<q<<el; 
    FOR(i,1,n)
    {
    	cout<<rd(0,MAX)<<" ";
    }
    cout<<el;
    int pos = n; 	
    FOR(i,1,q)
    {
    	int type =rd(1,6); 
    	if(pos==1&&type==2)type=1 ;
    	cout<<type<<" ";
    	if(type==1)
    	{
    		cout<<rd(1,MAX)<<el;
    	}
    	if(type==2)
    	{
            --pos;
    		cout<<el ;
    	}
    	if(type==3)cout<<rd(1,MAX)<<el;
    	if(type>3)
    	{
    		int l =rd(1,pos) ;
    		int r = rd(l,pos)  ;
    		cout<<l<<" "<<r<<" ";
    		if(type==6)cout<<rd(1,r-l+1)<<el;
    		else cout<<rd(0,MAX)<<el;
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
        system("LQUERY""_trau.exe");
        system("LQUERY"".exe"); 
        if(system("fc " TASK ".OUT " TASK ".ANS")!=0)
        {   
            cout<<"Test "<<i<<" WA"<<"\n";
            return  0 ; 
        }
        cout<<"Test "<<i<<" AC"<<"\n";
    }
}