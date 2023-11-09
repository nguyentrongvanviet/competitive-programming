#include <bits/stdc++.h>
using namespace std;

#define TASK "astr2"
const bool multitest = false; 
const int T =100;
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));; 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
#define pii pair<int,int>
#define vi vector<int>
#define ve vector
#define str string  
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b)  a/gcd(a,b)*b 
using namespace std;

const int N =2e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

ll rd(ll l , ll r )
{
    return l +1LL*rand()%(r-l+1);
}
void create()
{
    ofstream cout(TASK".INP");

    int n= 4 ; 
    int k = rd(1,4) ;
    cout<<4<<" "<<k<<endl; 
    FOR(i,1,k)
    {
    	int k =rd(1,n) ; 
    	FOR(j,1,k)
    	{
    		cout<<rd(0,1);
    	}
    	cout<<endl;
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