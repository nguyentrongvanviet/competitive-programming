#include<bits/stdc++.h>
#define MAX   100005
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
#define TASK "walk"
using namespace std;
const int INF=(int)1e9+7;
typedef pair<int,int> ii;
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
void minimize(int &x,const int &y) {
	if (x>y) x=y;
}
class MaxFlowMinCost {
	public:
	struct edge {
		int from,to,capa,flow,cost;
		edge() {
			from=0;to=0;capa=0;flow=0;cost=0;
		}
		edge(int u,int v,int ca,int co) {
			from=u;to=v;capa=ca;flow=0;cost=co;
		}
		int residual(void) const {
			return (capa-flow);
		}		
	};
	vector<vector<int> > g;
	vector<edge> e;
	vector<int> d,tr;
	int n;	
	MaxFlowMinCost() {
		n=0;
	}
	MaxFlowMinCost(int n) {
		this->n=n;
		g.assign(n+7,vector<int>());
		e.clear();
		d=vector<int>(n+7);
		tr=vector<int>(n+7);
	}
	void addedge(int u,int v,int ca,int co) {
		g[u].push_back(e.size());
		e.push_back(edge(u,v,ca,co));
		g[v].push_back(e.size());
		e.push_back(edge(v,u,0,-co));
	}
	bool FordBellman(int s,int t) {
		FOR(i,1,n) {
			d[i]=INF;
			tr[i]=-1;
		}
		vector<bool> inq=vector<bool>(n+7,false);
		queue<int> q;
		while (!q.empty()) q.pop();
		q.push(s);d[s]=0;inq[s]=true;
		while (!q.empty()) {
			int u=q.front();q.pop();inq[u]=false;
			FORE(it,g[u]) if (e[*it].residual()>0) {
				int v=e[*it].to;
				if (d[v]>d[u]+e[*it].cost) {
					d[v]=d[u]+e[*it].cost;
					tr[v]=*it;
					if (!inq[v]) {
						q.push(v);
						inq[v]=true;
					}
				}
			}
		}
		return (d[t]<INF);
	}
	ii getflow(int s,int t) {
		int totflow=0;
		int totcost=0;
		while (FordBellman(s,t)) {
			int delta=INF;
			for (int u=t;u!=s;u=e[tr[u]].from) minimize(delta,e[tr[u]].residual());
			for (int u=t;u!=s;u=e[tr[u]].from) {
				e[tr[u]].flow+=delta;
				e[tr[u]^1].flow-=delta;
			}
			totflow+=delta;
			totcost+=delta*d[t];
		}
		return (ii(totflow,totcost));
	}
};
MaxFlowMinCost g;
int n,m,s,t;
queue<int> q[MAX];
void loadgraph(void) {
	scanf("%d",&n);
	scanf("%d",&m);
	s=1 ; 
	t=n;
	g=MaxFlowMinCost(n+1);
	REP(i,m) {
		int u,v,c;
		scanf("%d",&u);
		scanf("%d",&v);
		scanf("%d",&c);
		g.addedge(u,v,1,c);
		g.addedge(v,u,1,c);
	}
	g.addedge(n+1,s,2,0);
}
void process(void) {
	ii res=g.getflow(n+1,t);
	if (res.fi<2) {
		printf("-1");
		return;
	}
	printf("%d\n",res.se);
	FORE(it,g.e) if (it->flow>0 && it->from<=n) q[it->from].push(it->to);
	REP(i,2) {
		vector<int> way;
		way.clear();
		int u=s;
		while (u!=t) {
			assert(!q[u].empty());
			way.push_back(u);
			int v=q[u].front();q[u].pop();
			u=v;
		}
		way.push_back(t);
		// printf("%d",way.size());
		if(i==1)way.pop_back(),reverse(way.begin(),way.end());
		FORE(it,way) printf("%d ",*it);
	}
}

int main(void) {
	IOS();
	loadgraph();
	process();
	return 0;
}