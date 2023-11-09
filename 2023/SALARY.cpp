#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

#include<bits/stdc++.h>
using namespace std; 
#define pb push_back
#define ll long long 
const int N = 2e5+5;
const  int M=8*N+5;  
vector<int>g[N];  
int n  , id = 0 , q  ;  
ll st[M],a[N], s[2*N+5] ;
int in[N] ;  
int out[N] ; ;
void build(int id , int  l , int r ){
	if(l==r ) {
		st[id] =s[l]; 
		return ; 
	}
	int mid =(l+r)/2; 
	build(id*2,l,mid) ; 
	build(id*2+1,mid+1,r) ; 
	st[id]=st[id*2]+st[id*2+1] ; 
}
ll lazy[8*N] ; 
void dolazy(int id)
{
	st[id]+=lazy[id] ;
	lazy[id*2]+=lazy[id] ;
	lazy[id*2+1]+=lazy[id] ;
	lazy[id] = 0; 
}
ll sum(int id,  int l , int r , int t  , int p ){
	dolazy(id); 
	if(l>=t&&r<=p){
		return st[id];
	}
	if(l>p||r<t){
		return 0 ;
	}
	int mid =(l+r)/2 ; 
	return sum(id*2,l,mid,t,p)+sum(id*2+1,mid+1,r,t,p);
}
void update(int id , int l , int r , int t, int p , int val ){
	dolazy(id) ;
	if(t<=l&&r<=p)
	{
		lazy[id]+=val;
		dolazy(id) ;
		return ;  
	}
	if(r<t||p<l) return   ;  
	int mid = (l+r)/2; 
	update(id*2,l,mid,t,p ,val)  ;
	update(id*2+1,mid+1,r,t,p,val); 
	st[id]=st[id*2]+st[id*2+1] ; 
} 
void dfs(int u  , int  p  ){
	id++;  
	in[u] =id ; 
	s[id]= a[u] ; 
	for(auto v:g[u])
	{
		dfs(v,u) ; 
	}
	out[u]=id;
}
int main(){
	if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
	cin>> n >>q; 
	for(int i =1;i<=n;i++){
		cin>>a[i] ;
		if(i!=1){
			int p ;cin>>p  ; 
			g[p].pb(i) ; 
		} 
	}
	dfs(1,0) ;
	build(1,1,n) ;
	while(q--){
		char t ;  
		cin>>t; 
		if(t=='p'){
			int node, val  ; 
			cin>> node >>val ;
			int pos1=in[node] ; 
			int pos2=out[node] ; 
			update(1,1,n,pos1+1,pos2,val) ;  
		}else{
			int node ; 
			cin>>node;
			cout<<sum(1,1,n,in[node],in[node])<<endl ;
		}
	}
	return 0 ; 
}
