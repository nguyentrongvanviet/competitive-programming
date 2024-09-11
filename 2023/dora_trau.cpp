/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define myClass class WORK,class HARD
#define tct template<myClass>
#define ll long long 
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define endl '\n' 
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 5e5 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n,m,q ; 
int s[N] ;
vi vec[N] ; 
struct Queries {
	int type,i,p,l,r,id ;
}Q[N] ;

bool okSub2 = true ;

void init(void) {
	cin >> n >> m >> q ; 
 	FOR(i,1,m) {
		cin >> s[i] ; 
		FOR(j,1,s[i]) {
			int x ; cin >> x ; 
			vec[i].pb(x) ; 
		}
	}
	FOR(i,1,q) {
		int type ; cin >> type ; 
		if(type==1) {
			int I , p ; 
			cin >> I >> p ; 
			Q[i] = {type , I , p , 0 ,  0 , i } ; 
		}else if(type==2) {
			int p ; 
			cin >> p ; 
			Q[i] = {type , 0 , p , 0 , 0 , i} ; 
		}else {
			int I , l , r ;
			cin >> I >> l >> r ; 
			Q[i] = {type , I , 0 , l , r , i } ;
		}
		if(type==3) okSub2 = false ; 
	}
}

namespace sub1 {
	int a[N] ; 
	void solve(void) {
		FOR(i,1,q) {
			int type = Q[i].type ; 
			if(type==1) {
				int vt = Q[i].i ; 
				int p = Q[i].p  ;
				FOR(t,1,s[vt]) {
					a[p + t - 1] = vec[vt][t-1] ;
				}	
			}else if(type==2) {
				int p = Q[i].p ; 
				cout << a[p] << endl ;
			}else {
				int vt = Q[i].i ; 
				int l = Q[i].l ;
				int r = Q[i].r ;
				FOR(t,max(1ll*1,l),min(r,s[vt]) ) {
					vec[vt][t-1] = (vec[vt][t-1] + 1)%256 ; 
				}
			}
		}
	}
}
namespace sub2 {
	
	struct Node {
		int type ; 
		ll sum ;
	}st[4*N] , lazy[4*N] ;

	ll calc(ll l,ll r,ll sub) {
		return (r - l + 1) * (r + l)/2 - (r-l+1) * sub + (r-l+1) ;
	}

	void down(int id,int l,int r) { 
		if(lazy[id].sum==-1) return ;

		int mid = (l+r)>>1 ; 

		st[id<<1].type = st[id].type ;
		st[id<<1|1].type = st[id].type ;

		st[id<<1].sum = calc(l,mid,lazy[id].sum) ; 
		st[id<<1|1].sum = calc(mid+1,r,lazy[id].sum) ;

		lazy[id<<1].type = lazy[id].type ; 
		lazy[id<<1|1].type = lazy[id].type ; 	

		lazy[id<<1].sum = lazy[id].sum ; 
		lazy[id<<1|1].sum = lazy[id].sum ; 

		lazy[id].sum = -1 ; 
	}

	void update(int id,int l,int r,int u,int v,int type) {
		if(l > v or r < u) return ; 
		if(l >= u and r <= v) {
			st[id].type = type ; 
			st[id].sum = (r - l + 1) * (r + l)/2 - (r-l+1) * u + (r-l+1) ;
			lazy[id].type = type ; 
			lazy[id].sum = u ;
			return ; 
		}
		down(id,l,r) ; 
		int mid = (l+r)>>1 ; 
		update(id<<1,l,mid,u,v,type) ; 
		update(id<<1|1,mid+1,r,u,v,type) ; 
		if(st[id<<1].type==st[id<<1|1].type) st[id].sum = st[id<<1].sum + st[id<<1|1].sum ;
		else st[id].sum = 0 ; 
	}	

	Node merge(Node a,Node b) {
		Node ans ; 
		ans.type = max(a.type,b.type) ; 
		ans.sum = a.sum + b.sum ;
		return ans ;
	}

	Node get(int id,int l,int r,int u,int v) {
		if(l > v or r < u) return {(int)0 ,(int)0 }  ;
		if(l >= u and r <= v) return {st[id].type,st[id].sum} ;  
		down(id,l,r) ; 
		int mid = (l+r)>>1 ; 
		Node t1 = get(id<<1,l,mid,u,v) ; 
		Node t2 = get(id<<1|1,mid+1,r,u,v) ;
		return merge(t1,t2) ;  
	}

	void solve(void) {	
		FOR(i,1,q) {
			int type = Q[i].type ; 
			if(type==1) {
				int vt = Q[i].i ; 
				int p = Q[i].p  ;
				update(1,1,n,p,p+s[vt]-1,vt) ;
			}else if(type==2) {
				int p = Q[i].p ; 
				Node it = get(1,1,n,p,p) ;
				if(it.type==0) cout << 0 << endl ;
				else cout << vec[it.type][it.sum-1] << endl ;
			}else {				
				int vt = Q[i].i ; 
				int l = Q[i].l ;
				int r = Q[i].r ;
				FOR(t,max(1ll*1,l),min(r,s[vt]) ) {
					vec[vt][t-1] = (vec[vt][t-1] + 1)%256 ; 
				}
			}
		}
	}	

}

namespace sub3 {

	void solve(void) {


	}

}


signed main(void) {
    #define TASK "text"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".ANS","w",stdout);
    }
    init() ; 
    /*if(okSub2) sub2::solve() ;
    else if(n <= 1000 and m <= 1000 and q <= 1000) sub1::solve() ;
    else sub3::solve() ;*/
    sub1::solve() ;
    /*cout << endl ;
    sub2::solve() ;*/
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}