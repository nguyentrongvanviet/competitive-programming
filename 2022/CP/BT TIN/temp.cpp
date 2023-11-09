#include<bits/stdc++.h>
#define fi "i.txt"
#define fo "o.txt"
#define ll long long
#define pb push_back
#define FOR(i,a,b) for( int i=a;i<=b;i++)
#define FORN(i,a,b) for( int i=a;i<b;i++)
#define FORG(i,a,b) for( int i=a;i>=b;i--)
using namespace std;
const ll oo=1e16;
const int N=1e6+5;

int n,q,a[N],sm=1e9+7,res[N];
map<int,int> f[33];

void doc(){
	cin>>n>>q;
	FOR(i,1,n)cin>>a[i];

}
void xuly()
{
	// f[0][0]=1;

	FOR(i,1,n)
	{
		f[1][a[i]]=(f[1][a[i]]+1)%sm;
		if(a[i]%q==0)
		FOR(j,2,min(n,32))
		{
			{
				f[j][a[i]]=(f[j][a[i]]+f[j-1][a[i]/q])%sm;
			}
		}
	}
	FOR(i,2,min(n,32))
	{
		map<int,int> :: iterator it;
		for(it=f[i].begin();it!=f[i].end();it++)res[i]=(res[i]+it->second)%sm;
	}
	FOR(i,2,n)cout<<res[i]<<'\n';
}
int main()
{
	freopen( fi, "r" , stdin );
	freopen( fo, "w" , stdout );

	ios_base:: sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int t;
	// cin>>t;
	t=1;
	while(t--)
	{
		doc();
		xuly();
	}

	return 0;
}