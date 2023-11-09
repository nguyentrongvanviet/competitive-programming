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
    int T = 1 ;
    cout<<T<<el;
    while(T--)  
    {
	    int n= rd(1,6) ;
	    cout<<n<<el; 
	    int a[5] = {0,1,2,3,0} ; 
	    random_shuffle(a+1,a+3+1) ; 
	    FOR(i,1,3)cout<<a[i]<<" ";
	    cout<<el;
	    FOR(i,1,n-1)
	    {	
	    	cout<<i<<" "<<rd(i+1,n)<<el;
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
        system("KTHMAX""_trau.exe");
        system("KTHMAX"".exe"); 
        if(system("fc " TASK ".OUT " TASK ".ANS")!=0)
        {   
            cout<<"Test "<<i<<" WA"<<"\n";
            return  0 ; 
        }
        cout<<"Test "<<i<<" AC"<<"\n";
    }
}