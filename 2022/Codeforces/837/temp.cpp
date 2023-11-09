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
 
const int N =2e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  
 
int n ;
ll a[N]; 			
void doc()
{
    cin>> n; 
    FOR(i,1,n)cin>>a[i] ; 
}	
bool ok  ;
ll uoc;

void xuly()
{
	unordered_map<int,bool>dd; 
    FOR(i,1,n)
    {
    	uoc =2;  
    	while(uoc*uoc<=a[i])
    	{	
    		ok = 0;
    		if(a[i]%uoc==0)
    		{
    			ok =1 ; 
    			while(a[i]%uoc==0)
	    		{
	    			a[i]/=uoc; 
	    		}
	    	}
	    	if(ok)
	    	{
	    		if(dd.find(uoc)!=dd.end())
	    		{
	    			cout<<"YES"<<'\n'; 
	    			return ; 
	    		}
	    		dd[uoc]= 1; 
	    	}
	    	++uoc;
    	}
    	if(a[i]>1)
    	{
    		if(dd.find(a[i])!=dd.end())
    		{
    			cout<<"YES"<<'\n';
    			return ;
    		}
    		dd[a[i]]=1;
    	}
    }
	cout<<"NO"<<'\n';
}
int main()
{
    IOS(); 
    int test ;cin>>test ; 
    while(test--)
    {
    	doc() ; 
    	xuly() ;
    } 
   	return 0 ; 
}