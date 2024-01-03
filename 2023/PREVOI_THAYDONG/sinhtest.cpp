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
    int n= 100 ,  q=5 ;
    cout<<n<<" "<<q<<el; 
    FOR(i,1,n)
    {
    	cout<<rd(2,10)<<" ";
    }
    cout<<el;
    FOR(i,1,n-1)
    {
        cout<<i<<" "<<rd(i+1,n)<<el;
    }
    FOR(i,1,q)
    {
    	int type =rd(1,2) ;
        type=2; 
        // type=1;
    	cout<<type<<" ";
		int l =rd(1,n-5) ;
		int r = rd(l+1,n) ;
        cout<<l<<" "<<r<<el;
    	if(type==1)
    	{
    		cout<<rd(1,10)<<el;
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
        system("GCDIX""_trau.exe");
        system("GCDIX"".exe"); 
        if(system("fc " TASK ".OUT " TASK ".ANS")!=0)
        {   
            cout<<"Test "<<i<<" WA"<<"\n";
            return  0 ; 
        }
        cout<<"Test "<<i<<" AC"<<"\n";
    }
}