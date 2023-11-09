// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "DDNT"

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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ; 
int f[N] , nt[N] ; 
void snt()
{
	nt[1] = -1 ;
	for(ll i = 2; i<=9999;i++)
	{
		if(nt[i]==0)
		{
			nt[i]=i ; 
			for(ll j= i*i;j<=9999;j+=i)
			{
				nt[j]= i;
			}
		}
	}
}
int bfs(int s , int t )
{
	memset(f,0,sizeof(f)) ;
	queue<int>q ; 
	q.push(s) ; 	
	f[s]=1 ; 
	if(s==t)return 1 ;
	while(!q.empty())	
	{
		int u= q.front() ; 
		q.pop() ; 
		for(int i =1 ;i<=4;i++)
		{
			int st= 0 ; 
			if(i==4)st=1 ;
			for(int j =st;j<=9;j++)
			{
				// int v= 0 ;
				int v= u-u/(int)pow(10,i-1)%10*(int)pow(10,i-1)+j*pow(10,i-1);
				if(f[v]||nt[v]!=v)continue ; 
				f[v]= f[u]+1 ; 
				if(v==t)
				{
					return f[v] ; 
				} 	
				q.push(v) ; 
			}
		}
	}
	return -1 ; 
}
void doc()
{
	int a, b ;
    cin>>a>>b; 
    // int res =0 ;
    int res= bfs(a,b) ;
    cout<<res-1<<"\n"; 
}
void xuly()
{	
    
}
int main()
{
    IOS();  
    snt() ;
    int test ;
    cin>>test ;
    while(test--)
    {
    	doc(); 
   		xuly();
    }
    return 0 ; 
}