#include<bits/stdc++.h>
using namespace std;

#define TASK "VMSUBSTR"
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
const int N =1e6+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n ; 
int a[N] ; 
int f[300][300];
int dd[300] ;
void doc()
{
 	cin>> n;   
 	FOR(i,1,n)
 	{
 		char x ; 
		cin>>x ; 
		a[i] = x ; 
		f[a[i-1]][a[i]]++;
 	}   
 	f['A'-1][a[1]]++;
 	int q ; 
 	cin>>q; 
 	FOR(i,1,q)
 	{
 		string s; cin>> s;
 		for(int i= 'A';i<='z';i++)dd[i] =0;
 		FOR(i,0,(int)s.size()-1)
 		{
 			dd[s[i]] = 1 ; 
 		}
 		int res = 0 ; 
 		FOR(u,'A'-1,'z')
 		{
 			FOR(v,'A','z')
 			{
 				if(dd[u]==0&&dd[v])
 				{
 					res+=f[u][v];
 				}
 			}
 		}
 		cout<<res<<"\n";
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