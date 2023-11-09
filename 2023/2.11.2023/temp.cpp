// O(n*log(n)*log(MAX) + q*log(MAX))
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int maxn = 200005;
const int lgn = 18;
const int depth = 20;

struct Node{
    int l, r, id;
};

Node trie[maxn*lgn*depth];
vector<int> g[maxn];
int sz[maxn], root[maxn], val[maxn], st[maxn], en[maxn], vert[2*maxn];
int ptr, tptr;

void dfs(int v, int p){
    sz[v] = 1;
    vert[tptr] = v;
    st[v] = tptr++;
    for(auto u : g[v]){
        if(u != p){
            dfs(u, v);
            sz[v] += sz[u];
        }
    }
    vert[tptr] = v;
    en[v] = tptr++;
}

void clear(int v){
    trie[v].l = trie[v].r = trie[v].id = 0;
}

int update(int v, int k, int id){
	clear(ptr);
	int nv = ptr++;
	trie[nv] = trie[v];
	int ret = nv;
	for(int i = depth - 1; i >= 0; i--){
		clear(ptr);
		if((k>>i)&1){
			trie[nv].r = ptr++;
			trie[trie[nv].r] = trie[trie[v].r];
			nv = trie[nv].r;
			v = trie[v].r;
		}else{
			trie[nv].l = ptr++;
			trie[trie[nv].l] = trie[trie[v].l];
			nv = trie[nv].l;
			v = trie[v].l;
		}
	}
	if(!trie[nv].id)trie[nv].id = id;
	else trie[nv].id = min(trie[nv].id, id);
	return ret;
}

int query(int v, int k){
    for(int i = depth - 1; i >= 0; i--){
        if((k>>i)&1){
            if(trie[v].l)v = trie[v].l;
            else v = trie[v].r;
        }else{
            if(trie[v].r)v = trie[v].r;
            else v = trie[v].l;
        }
    }
    return trie[v].id;
}

void createRoot(int v, int p){
    int bg = -1;
    for(auto u : g[v]){
        if(u != p && (bg == -1 || sz[bg] < sz[u]))bg = u;
    }
    for(auto u : g[v]){
        if(u != p)createRoot(u, v);
    }
    root[v] = (bg == -1)?0:root[bg];
    root[v] = update(root[v], val[v], v);
    for(auto u : g[v]){
        if(u == p || u == bg)continue;
        for(int i = st[u]; i < en[u]; i++){
            int w = vert[i];
            if(st[w] == i){
                root[v] = update(root[v], val[w], w);
            }
        }
    }
}

void solve(){
    int n, q, u, v, k;
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        cin>>val[i];
        g[i].clear();
    }
    for(int i = 1; i < n; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    ptr = tptr = 1;
    trie[0].l = trie[0].r = trie[0].id = 0;
    createRoot(1, -1);
    int last_answer = 0, last_node = 0;
    while(q--){
        cin>>v>>k;
        v ^= last_node;
        k ^= last_answer;
        last_node = query(root[v], k);
        last_answer = val[last_node]^k;
        cout<<last_node<<" "<<last_answer<<'\n';
    }
}

int main(){
 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)solve();
}