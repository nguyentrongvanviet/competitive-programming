/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "E"

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

const int N =4e2+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ,m ; 
int a[N][N] ;
int res=0 ;  
int s[N][N];
int sum(int l ,int r ,int h )
{
	return s[h][r]-s[h-1][r]-s[h][l-1]+s[l-1][r-1];
}
void doc()
{
 	cin>> n>> m; 
 	FOR(i,1,n)
 	{
 		FOR(j,1,m)
 		{
 			char x; cin>>x ; 
 			if(x=='m')a[i][j] =1;
 			else if(x=='#')a[i][j] =-n*m-100;
 			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j] ; 
 		}
 	}   
 	FOR(l,1,n)
 	{
 		FOR(r,l+2,n)
 		{	 
 			int medium = 0 , white= 0  ; 
 			int full_white= 0  ;
 			int one_medium  = 0 ;
 			if(a[1][l]+a[1][r]==0)white=1 ;
 			else if(a[1][l]+a[1][r]==1)medium=1; 
 			if(sum(l,r,2)==0)
 			{
 				full_white= 2 ;
 			}
 			else if(sum(l,r,2)==1)
 			{
 				one_medium= 2; 
 			}
 			FOR(i,3,n)
 			{
 				if(a[i][l]<0||a[i][r]<0||(a[i][l]+a[i][r]==2))
 				{
 					medium =  white  = full_white = one_medium =0 ;
 				}
 				else if(a[i][l]+a[i][r]==0) 
 				{
 					if(white!=0&&full_white!=0&&white<full_white)
 					{
 						res=max(res,(i-white+1)+(r-l-1));
 					}
 					else if(medium!=0&&full_white!=0&&medium<=full_white)
 					{
 						res=max(res,(i-medium+1)+(r-l+1));
 					}	
 					else if(one_medium&&white&&one_medium>white)
 					{
 						res=max(res,(i-white+1)+(r-l+1));
 					}
 					if(sum(l,r,i)==0)
 					{
 						all_white = i ;
 					}
 					else if(sum(l,r,i)==1)
 					{
 						one_medium= i ;
 					}
 					if(white==0)white=i;
 				}
 				else if(a[i][l]+a[i][r]==1)
 				{
 					if()
 					if(medium==0)medium=i ; 
 				}	
 			}
 		}
 	}
 	cout<<(res==0?-1:res);
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