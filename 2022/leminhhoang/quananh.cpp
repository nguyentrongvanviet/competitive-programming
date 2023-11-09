#include<bits/stdc++.h>
#define fi "TASKSELECT.INP"
#define fo "TASKSELECT.OUT"
#define ll long long
#define pb push_back
#define FOR(i,a,b) for( int i=a;i<=b;i++)
#define FORN(i,a,b) for( int i=a;i<b;i++)
#define FORG(i,a,b) for( int i=a;i>=b;i--)
using namespace std;
const ll oo=1e16;
const int N=1e6+5;

int s,sd,k,n;
vector< pair<int,int>> canh;
vector< vector<int> > a,tmp,c;
vector<int> v;
int sm=1e9+7;
void doc(){
	cin>>k>>n;

}
vector< vector<int> > nhan( vector< vector<int> > a, vector< vector<int> > b)
{
	c=tmp;
	FOR(i,0,s)
	FOR(j,0,s)
	{
		FOR(k,0,s)c[i][j]=(c[i][j]+(ll)a[i][k]*b[k][j])%sm;
	}
	return c;
}
vector< vector<int> > po(int n)
{
	if(n==1)return a;
	int mid=n/2;
	vector< vector<int> > x=po(mid);
	vector< vector<int> > y=nhan(x,x);
	if(n%2==1) y=nhan(y,a);
	return y;
}
void taocanh(int u, int v, int w)
{
	FOR(i,1,w-1)
	{
		s++;
		canh.pb({u,s});
		u=s;
	}
	canh.pb({u,v});
}
void xuly()
{
	s=k;
	
	canh.clear();
	a.clear();
	

	 sd=k*k+k+1;
	FOR(i,0,sd)v.pb(0);
	FOR(i,0,sd)a.pb(v);
	tmp=a;
	FOR(i,1,k)
	{
		taocanh(i-1,i,i);
		taocanh(i,i,i);
	}
	FORN(i,0,canh.size())
	{
		a[canh[i].first][canh[i].second]=1;
	}
	vector< vector<int> > b=po(n);
	cout<<b[0][k]<<'\n';
}
int main()
{
	freopen( fi, "r" , stdin );
	freopen( fo, "w" , stdout );

	ios_base:: sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		doc();
		xuly();
	}

	return 0;
}