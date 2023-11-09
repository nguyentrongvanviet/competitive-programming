#include<bits/stdc++.h>
using namespace std;

#define TASK "rowboat"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".ANS","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ,m;
int a[N] ; 
int dd[N] ;
void doc()
{
	cin>>n>>m; 
    FOR(i,1,2*n)
    {
    	if(i<=2*m)dd[i]= 1 ;
    	else dd[i] = 0;
    	a[i] = i;
    }
    int res= 0 ; 
    do
    {
    	int x =0  ;
    	for(int i= 1;i<=2*n-1;i++)
    	{
    		if(dd[a[i]]==0)continue;
    		if(a[i]&1)
    		{
    			if(a[i+1]==a[i]+1&&dd[a[i+1]])
    			{
    				x++ ; 
    				break; 
    			}
    		}
    		else 
    		{
    			if(a[i+1]==a[i]-1&&dd[a[i+1]])
    			{
    				x++; 
    				break; 
    			}
    		}
    	}
    	if(x==0)res++ ;
    }while(next_permutation(a+1,a+2*n+1)) ;
    cout<<res<<"\n";
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