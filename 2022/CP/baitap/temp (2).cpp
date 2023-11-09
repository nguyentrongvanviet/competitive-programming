#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
#define int long long 
struct edge
{
	int u , v ,w ; 
	bool operator<(const edge& a)const
	{
		return w<a.w; 
	}
};
int sz[N] , pa[N] ,dd[N],s1[N],s2[N] ; 
vector<edge>q;  
int n , m ,W , na , nb ;
ll ans ;
int goc(int u)
{
	return pa[u]==u?u:pa[u]=goc(pa[u]);
}
void hop(int u , int v )
{
	int chau = goc(u) ; 
	int chav =goc(v) ; 
	if(chau == chav)return ; 
	ans+=s1[chau]*s2[chav]+s1[chav]*s2[chau] ; 
	s1[chau]+=s1[chav] ;
	s2[chau]+=s2[chav] ;
	pa[chav]=chau; 
}
void init()
{
	for(int i= 1;i<=n;i++)
	{
		pa[i] = i ; 
		if(dd[i]==1)s1[i]=1; 
		else if(dd[i]==2)s2[i]=1; 
		else s1[i]=s2[i]=0;
	}
}

void input()
{
 	cin>>n>>m>>W>>na>>nb ; 
	for(int i= 1;i<=m;i++)
	{
		int u , v ,w; 
		cin>>u>>v>>w; 
		q.pb({u,v,w}); 
	}   
	sort(all(q));
	for(int i= 1;i<=na;i++)
	{
		int u ; 
		cin>> u ;
		dd[u] =1 ;  
	}
	for(int i= 1;i<=nb;i++)
	{
		int u ; 
		cin>>u ; 
		dd[u]=2 ; 
	}
}
ll solve(int W)
{
	ans= 0 ; 
	init() ; 
	for(int i= 0;i<_sz(q);i++)
	{
		if(q[i].w>W)break ; 
		hop(q[i].u,q[i].v); 
	}
	return ans  ; 
}
void output()
{
    cout<<solve(W)-solve(W-1) ; 
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    // freopen("i.txt","r",stdin); 
    // freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}