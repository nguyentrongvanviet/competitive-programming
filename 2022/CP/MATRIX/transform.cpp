/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "transform"

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

const int N =300+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  


string s ; 
int n , m ; 
int   f[N][N]; 
int g[CH][CH];
void doc()
{
	cin>>s;
	m = s.size() ;
	s='$'+s; 
	cin>>n; 
	// memset(g,-1,sizeof(g));
	FOR(i,1,n)
	{
		char x ; cin>>x ;
		x-='a' ; 
		char p , q; cin>>p>>q; 
		p-='a' ; 
		q-='a';
		g[p][q]|=(1<<x);
	}
}
int dd[N][N] ; 
int W[4][4][1<<7][1<<7];
int at1[4] ,at2[4] ;
ll tinh(int l , int r )
{

	if(l==r)return (f[l][r] |= (1<<(s[l]-'a'))); 
	if(dd[l][r])return f[l][r] ; 
	dd[l][r] =1; 
	ll res = 0;
	FOR(mid,l,r-1)
	{
		ll msk1  = tinh(l,mid) ; 
		ll msk2 =tinh(mid+1,r) ; 
		// FORN(i,0,CH)
		// {
		// 	FORN(j,0,CH)
		// 	{
		// 		if((mask1>>i&1) &&(mask2>>j&1))
		// 		{
		// 			res|=g[i][j]; 
		// 		}
		// 	}
		// }
		FOR(i,0,3)
		{
			at1[i] = msk1%128;
			at2[i] = msk2%128;
			msk1>>=7; 
			msk2>>=7;
		}
		FOR(i,0,3)
		{
			FOR(j,0,3)
			{
				res|=W[i][j][at1[i]][at2[j]];
			}
		}
	}

	return f[l][r]=res; 
}
void xuly()
{
	FOR(i,0,3)
	{
		FOR(j,0,3)
		{
			FOR(msk1,0,128)
			{
				FOR(msk2,0,128)
				{
					FOR(c1,0,6)
					{
						FOR(c2,0,6)
						{
							if((msk1>>c1&1)&&(msk2>>c2&1))
							{
								W[i][j][msk1][msk2]|=g[i*7+c1][j*7+c2];
							}
						}
					}	
				}
			}
		}
	}
    ll res= tinh(1,m) ;
    FORN(i,0,CH)
    {
    	if(res>>i&1)
    	{
    		cout<<(char)(i+'a');
       	}
    }
    if(res==0)cout<<"No Solution.";
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}