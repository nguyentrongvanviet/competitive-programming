// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "Number_reduction"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
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

const int N =5e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n , k ;
int a[N] ;
int la[N][10] ; 
void doc()
{		 
	string s; cin>>s ;
	n = s.size(); 
    s=' '+s+' '; 
    FOR(i,1,n)
    { 
    	a[i]=s[i]-'0';
    }
    cin>>k; 
    FOR(i,0,9)la[n+1][i]=0; 
    FORD(i,n,1)
    {
    	FOR(j,0,9)la[i][j]=la[i+1][j];
    	la[i][a[i]]=i; 
    }
    int scs = n - k; 
   	// first number
   	int cur; 
   	FOR(j,1,9)
   	{
   		int x = la[1][j] ;
   		if(x!=0&&x-1<=k)
   		{
   			cout<<a[x]; 
   			k-=x-1;  
   			cur=  x ; 
   			break ;
   		}
   	}
   	FOR(i,2,scs)
   	{
   		++cur ;
   		FOR(j,0,9)
   		{
   			int x =la[cur][j] ;  
   			if(x!=0&&x-cur<=k)
   			{
   				// cout<<cur<<" "<<x<<" "<<j<<" "<<k<<endl;
   				cout<<j;
   				k-=x-cur; 
   				cur = x; 
   				break; 
   			}
   		}
   	}
   	cout<<"\n";

}
void xuly()
{
    
}
int main()
{
    IOS();  
    int test ;
    cin>>test; 
    while(test--)
    {
    	doc(); 
    	xuly();
    }
}