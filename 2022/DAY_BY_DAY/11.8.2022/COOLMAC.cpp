#include<bits/stdc++.h>
using namespace std;

#define TASK "COOLMAC"

#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b) for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i = b;i>=a;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

struct R
{
	int l , r ;
	bool operator<(const R&a )const
	{
		return r>a.r ; 
	} 
};
int m  ; 
int n ; 
R a[N] ; 
void doc()
{
    cin>> m ;  
    FOR(i,1,m)
    {
    	cin>>a[i].l>>a[i].r ; 
    }
    sort(a+1,a+m+1);
    cin>>n ; 
    int mi = oo ; 
    FOR(i,1,n)
    {	
    	int val ; 
    	cin>>val;  
    	mi = min(mi,val) ; 
    }
    int res = 0;
    int current_r=1e5;
    int it=  1; 
    while(it<=m)
    {
    	int new_min_left = oo ; 
    	while(it<=m&&a[it].r>=current_r)
    	{
    		new_min_left= min(new_min_left,a[it].l);
    		++it ;
    	}			
    	if(new_min_left>current_r)
    	{
    		cout<<-1 ; 
    		return ; 
    	}
    	res++ ; 
    	current_r = new_min_left; 
    	if(new_min_left<=mi)
    	{
    		cout<<res; 
    		return  ; 
    	}
    }
    cout<<-1 ;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}