#include<bits/stdc++.h>
using namespace std;

#define TASK "PIG"
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

struct DL
{
int val;  
int tt;  
};
struct bg 
{
int val; 
int id ;
int tt ;
bool operator<(const bg& a)const
{
	return val<a.val||(val==a.val&&id<a.id); 
} 
};
int n ; 
vector<DL>a[N]; 
vector<bg>q; 
int pos[N*20];
int tt =0 ; 
int bit[N*8];
void up(int idx , int val)
{
	for(int i= idx;i<=tt;i+=i&-i)
	{
		bit[i]=max(bit[i],val);
	}
}  
int get(int idx)
{
	int ans= 0 ; 
	for(int i = idx;i;i-=i&-i)
	{
		ans=max(ans,bit[i]) ; 
	}
	return ans ; 
}
void doc()
{
	cin>> n; 
FOR(i,1,n)
{
	set<int>s; 
	int sz ; 
	cin>>sz ; 
	FOR(j,1,sz)
	{
		int u ; 
		cin>>u ; 
		s.insert(u); 
	}
	for(auto v : s)
	{
		++tt;  
		a[i].pb({v,tt});
		q.pb({v,i,tt});
	}
}
	sort(q.begin(),q.end());
	FOR(i,0,tt-1)
	{
		int id = q[i].tt;  
		pos[id] = i+1;
	}
	int res=0 ; 
	FOR(i,1,n)
	{
		FORD(j,a[i].size()-1,0)
		{
			int tmp = get(pos[a[i][j].tt])+a[i][j].val;
			up(pos[a[i][j].tt],tmp);
			res=max(res,tmp ); 
		}
	}
	cout<<res;
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