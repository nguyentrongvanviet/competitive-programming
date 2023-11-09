#include<bits/stdc++.h>
using namespace std; 
#define ll long long
ll n, m ;
int sum[1502][1502];
bool a[1502][1502],A[1502][1502],B[1502][1502];
bool dd[1502][1502];
struct bg{
	int x;
	int y;
};
int vx[5] = {0,0,0,-1,1},vy[5] = {0,-1,1,0,0};
queue<bg> Q;
bool outside(ll xx,ll yy,ll i,ll j,ll u,ll v){
	if(xx<i||xx>u||yy<j||yy>v) return 1;
	return 0;
}
void bfs(ll l,ll r,ll h,ll k){
	while(!Q.empty()){
		Q.pop();
	}
	Q.push({1,1});
	dd[1][1] = 1;
	while(!Q.empty()){
		bg u = Q.front();
		Q.pop();
		// cout<<u.x<<" "<<u.y<<endl;
		for(int i=1;i<=4;i++){
			int xx = u.x + vx[i],yy = u.y + vy[i];
			if(1<=xx&&xx<=n&&1<=yy&&yy<=m){
				if(a[xx][yy] ==0){
					// cout<<
					if(outside(xx,yy,l,r,h,k)){
						if(dd[xx][yy]==0){
							dd[xx][yy] = 1;
							Q.push({xx,yy});
						}
					}
				}

			}
		}
	}
}
bool check(ll x,ll y,ll u,ll v){
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dd[i][j] = 0;
	bfs(x,y,u,v);
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++) cout<<dd[i][j]<<" ";
	// 	cout<<endl;
	// }
	return !dd[n][m];
}
bool dot(ll i,ll j,ll u,ll v){
	if(!((i==1&&j==1)||(u==n&&v==m))) return 1;
	return 0;
}
ll sumA[1502][1502],sumB[1502][1502];
int vax[5] = {0,-1,0,1,0},vay[5] = {0,0,1,0,-1},vbx[5]={0,1,0,0,-1},vby[5]={0,0,-1,1,0};
bool flag1,flag2;
void dfs1(ll x,ll y){
	if(A[n][m]==1) flag1 = 0;
	if(flag1 == 0) return;
	A[x][y] = 1;
	for(int i=1;i<=4;i++){
		ll xx =  x+vax[i],yy = y+vay[i];
		if(1<=xx&&xx<=n&&1<=yy&&yy<=m){
			if(a[xx][yy] == 0) if(A[xx][yy]==0){				
				dfs1(xx,yy);
			}
		}
	}
}
void dfs2(ll x,ll y){
	if(B[n][m]==1) flag2 = 0;
	if(flag2 == 0) return;
	B[x][y] = 1;
	for(int i=1;i<=4;i++){
		ll xx =  x+vbx[i],yy = y+vby[i];
		if(1<=xx&&xx<=n&&1<=yy&&yy<=m){
			if(a[xx][yy] == 0) if(B[xx][yy]==0){				
				dfs2(xx,yy);
			}
		}
	}
}
void makeAB(){
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		A[i][j] = 0;
		B[i][j] = 0;
	}
	flag1 = 1;
	flag2 = 1;
	dfs1(1,1);
	dfs2(1,1);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) cout<<A[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) cout<<B[i][j]<<" ";
		cout<<endl;
	}
	
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		sumA[i][j] = sumA[i][j] +sumA[i-1][j]+sumA[i][j-1]-sumA[i-1][j-1]+A[i][j];
		sumB[i][j] = sumB[i][j] +sumB[i-1][j]+sumB[i][j-1]-sumB[i-1][j-1]+B[i][j];
	}
}
bool ck1(ll i,ll j ,ll len){
	ll u = i+len-1,v = j+len-1;

	if(!dot(i,j,u,v)) return 0;
	if(1<=u&&u<=n&&1<=v&&v<=m){
		ll S = sum[u][v] - sum[u][j-1] - sum[i-1][v] + sum[i-1][j-1];
		// ll SA = sumA[u][v] - sumA[u][j-1] - sumA[i-1][v] + sumA[i-1][j-1];
		// ll SB = sumB[u][v] - sumB[u][j-1] - sumB[i-1][v] + sumB[i-1][j-1];
		// cout<<i<<" "<<j<<" "<<u<<" "<<v<<" "<<S<<" "<<SA<<" "<<SB<<endl;
		// cout<<"& "<<i<<" "<<j<<" "<<u<<" "<<v<<" "<<S<<endl;
		if(S==0) {
			// cout<<i<<" "<<j<<" "<<u<<" "<<v<<endl;
			return 1;
			// if(check(i,j,u,v)&&dot(i,j,u,v) ){
				// res = min(res,(ll)len);
				// cout<<i<<" "<<j<<" "<<u<<" "<<v<<endl;
			// }
		}
	}
	return 0;
}
bool ck2(ll i,ll j ,ll len){
	ll u = i+len-1,v = j+len-1;
	if(!dot(i,j,u,v)) return 0;
	if(1<=u&&u<=n&&1<=v&&v<=m){
		// ll S = sum[u][v] - sum[u][j-1] - sum[i-1][v] + sum[i-1][j-1];
		ll SA = sumA[u][v] - sumA[u][j-1] - sumA[i-1][v] + sumA[i-1][j-1];
		ll SB = sumB[u][v] - sumB[u][j-1] - sumB[i-1][v] + sumB[i-1][j-1];
		// cout<<i<<" "<<j<<" "<<u<<" "<<v<<" "<<S<<" "<<SA<<" "<<SB<<endl;
		// cout<<"& "<<i<<" "<<j<<" "<<u<<" "<<v<<" "<<S<<endl;
		if(SA>0&&SB>0) {
			// cout<<i<<" "<<j<<" "<<u<<" "<<v<<endl;
			return 1;
			// if(check(i,j,u,v)&&dot(i,j,u,v) ){
				// res = min(res,(ll)len);
				// cout<<i<<" "<<j<<" "<<u<<" "<<v<<endl;
			// }
		}
	}
	return 0;
}
void doc(){
	cin>>m>>n;
	// cout<<m<<" "<<n<<endl;
	// ll res = 1e9;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		char x;
		cin>>x;
		if(x=='.') a[i][j] = 0;
		else a[i][j] = 1;
	}
	makeAB();
	ll res =1e9;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j]; 
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		ll d = 1,c = min(n,m),mid;
		ll l = 1,r;
		while(d+1<c){
			mid = (d+c)/2;

			if(ck1(i,j,mid)) d = mid;
			else c = mid;
		}
		if(ck1(i,j,c)){
			r = c;
		} else if(ck1(i,j,d)){
			r = d;
		}
		while(l+1<r){
			mid =(l+r)/2;
			if(ck2(i,j,mid)) r = mid;
			else l = mid;
		}
		if(ck2(i,j,l)){
			res = min(res,l);
		} else if(ck2(i,j,r)){
			res = min(res,r);
		}
	}
	if(res!=1e9) cout<<res;
	else cout<<"Impossible";
}
int main(){
	freopen("p9robot1.INP","r",stdin);
    freopen("p9robot1.ANS","w",stdout);	
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	doc();
}