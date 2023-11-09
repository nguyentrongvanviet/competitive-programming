/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "countbinary"

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
#define vec vector
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

const int N =1e2+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm =998244353,cs=330 ,inf = 1e17  ;  


int n ; 
ll f[N][N][N][2][2] ; 
int g[N][3] ;
void doc()
{
   	cin>> n;  
   	FOR(i,1,n)
   	{
   		FOR(j,i,n)
   		{
   			int x; cin>>x ;
   			if(x==2)
   			{
   				g[j][x]=  max(g[j][x],i) ; 
   			} 
   			else if(x==1)
   			{
   				if(g[j][x]==0||g[j][x]>i)
   				{
   					g[j][x]=  i ; 
   				}
   			}
   		}
   	}
}
ll tinh(int pos ,  int mi1 , int mi2 , int x , int y)
{
	if(f[pos][mi1][mi2][x][y]!=-1)return f[pos][mi1][mi2][x][y] ; 
	if(pos==0)return f[pos][mi1][mi2][x][y]=1 ;  
	ll tmp=  0 ;
	int mii1 = g[pos][1] ; 
	int mii2 = g[pos][2] ; 
	if(mii1)if(mi1==0||mi1>mii1)mi1=mii1; 
	if(mi2)
	{
		if(mi1)
		{
			if(x==y)
			{
				int ok = (mi1<=pos-1) ; 
				tmp =tinh(pos-1,ok,mi2,(ok?x:0),mii2,1-y);
				mi2 =max(mi2,mii2) ; 
				if(pos-1<=mi2)
				{
					tmp= (tmp+tinh(pos-1,ok,mi2))
				}
			}		
			else tmp =0  ;
		}
		else 
		{
			tmp =tinh(pos-1,0,mii2,0,!y);
			if(y<pos)tmp=(tmp+tinh(pos-1,0,mi2,0,y))%sm;
		}
	}
	else
	{
		if(mi1)
		{
			int ok = (mi1<=pos-1);
			int ok2=  (mii2>0);
			tmp=tinh(pos-1,ok,ok2,(ok?x:0),(ok2?1-x:0));  
		}	
		else 
		{
			int ok2= (mii2>0) ; 
			tmp=tinh(pos-1,0,ok2,0,0)+tinh(pos-1,0,ok2,0,1);
		}
	}
	return f[pos][mi1][mi2][x][y] = tmp ; 
}
void xuly()
{
	memset(f,-1,sizeof(f)) ;
 	ll res= tinh(n,0,0,0,0) ;   
 	cout<<res;
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}