#include<bits/stdc++.h>
using namespace std;
const int N = 5e4+5;
const long long INF = 1e18; 
int n, costOneShot, numRound, query; 
struct Gun
{
	int position , range, cost;
}GunAtRound[N]; 
long long res[N] ;
struct QueryType
{
	int id ; 
	int round, start, end;
	bool operator<(const QueryType& other)const
	{
		return round < other.round; 
	}
}Query[N]; 
void doc()
{
	cin >> n >> costOneShot >> numRound >> query;
	for (int i = 1; i <= numRound; i++)
	{
		cin >> GunAtRound[i].position>> GunAtRound[i].range >> GunAtRound[i].cost;
	}
	for (int i = 1; i <= query; i++)
	{
		cin >> Query[i].round >> Query[i].start >> Query[i].end; 
		Query[i].end += Query[i].start; 
		Query[i].id= i ; 
	}
}
namespace sub1
{
	vector<Gun> GunsAt[N];
	void add(Gun gun)
	{
		GunsAt[gun.position].emplace_back(gun); 
	}
	long long F[N]; 
	long long  solve(int start, int end)
	{
		for (int i = start; i <= end; i++)
		{
			F[i] = INF; 
		}
		F[start] = 0; 
		for (int i = start; i <end; i++)
		{
			F[i + 1] = min(F[i + 1], F[i] + costOneShot); 
			for (auto& [position , range ,cost] : GunsAt[i])
			{
				for (int j = 1; j <= range; j++)if(i+j<=n)
				{
					F[i + j] = min(F[i + j], F[i] + cost); 
				}
			}
		}	
		return F[end]; 
	}
	void xuly()
	{
		sort(Query + 1, Query + query + 1);
		
		int holder = 1; 
		for (int i = 1; i <= query; i++)
		{
			while (holder <= Query[i].round)
			{
				add(GunAtRound[holder]);
				++holder; 
			}
			res[Query[i].id] = solve(Query[i].start,Query[i].end) ; 
		}
		for(int i=1;i<=query;i++)
		{
			cout<<res[i]<<endl; 
		}
	}
}
namespace sub2
{

	vector<Gun> GunsAt[N];
	long long F[N]; 
	long long  solve(int start, int end)
	{
		for (int i = start; i <= end; i++)
		{
			F[i] = INF; 
		}
		F[start] = 0; 
		for (int i = start; i <end; i++)
		{
			F[i + 1] = min(F[i + 1], F[i] + costOneShot); 
			for (auto& [position , range ,cost] : GunsAt[i])
			{
				for (int j = 1; j <= range; j++)if(i+j<=n)
				{
					F[i + j] = min(F[i + j], F[i] + cost); 
				}
			}
		}	
		return F[end]; 
	}
	long long temp[5][5] ; 
	struct Block
	{	
		long long cost[5][5] ; 
		int l ,r ; 
		Block(int l =0,int r=0 ):l(l),r(r) 
		{
			for(int i=0;i<5;i++)for(int j=0;j<5;j++)cost[i][j] = INF ; 
		}
		int size()
		{
			return r-l+1 ;
		}
		friend Block operator+(Block left,  Block right)
		{
			for(int midl = 0 ;midl<min(5,left.size());midl++)
			{
				for(int midr=0;midr<min(5,right.size());midr++)
				{
					temp[midl][midr] =  solve(left.r-midl,right.l+midr) ; 
				}
			}
			Block res(left.l,right.r) ; 
			res.l=left.l; 
			res.r=right.r; 

			for(int i=0;i<min(5,left.size());i++)
			{
				for(int j=0;j<min(5,right.size());j++)
				{
					for(int midl = 0 ;midl<min(5,left.size());midl++)
					{
						for(int midr=0;midr<min(5,right.size());midr++)
						{
							res.cost[i][j] =  min(res.cost[i][j],left.cost[i][midl]+right.cost[midr][j]+temp[midl][midr]);
						}
					}
				}
			}
			for(int i=left.size();i<5;i++)
			{
				for(int j=0;j<min(5,right.size());j++)
				{
					res.cost[i][j] = min(res.cost[i][j],right.cost[i-left.size()][j]) ; 
				}
			}
			for(int i=0;i<min(5,left.size());i++)
			{
				for(int j=right.size();j<5;j++)
				{
					res.cost[i][j] = min(res.cost[i][j],left.cost[i][j-right.size()]); 
				}
			}
			return res ; 
		} 
	};  
	Block Tree[4*N] ; 
	void build(int id ,int l , int r )
	{
		if(l==r)
		{
			Tree[id]  = Block(l,l) ; 
			Tree[id].cost[0][0] = 0 ; 
			return ; 
		}
		int mid = (l+r)>>1 ;
		build(id<<1,l,mid) ; 
		build(id<<1|1,mid+1,r) ; 
		Tree[id] = Block(l,r) ; 
		for(int i=0;i<min(5,(r-l+1));i++)
		{
			for(int j=0;j<min(5,r-l+1);j++)
			{
				if(l+i<=r-j)
				{
					Tree[id].cost[i][j] = 1ll*((r-j)-(l+i))*costOneShot;
				}
			}
		}
	}
	void update(int id , int l ,int r , int pos)
	{
		if(l==r)return ; 
		int mid = (l+r)>>1 ; 
		if(pos<=mid)
		{
			update(id<<1,l,mid,pos) ; 
		}
		else update(id<<1|1,mid+1,r,pos) ; 
		Tree[id] =  Tree[id<<1]+Tree[id<<1|1] ; 
	}
	Block get(int id ,int l, int r,int t ,int p )
	{
		if(t<=l&&r<=p)return Tree[id]  ; 
		int mid = (l+r)>>1 ; 
		if(p<=mid)return get(id<<1,l,mid,t,p) ; 
		if(mid+1<=t)return get(id<<1|1,mid+1,r,t,p) ; 
		return get(id<<1,l,mid,t,p) + get(id<<1|1,mid+1,r,t,p) ; 
	}
	void add(Gun gun)
	{
		GunsAt[gun.position].emplace_back(gun); 
		update(1,0,n,gun.position) ; 
	}

	void xuly()
	{
		build(1,0,n); 
		sort(Query + 1, Query + query + 1);
		
		int holder = 1; 
		
		for (int i = 1; i <= query; i++)
		{
			while (holder <= Query[i].round)
			{
				add(GunAtRound[holder]);
				++holder ; 
			}
			// if(Query[i].id==1)
				res[Query[i].id] = get(1,0,n,Query[i].start,Query[i].end).cost[0][0] ; 
		}
		for(int i=1;i<=query;i++)
		{
			cout<<res[i]<<endl; 
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0) ; 

	doc();
	// if (max({ n, numRound, query }) <= 2000)sub1::xuly();
	sub2::xuly() ; 
}