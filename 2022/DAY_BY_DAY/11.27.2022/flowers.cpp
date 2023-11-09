#include<bits/stdc++.h>
using namespace std;

#define TASK "flowers"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =1e3+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct TT 
{
    int l , r;  
};
int n ; 
int a[N],b[N] ; 
bool dd[N][N] ; 
int s[N][N] ;
int sum[N][N] ;
vector<int>pos[N];
queue<TT>q; 
void doc()
{
 	cin>>n ; 
 	FOR(i,1,n)cin>>a[i] ; 
 	FOR(i,1,n)cin>>b[i],pos[b[i]].pb(i) ;   
    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            s[i][j] = s[i-1][j] ; 
        } 
        s[i][a[i]]++;
    } 
    FOR(i,1,n)
    {   
        FOR(j,1,n)sum[i][j] =sum[i-1][j]+(b[i]==j);
    }
}
int get(int l , int r , int x)
{
    if(l<=n&&r>=1&&l>r)
    {
        return get(l,n,x)+get(1,r,x) ;
    }
    return sum[r][x]-sum[l-1][x];
}
void add(int l , int r, int k)
{
    int Left =l-1 ; 
    int Right=r+1; 
    int len ; 
    int sl =0  ; 
    if(Left==0)Left = n ; 
    if(Right==n+1)Right= 1 ;

    if(l<=n&&r>=1&&l>r)
    {
        len =(n-l+1)+(r-1)+1;
    } 
    else
    {
        len=r-l+1;
    }
    sl = get(l,r,b[Left]);
    // cout<<l<<" "<<r<<endl;
    // cout<<Left<<" "<<Right<<endl;
    // cout<<sl<<" "<<s[min(n,len+k+1)][b[Left]]<<endl;
    // if(l==1&&r==4)cout<<sl<<" ",cout<<s[min(n,len+k-1)][b[Left]]<<" "<<"\n";
    if(dd[Left][r]==0&&sl<s[min(n,len+k+1)][b[Left]])
    {
        dd[Left][r]=1 ; 
        // cout<<Left<<" "<<r<<endl;
        q.push({Left,r});
    } 
    sl = get(l,r,b[Right]); 
    if(dd[l][Right]==0&&sl<s[min(n,len+k+1)][b[Right]])
    {
        // cout<<l<<" "<<Right<<endl;
        dd[l][Right]=1 ; 
        q.push({l,Right});
    }
    // cout<<"____________"<<"\n";
} 
bool check(int k )
{
    FOR(i,0,n)FOR(j,0,n)dd[i][j]=0;
    FOR(i,1,k+1)
    {
        for(auto x:pos[a[i]])
        {
            if(dd[x][x]==0)q.push({x,x}),dd[x][x]=1 ;
        }    
    }
    while(!q.empty())
    {
        int l = q.front().l; 
        int r = q.front().r;
        q.pop();
        add(l,r,k); 
    }
    FOR(l,1,n)
    {
        int r = l-1 ;
        if(r==0)r=n;
        if(dd[l][r])return 1 ;   
    }
    return 0 ; 
}
void xuly()
{
    int l = 0; 
    int r = n-1 ;
    int ans = oo;
    while(l<=r)
    {
    	int mid =(l+r)/2; 
    	if(check(mid))
    	{
    		ans =mid ; 
    		r=mid-1 ; 
    	}
    	else 
    	{
    		l=mid+1 ;
    	}
    }
    cout<<ans;
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}