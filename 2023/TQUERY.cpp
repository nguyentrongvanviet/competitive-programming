
// Author: Nguyen Quoc Phu Dep Trai	
#define TASK "test"
#include<bits/stdc++.h>
using namespace std; 

bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db long double
#define mp make_pair
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin())
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define pt pop_front
#define pf push_front
#define el '\n'
#define f(i,a,b) for(int i=(a);i<=(b);i++)
#define fd(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
#define            tct  template<typename T>
#define BIT ((x>>i)&1)
#define MASK(x) (1<<(x))

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){f(i,1,n)cout<<a[i]<<" ";cout<<el;}
const ll INF=(ll)1e18 + 7LL;
const int N =2e5*30, maxN=20, oo = 2e9, CH = 26 , size = 1e3 +5;
const ll sm = 1e9+7, base=311, inf = 1e18 , MOD=1e9+7 , LG=30;
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
// end template 


// ll num[N],low[N],timeDFS=0,tplt=0,was[N],tp[N],child[N]; // DFS
// ll up[N][20],h[N],dist[N][20],mi[N][20],ma[N][20],par[N]; //LCA

multiset<ll>save;
ll tr[N+5][3],sl[N+5],s[N+5],q,node=1;
void read()
{
	cin>>q;
}
void add(ll val){
	ll r=1;
	s[r]+=val;
	sl[r]++;
	fd(j,LG,0){
		ll v=val>>j&1;
		if(tr[r][v]==0) tr[r][v]=++node;
		r=tr[r][v];
		s[r]+=val;
		sl[r]++;
	}
}
void erase(ll val){
	if(save.find(val)==save.end()) return;
	save.erase(save.find(val));
	ll r=1;
	s[r]--;
	sl[r]-=val;
	fd(j,LG,0){
		ll v=val>>j&1;
		r=tr[r][v];
		sl[r]--;
		s[r]-=val;
	}
}
ll sum(ll val){
	ll r=1; ll res=0;
	fd(j,LG,0){
		ll v=val>>j&1;
		if(v==0&&tr[r][v^1]!=0&&sl[tr[r][v^1]]>=1) res+=s[tr[r][v^1]];
		r=tr[r][v];
	}
	res+=s[r];
	return res;
}
ll ptbk(ll val){
	ll r=1; ll res=val; ll ans=0;
	fd(j,LG,0){
		ll L=tr[r][0]; ll R=tr[r][1];
		if(sl[L]>=res&&L!=0&&sl[L]>=1) r=L;
		else {
			res-=sl[L];
			ans+=(1<<j);
			r=R;
		}
	}
	return ans;
}
ll maxxor(ll val){
	ll r=1; ll res=0;
	fd(j,LG,0){
		ll v=val>>j&1;
		if(tr[r][v^1]!=0&&sl[tr[r][v^1]]>=1){
			res+=(1<<j);
			r=tr[r][v^1];
		}
		else r=tr[r][v];
	}
	return res;
}
void solve()
{
	while(q--)
	{
		ll type,x,L,R;
		cin>>type;
		if(type==1){
			cin>>x;
			add(x);
			save.insert(x);
		}
		else if(type==2){
			cin>>x;
			erase(x);
		}
		else if(type==3){
			cin>>L>>R;
			// cout<<sum(L)<<" "<<sum(R)<<el;
			cout<<sum(L)-sum(R+1)<<el;
		}
		else if(type==4){
			cin>>x;
			cout<<ptbk(x)<<el;
		}
		else {
			cin>>x;
			cout<<maxxor(x)<<el;
		}
	}
}

signed main()	
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen(TASK".INP", "r"))
	{
		freopen(TASK".INP", "r", stdin);
		freopen(TASK".OUT", "w", stdout);
	}
	fast;
    int test =1; 
  //  cin>>test;
   while(test--)
    {
        read(); 
        solve();
    }
    cerr << "\nTime: " << clock() << "ms\n";
}