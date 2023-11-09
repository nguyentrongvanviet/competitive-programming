#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n , q ; 
ll bit[N]  ,a[N] ; 
void input()
{
	cin>> n>>q ; 
	for(int i =1;i<=n;i++)
	{
		cin>>a[i] ; 
	}   
}
void up(int idx,int val )
{
	for(int i= idx;i<=n;i+=(i&-i))
	{
		bit[i]+=val; 
	}
}
ll get(int idx)
{
	ll ans =0 ;
	for(int i =idx;i;i-=(i&-i))
	{
		ans+=bit[i] ; 
	}
	return ans;  
}
void init()
{
	for(int i= 1;i<=n;i++)
	{
		up(i,a[i]-a[i-1]); 
	}
}
void output()
{	
   	init();
   	while(q--)
   	{
   		int t; cin>>t ;  
   		if(t==1)
   		{
			int l , r  , val ;
			cin>>l>>r>>val; 
			up(l,val);  
			up(r+1,-val); 
   		}
   		else 
   		{
   			int pos ;  
   			cin>>pos;
   			cout<<get(pos)<<"\n";
   		}
   	}
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    // freopen("i.txt","r",stdin); 
    // freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}