
/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "A"

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
int a[N] ; 
void doc()
{
    cin>> n; 
    ll s= 0 ;
    FOR(i,1,n)
    {
    	cin>>a[i] ; 
    	s+=a[i ]; 
    }
    if(s%2==0)
    {
    	cout<<0<<'\n';
    }
    else
    {
    	int ans =oo ; 
    	FOR(i,1,n)
    	{
    		int x= a[i]&1;
    		int cnt =0  ;   
    		while((a[i]&1)==x&&a[i]!=0)++cnt ,a[i]/=2;
    		if((a[i]&1)!=x)
    		{
    			ans =min(ans,cnt);
    		}
    	}
    	cout<<ans<<'\n';
    }
}
void xuly()
{
    
}
int main()
{
    IOS();  
    int test ;
    cin>>test ; 
    while(test--)
    {
    	doc();
    }
     
    xuly();
}