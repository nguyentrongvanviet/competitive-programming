#include<bits/stdc++.h>
using namespace std;

#define TASK "bitproblem"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#pragma CPP target("popcnt")
const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
const int maxN = (1<<21)+5;
int n ; 
int a[N] ;
int freq[1<<22];
int f1[maxN][21],f2[maxN][21] ;
void doc()
{
 	cin>> n; 
 	FOR(i,1,n)cin>>a[i] , freq[a[i]]++;
 	FOR(i,1,(1<<21)-1)
 	{
 		f1[i][0]= freq[i];
 		if(i&1)f1[i][0]+=freq[i^1];
 		FOR(j,1,20)
 		{
 			f1[i][j] = f1[i][j-1];
 			if(i>>j&1)
 			{
 				f1[i][j]+=f1[i^(1<<j)][j-1];
 			}
 		}
 	}   
 	// dem so cau hinh la con cua i 
 	FORD(i,(1<<21)-1,0)
 	{
 		f2[i][0] = freq[i];
 		if(i&1^1)
 		{
 			f2[i][0] +=freq[i^1];
 		}
 		FOR(j,1,20)
 		{
 			f2[i][j]  =f2[i][j-1] ;
 			if(i>>j&1^1)
 			{
 				f2[i][j] +=f2[i^(1<<j)][j-1];
 			}
 		}
 	}
 	FOR(i,1,n)
 	{
 		// cout<<bitset<20>(a[i])<<" ";
 		// cout<<bitset<20>((((1<<21)-1)^a[i]))<<" ";
 		cout<<f1[a[i]][20]<<" "<<f2[a[i]][20]<<" "<<n-f1[((1<<21)-1)^a[i]][20]<<"\n";
 	}
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
 	   }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}