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

int n  ,m ; 
int x;  
int a[N] ; 
int bit[N] ; 
void up(int idx,int val)
{
	for(int i=idx;i<=(2e5);i+=i&-i)
	{
		bit[i]+=val; 
	}
}
int get(int idx   )
{
	int ans= 0 ;
	for(int i=idx;i;i-=i&-i)
	{
		ans+=bit[i] ; 
	}
	return ans;  
}
void doc()
{
    cin>> n >> x ; 
    FOR(i,1,n)cin>>a[i],a[i] = (a[i]>=x); 
    cin>>m ;
    int cur = n ;
    int head =1 ;   
    FOR(i,1,n)
    {	
    	if(a[i])up(i,1);
    }
  	FOR(i,1,m)
  	{
  		int t; 
  		cin>>t; 
  		if(t==1)
  		{
  			int val ; 
  			cin>>val; 
  			++cur;
  			a[cur] = (val>=x); 
  			if(a[cur])up(cur,1); 
  		}
  		else if(t==2) 
  		{
  			if(a[head])up(head,-1);
  			a[head] =0 ;  
  			++head;   			
  		}
  		else if(t==3)
  		{
  			int pos ; 
  			cin>>pos; 
  			++pos; 
  			if(head+pos-2>=0)cout<<get(head+pos-2)<<'\n';
  			else cout<<0<<"\n";
  			// cout<<get(head+pos-1)<<'\n';
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