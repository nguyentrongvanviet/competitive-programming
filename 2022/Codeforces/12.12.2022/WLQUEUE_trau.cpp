/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "WLQUEUE"

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

int n  ,  x, m ; 
int a[N] ; 
void doc()
{
 	cin>>n >>x; 
 	FOR(i,1,n)cin>>a[i] ; 
 	int cur =1 ; 
 	FOR(i,1,n)
 	{
 		if(a[i]>=x)
 		{
 			a[i]= 1;  
 		}
 		else 
 		{
 			a[i] = 0 ;
 		}
 	}   
 	cin>>m ; 
 	int head= 1 ; 
 	while(m--)
 	{
 		int t; cin>>t ; 
 		if(t==1)
 		{
 			++n; 
 			int val; 
 			cin>>val; 
 			a[n] =(val>=x);
 		}
 		else if(t==2)
 		{
 			++head ; 
 		}
 		else 
 		{
 			int pos ; 
 			cin>>pos ; 
 			int res=0  ; 
 			FOR(i,head,head+pos-1)
 			{
 				res+=(a[i]==1);
 			}
 			cout<<res<<'\n';
 		}
 	}
}
void xuly()
{
    
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}