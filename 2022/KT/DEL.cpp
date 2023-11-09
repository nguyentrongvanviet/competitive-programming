#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
const int N =3e2+5 ; 
const ll INF = 1e17 ; 
int n ;
ll a[N]  ; 
ll f[N][N] ,dd[N][N];
void init(){
	for(ll i = 1;i<=n;i++){
		for(ll j =1;j<=n;j++){
			f[i][j] = INF ;
			dd[i][j]=0 ;  
		}
	}
} 
ll tinh(ll i , ll j ){
	if(dd[i][j]==1){
		return f[i][j] ; 
	}
	if(i==j){
		f[i][j] =0; 
		dd[i][j]=1; 
		return f[i][j]; 
	}
	ll tmp=INF;
	for(ll t=i ;t<=j-1;t++){
		ll val = tinh(i,t)+tinh(t+1,j);
		if(a[t]==a[j]){
			tmp =min(tmp,val) ; 
		}else{
			tmp =min(tmp,val+1) ;
		}
	}
	f[i][j] =tmp; 
	dd[i][j]=1;	
	return f[i][j ] ;
}
int main(){
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
    freopen("i.txt","r",stdin) ; 
    freopen("o.txt","w",stdout) ;  
	cin>> n ; 
	for(int i =1;i<=n;i++){
		cin>>a[i ]; 
	}
	cout<<tinh(1,n) +1 <<endl ; 
}