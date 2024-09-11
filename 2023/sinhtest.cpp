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
const int N = 5e5+5 ;
int L[N] ; 
void create()
{
    ofstream cout(TASK".INP");
    int n = 5e5 , m = 24 , q = 5e5 ;
    cout<<n<<" "<<m<<" "<<q<<el; 
    int sum = 5e5 ; 
    FOR(i,1,m-1)
    {
    	int len =rd(1,sum-m+i) ;
    	sum-=len; 
    	cout<<len<<" ";
    	L[i] = len ; 
    	FOR(j,1,len)cout<<rd(0,5)<<" ";
    	cout<<el; 
    }
    cout<<sum<<el;
    int len =sum ;
	sum-=len; 
	L[m] = len ; 
	FOR(j,1,len)cout<<rd(0,5)<<" ";
	cout<<el; 
    FOR(i,1,q)
    {
    	int type =rd(1,3) ;
    	cout<<type<<" ";
    	if(type==1)
    	{
    		int t =rd(1,m) ; 
    		int p = rd(1,n-L[t]+1) ; 
    		cout<<t<<" "<<p<<el;
    	}
    	else if(type==2)
    	{
    		cout<<rd(1,n)<<el; 
    	}
    	else
    	{
    		int id = rd(1,m) ; 
    		cout<<id<<" ";
            // int l = 1,  r= 1 ;
    		int l =rd(1,L[id]) ;
    		int r = rd(l,L[id]) ; 
    		cout<<l<<" "<<r<<el; 
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
        // system("DORA""_trau.exe");
        system("DORA"".exe"); 
        cout<<"TEST "<<i<<" OK"<<el;
        // if(system("fc " TASK ".OUT " TASK ".ANS")!=0)
        // {   
        //     cout<<"Test "<<i<<" WA"<<"\n";
        //     return  0 ; 
        // }
        // cout<<"Test "<<i<<" AC"<<"\n";
    }
}