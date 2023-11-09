#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(ll i=a;i<=b;++i)
#define fd(i,a,b) for(ll i=a;i>=b;--i)
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<ll,ll>
//#define X first 
//#define Y second
ll const N=1e6+5;
ll Dx[3]={0,1,1};
ll Dy[3]={1,1,0};
ll Vx[3]={0,1,1};
ll Vy[3]={-1,-1,0};
ll sm=1e9+7;
ll n,m;
ll f[N],l[N],r[N],s[N];
ll lazy[4*N];
ll a[N];
struct bg{
	ll X,Y;
};
bg T[4*N];
void Build(ll id,ll l,ll r){
	if(l==r){
		T[id].X=a[l];
		T[id].Y=1;
		return;
	}
	ll mid=(l+r)/2;
	Build(id*2,l,mid);
	Build(id*2+1,mid+1,r);
	T[id].X=min(T[id*2].X,T[id*2+1].X);
	if(T[id*2].X==T[id].X) T[id].Y+=T[id*2].Y;
	if(T[id*2+1].X==T[id].X) T[id].Y+=T[id*2+1].Y;
}
bg get(ll id, ll l, ll r, ll u, ll v){
	if(l>v || r<u) return {0,0};
	if(l>=u && r<=v) return T[id];
	ll mid=(l+r)/2;
	bg get1 = get(2 * id, l, mid, u, v);
    bg get2 = get(2 * id + 1, mid + 1, r, u, v);
    return min(get1,get2);
}
void update(ll id,ll l,ll r,ll u,ll val){
	if(u<l || u>r) return;
	if(u>=l && u<=r){
		T[id].X=val;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,u,val);
	update(id*2+1,mid+1,r,u,val);
	T[id].Y=0;
	T[id].X=min(T[id*2].X,T[id*2+1].X);
	if(T[id*2].X==T[id].X) T[id].Y+=T[id*2].Y;
	if(T[id*2+1].X==T[id].X) T[id].Y+=T[id*2+1].Y;
}
void input(){
    cin>>n>>m;
    f(i,0,n-1) cin>>a[i];
    Build(1,0,n-1);
    while(m--){
    	ll k,u,v;
    	cin>>k>>u>>v;
    	if(k==1){
    		update(1,0,n-1,u,v);
		}
		else {
			bg res=get(1,1,n,u+1,v);
			cout<<res.X<<" "<<res.Y<<endl;
		//	cout<<res.X<<" "<<res.Y<<endl;
		}
	}
}
void output(){
	
}
int main(){
//	freopen("qhd.inp","r",stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test = 1 ;
//	cin>>test;
	f(i,1,test){
		input();
		output();
	}
	return 0;
}