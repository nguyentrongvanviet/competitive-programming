#define lmao ""
#include<bits/stdc++.h>
#define forgor(i,a,b) for(int i=a; i<=b; i++)
#define rember(i,a,b) for(int i=a; i>=b; i--)
#define ll long long
#define db double
#define big 1e18
#define small -1e16
#define pb push_back
#define endl '\n'
#define int long long
#define se second
#define fi first
#define ishowspeed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mask(i) (1LL<<(i))
using namespace std;
bool maximize(ll &x, const ll &y) {
	if(x<y){
		x=y; return true;
	} else return false;
}
bool minimize(ll &x, const ll &y) {
	if(x>y){
		x=y; return true;
	} else return false;
}
typedef priority_queue<int,vector<int>,greater<int>> sup;
typedef priority_queue<int,vector<int>> yo;
typedef vector<int> vt;
const int sm=1e9+7;
inline ll gcd(ll a,ll b){return __gcd(a,b);}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
struct bg{
	ll x;
	ll y;
};
const int N=1e6+5,N2=2e3+5;
const bool nhieutest=false;

void doc(){

}
void hello(){
	
}
signed main(){
    ishowspeed;
    if(fopen(lmao".inp","r")){
    freopen(lmao".inp", "r", stdin);
    freopen(lmao".out", "w", stdout);}
	ll t=1;
	if(nhieutest) cin>>t;
	while(t--){
		doc(); hello();
		cout<<endl;
	}
	return 0;
}