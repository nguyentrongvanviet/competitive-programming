#include<bits/stdc++.h>
#define FOR(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define FOr(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define FOD(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define llg long long
#define pub push_back
using namespace std;
const int BZ=320;
int n,Q,nb;
llg a[100005],b[100005],ly[325];
unordered_map < llg ,int > mp[325]; 
void dowz(int o){
	int u=(o-1) * BZ + 1;
	int v=o * BZ;
	llg gt=ly[o];
	ly[o]=0;
	FOR(i,u,v) b[i]^=gt;
	mp[o].clear();
	FOR(i,u,v) mp[o][b[i]]++;
}
void cnA(int u,int uo,llg gt){
	dowz(uo);
	mp[uo].clear();
	int v=uo*BZ;
	FOR(i,u,v) b[i]^=gt;
	u=(uo-1) * BZ + 1;
	FOR(i,u,v) mp[uo][b[i]]++;
}
void cnB(int uo,llg gt){
	FOR(i,uo,nb) ly[i]^=gt;
}
int geA(int v,int vo,llg gt){
	dowz(vo);
	int re=0;
	int u=(vo-1) * BZ + 1;
	FOR(i,u,v)
	if(b[i]==gt) re++;
	return re;
}
int geB(int vo,llg gt){
	int re=0;
	FOR(i,1,vo)
	if(mp[i].count(gt^ly[i])!=0) re+=mp[i][gt^ly[i]];
	return re;
}
void ME(){
	nb=(n-1) / BZ + 1;
	b[0]=0;
	FOR(i,1,n) b[i]=b[i-1] ^ a[i];
	FOR(i,1,n){
		int io=(i-1) / BZ + 1;
		mp[io][b[i]]++;
	}
	FOR(i,1,nb) ly[i]=0;
	while(Q--){
		int ID;
		cin>>ID;
		if(ID==1){
			int u;
			llg gt;
			cin>>u>>gt;
			int uo=(u-1) / BZ + 1;
			cnA(u,uo,gt^a[u]);
			cnB(uo+1,gt^a[u]);
			a[u]=gt;
		}else{
			int v;
			llg gt;
			cin>>v>>gt;
			int vo=(v-1) / BZ + 1;
			
			cout<<geA(v,vo,gt)+geB(vo-1,gt)<<'\n';
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// freopen("text.INP","r",stdin);
	// freopen("text.OUT","w",stdout);
	cin>>n>>Q;
	FOR(i,1,n) cin>>a[i];d
	ME();
	return 0;
}