#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll 
#define TASK "p9queue1"
ll n,k;
struct DL{
    ll val;
    ll id;
};
DL Q[405][4005];
ll a[100005],L[100005];
bool dd[100005];
int dem;

void work(int p){
    dem = 0;
    int sz = sqrt(n) + 1;
    for(ll j=0;j<min(k, sz);j++) Q[p][j] = {-1,-1};
    int l = sz*p, r = sz*(p+1) -1 ;
    for(ll j=l+1;j<=min(n,(ll)r+1);j++){
        if(dd[j]==0){
            ll u = dem%k;
            if(u < min(k,sz) && Q[p][u].val<a[j]) Q[p][u] = {a[j],j};
            dem++;
        }
    } 
    L[p] = dem;
}
void doc(){
    cin>>n>>k;
    int sz = 322;
    for(ll i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<sz;i++) work(i);

    for(ll i=1;i<=n;i++)
    {
        DL ma = {-1,-1};
        int tmp=0,id= - 1;
        for(int j=0;j<sz;j++)
        {
            if(L[j]==0) continue;
            int h = (k - tmp%k)%k;
            if( h < sz && Q[j][h].val>ma.val){
                ma = Q[j][h];
                id = j;
            }
            tmp+=L[j];
        }   

        cout<<ma.val<<" ";
        dd[ma.id] = 1;
        work(id);
    }
}
main(){
   
    if(fopen(TASK".INP","r")){
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout); 
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // cout<<to_ll("12345");
    // cin>>t;
    // while(t--)
     doc();
}