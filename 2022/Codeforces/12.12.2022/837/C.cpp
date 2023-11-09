/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "C"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
#define pii pair<int,int>
#define vi vector<int> 
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
void IOS()
{
    fast 
    srand(time(0)) ;
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =1e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ,a[N];
int nt[N] ;
vector<int>prime ;
void snt()
{
	nt[1]=nt[0]=-1 ; 
	FOR(i,2,(int)sqrt(1e9+5))
	{
		if(nt[i]==0)
		{
			nt[i] = i ; 
			prime.pb(i) ; 
			for(int j=i*i;j<=(int)sqrt(1e9+5);j+=i)
			{
				nt[j] = i ; 
			}
		}	
	}
}
void doc()
{
    cin>> n; 
    FOR(i,1,n)cin>>a[i] ; 
}	
void xuly()
{
	unordered_map<int,bool>dd; 			
	ll div=  2;
	bool ok =0 ; 
    FOR(i,1,n)
    {
    	int k = a[i] ; 
    	for(auto x : prime)
    	{
    		if(k%x==0)
    		{
    			while(k%x==0)
	    		{
	    			k/=x;
	    		}
	    		if(dd[x])
	    		{
	    			cout<<"YES"<<'\n';
	    			return ; 
	    		}
	    		else dd[x] =1; 
	    	}
    	}
    	if(k>1&&dd[k])
    	{
    		cout<<"YES"<<'\n';
    		return ; 
    	}
    	if(k>1)dd[k]=1;  
    }
	cout<<"NO"<<'\n';
}
int main()
{
    IOS(); 
    snt(); 
    int test ;cin>>test ; 
    while(test--)
    {
    	doc() ; 
    	xuly() ;
    } 
   	return 0 ; 
}