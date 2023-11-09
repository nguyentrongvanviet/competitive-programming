// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;
 
#define TASK "prefix_function_query"
 
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
 
const int N =1e6+12 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ; 
const int CH = 26 ; 
int n ; 
int a[N] ; 
string s; 
int A[N][CH+5];
void doc()
{
    cin>>s ; 
   	n = s.size() ;
    FOR(i,0,n-1)a[i] =s[i]; 
}
vi KMP(int a[],  int n )
{
	vi z(n) ; 
	for(int i= 1 ;i<n;i++)		
	{
		int j=z[i-1]; 
		while(j&&a[j]!=a[i])
		{
			j=z[j-1];
		}  
		if(a[j]==a[i])++j ;
		z[i] = j;
	}
	return z; 
}
void xuly()
{
	vi z = KMP(a,n);
	FOR(i,0,n)
	{
		FORN(j,0,CH)
		{	
			if(i&&a[i]-'a'!=j)
			{
				A[i][j] = A[z[i-1]][j];
			}
			else 
			{
				A[i][j] =i +(a[i]-'a'==j);
			}
		}
	}
    int q; cin>>q; 
    while(q--)
    { 
    	cin>>s ; 
    	int m = s.size(); 
    	FOR(i,n,m+n-1)
    	{
    		FORN(j,0,CH)
    		{
    			if(j!=s[i-n]-'a')
    			{
    				A[i][j] =A[z[i-1]][j];
    			}
    			else 
    			{
    				A[i][j] = i+(j==s[i-n]-'a');
    			}
    		}
      		z.pb(A[z[i-1]][s[i-n]-'a']);
    		cout<<z[i]<<" ";
    	}
    	FOR(i,1,m)z.pk();
    	cout<<"\n";
    }
}	
int main()
{
    IOS();  
    doc(); 
    xuly();
}