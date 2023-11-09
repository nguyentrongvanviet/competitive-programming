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

struct pt 
{
	int x, y ; 
}a[N];
int n ; 
map<pii,bool>dd ; 
void input()
{
    cin>> n; 
    for(int i= 1;i<=n;i++)
    {
    	cin>>a[i].x>>a[i].y;  
    	dd[{a[i].x,a[i].y}]=1;
    }
    ll res=0  ;
    for(int i=1 ;i<=n;i++)
    {
    	for(int j=i+1;j<=n;j++)
    	{
    		if(dd[{a[i].x,a[j].y}]&&dd[{a[j].x,a[i].y}])
    		{
    			if(abs((a[i].x-a[j].x)*1LL*(a[i].y-a[j].y))==65721LL)
    			{
    				cout<<i<<" "<<j<<endl;
    			}
    			res=max(res,(a[i].x-a[j].x)*1LL*(a[i].y-a[j].y));
    		}
    	}
    }
    cout<<res; 
}
void output()
{
    
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
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