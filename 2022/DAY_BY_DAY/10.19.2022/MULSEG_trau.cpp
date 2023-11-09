#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define int long long 
ll mod=1e9+7,n;
struct Node {
    ll lazy = 1;
    ll val = 1; 
} ;
Node nodes[1000006 * 8];
void down(int id) {
    int t = nodes[id].lazy;
    nodes[id*2].lazy = nodes[id*2].lazy*t%mod;
    nodes[id*2].val = t*nodes[id*2].val%mod;

    nodes[id*2+1].lazy = t*nodes[id*2+1].lazy%mod;
    nodes[id*2+1].val = t*nodes[id*2+1].val%mod;

    nodes[id].lazy = 1;
}
void update(int id, int l, int r, int u, int v, ll val) {
    if (v < l || r < u) {
        return ;
    }
    if (u <= l && r <= v) {
        nodes[id].val = val*nodes[id].val%mod;
        nodes[id].lazy = val*nodes[id].lazy%mod ;
        return ;
    }
    int mid = (l + r) / 2;

    down(id); 

    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);

    nodes[id].val = max(nodes[id*2].val, nodes[id*2+1].val);
}
int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return -21132;
    }
    if (u <= l && r <= v) {
        return nodes[id].val;
    }
    int mid = (l + r) / 2;
    down(id); 

    return max(get(id*2, l, mid, u, v),
    get(id*2+1, mid+1, r, u, v));
}
void doc(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll l,r,w,val;
        cin>>val;
        if(val==0){
            cin>>l>>r>>w;
            update(1,1,1e2,l,r,w%mod);
        } else {
            cin>>w;
            cout<<get(1,1,1e2,w,w)<<'\n';
        }
    }
}
signed main(){
    freopen("MULSEG.INP","r",stdin);
    freopen("MULSEG.ANS","w",stdout);  
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    doc();
}