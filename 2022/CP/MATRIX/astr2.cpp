/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "astr2"

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

const int N =4e4+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int  k ; 
int node= 1 ; 
string s[N]; 
int T[N][2];
bool leaf[N] ; 
void add(string s )
{
	int r= 1; 
	FORD(i,s.size()-1,0)
	{
		int j= s[i]-'0'; 
		if(T[r][j]==0)
		{
			T[r][j]=++node;  
		}
		r=T[r][j] ; 
	}
	leaf[r] = 1;  
}
ll tinh(int c,  int node )
{
	
}
void doc()
{
    cin>> k; 
    FOR(i,1,k)cin>>s[i],add(s[i]) ;
}
void xuly()
{

	cout<<tinh(0,1)<<"\n";
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}