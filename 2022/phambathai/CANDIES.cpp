#include<bits/stdc++.h>
#define FOR(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define FOr(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define FOD(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define llg long long
#define pub push_back
#define btpc(x) __builtin_popcount(x)
#define one (llg)(1)
using namespace std;
int Test,n,nf,K,w[105];
llg F[105][105],R[105][105],L[105][105][3],sm;
vector <llg> b;
void CRE(){
	nf=1;
	b.pub(1);
	b.pub(1);
	while(b[nf]+b[nf-1]<=1e15){
		llg gt=b[nf]+b[nf-1];
		nf++;
		b.pub(gt);
	}
	FOR(i,0,nf)
	FOR(j,0,nf)
	FOR(k,0,1) R[i][j]=F[i][j]=L[i][j][k]=0;
	L[0][0][0]=1;

	FOR(i,1,nf)
	FOR(j,0,nf){
        L[i][j][0]+=L[i-1][j][0]+L[i-1][j][1];

        if(j-1>=0)
        L[i][j][1]+=L[i-1][j-1][0];

        L[i][j][0]%=sm;
        L[i][j][0]%=sm;


	}
	FOR(i,0,nf)
	FOR(j,0,nf){
		F[i][j]=(F[i][j]+(j*(L[i][j][0]+L[i][j][1]))) % sm;
		R[i][j]=(R[i][j]+L[i][j][0]+L[i][j][1]) % sm;
		if(j>0) {
			F[i][j]=(F[i][j]+F[i][j-1]) % sm;
			R[i][j]=(R[i][j]+R[i][j-1]) % sm;
		}

	}
}

llg HE(int i,int j){
	if(j<0) return 0;
	return F[i][j];
}
llg HO(int i,int j){
	if(j<0) return 0;
	return R[i][j];
}
void ME(llg u){
	
	FOD(i,nf,1)
	if(u>=b[i]){
		w[i]=1;
		u-=b[i];
	} else w[i]=0;
	int dem=0;
	llg re=0;
	FOD(i,nf,1)
	if(w[i]==1){
	
		
		re+=(F[i-1][nf]-HE(i-1,max(-1,K-dem-1))+sm+
		(R[i-1][nf]-((HO(i-1,max(-1,K-dem-1))*dem) % sm) + sm) % sm) % sm;

		// cout<<F[i-1][nf]-HE(i-1,max(-1,K-dem-1))+
		// (R[i-1][nf]-HO(i-1,max(-1,K-dem-1)))*dem<<'\n';
        dem++;


		

	}
	// cout<<F[3][nf]<<" "<<F[3][1]<<'\n';
	if(dem>=K) re+=dem;
	cout<<re<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("CANDIES.inp","r",stdin);
	freopen("CANDIES.out","w",stdout);
	sm=1e9+7;
	CRE();
	cin>>Test;
	// cout<<C[2][2];
	while(Test--){
		llg u;
		cin>>u>>K;
		if(K>nf){
			cout<<0<<'\n';
			continue;
		}
		K=min(K,nf);
		ME(u);
	}
	return 0;
}