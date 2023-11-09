#include<bits/stdc++.h>
using namespace std;

#define TASK ""
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
const int N =3501+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n ; 
string s[5];
int f[N][N][5] ;
void doc()
{
    cin>> n ; 
    for(int i=1;i<=n;i++)cin>>s[i]; 
}
string a , b;  
void solve(int id )
{
	int n = s[1].size() ; 
	int m = s[id].size() ; 
	string b =s[id]; 
	b=" "+b;
	for(int i= 1;i<=n;i++)
	{
		for(int j= 1 ;j<=m;j++)
		{
			if(a[i]==b[j])
			{
				f[i][j][id] = f[i-1][j-1][id]+1; 
			}
			else 
			{
				f[i][j][id] =0  ;
			}
		}
	}
}
void xuly()
{
	a=s[1];
	
	a=" "+a; 
	FOR(i,2,n)
	{
		solve(i);
	}
	int res=  0; 
	FOR(i,1,s[1].size())
	{
		int ma =0  ;
		FOR(j,2,n)
		{	
			FOR(ii,1,s[j].size())
			{
				ma=min(ma,f[i][ii][j]);
			}
		}
		res=max(res,ma);
	}
	cout<<res<<"\n";
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