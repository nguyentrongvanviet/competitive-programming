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
    ofstream cout(TASK".INP") ; 
    int n = 5000 ;
    cout<<n<<el; 
    FOR(i,1,n)
    {
    	cout<<rd(1,100)<<" ";
    }
    cout<<el;
    int q = 1000;  
  	cout<<q<<el; 
  	FOR(i,1,1)
  	{
  		int type  =rd(2,2) ;
  		int l =rd(1,n) ; 
  		int r = rd(l,n) ; 
  		cout<<type<<" "<<l<<" "<<r<<" ";
  		if(type==2)
  		{
  			cout<<rd(1,50)<<" "<<rd(1,50)<<el;
  		}
  		else cout<<el;
  	}
  	FOR(i,1,q-1)
  	{
  		int type  =rd(1,1) ;
  		int l =rd(1,n) ; 
  		int r = rd(l,n) ; 
  		cout<<type<<" "<<l<<" "<<r<<" ";
  		if(type==2)
  		{
  			cout<<rd(1,50)<<" "<<rd(1,50)<<el;
  		}
  		else cout<<el;
  	}
    cout.close();
}

signed main()
{   
    srand(time(0)) ; 
    FOR(i,1,T)
    {
        create(); 
        system("truy_van_max""_trau.exe");
        system("truy_van_max"".exe"); 
        if(system("fc " TASK ".OUT " TASK ".ANS")!=0)
        {   
            cout<<"Test "<<i<<" WA"<<"\n";
            return  0 ; 
        }
        cout<<"Test "<<i<<" AC"<<"\n";
    }
}