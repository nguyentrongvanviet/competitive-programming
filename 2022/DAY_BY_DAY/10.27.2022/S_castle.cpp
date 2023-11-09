#include<bits/stdc++.h>
using namespace std;

#define TASK "S_castle"

#define ll long long
#define pb push_back
#define pk pop_back
#define int long long 
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =5e3+5 ,  oo = INT_MAX;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;
#define pll pair<ll,ll>
struct pt
{
	int x, y ; 
	bool operator<(const pt& a )const
	{
		return y>a.y||(y==a.y&&x<a.x);
	}
};	
map<pll,int>dd1;
map<pll,int>dd2;
int n ;
pt a[N]; 
map<pll,int> cnt ; 
int res= 0;
void doc()
{	
    cin>> n; 
    for(int i= 1;i<=n;i++)
    {
    	cin>>a[i].x>>a[i].y;
    }
    sort(a+1,a+n+1);
    vector<pt>q ; 
    ll madt=0 ;
    ll midt= inf ;
    ll slma= 0 ; 
    ll slmi= 0 ;
    int it =1 ;
    while(it<=n)
    {
    	q.pb(a[it]);
    	while(a[it+1].y==a[it].y)
    	{
    		++it;
    		  q.pb(a[it]);
    	}
    	for(int i= 0 ;i <q.size();i++)
    	{
    		for(int j =i+1;j<q.size();j++)
    		{
    			if(dd1.find({q[i].x,q[j].x})!=dd1.end())
    			{
    				int g=dd1[{q[i].x,q[j].x}];
       				ll dt = (q[j].x-q[i].x)*(g-q[i].y);
    				if(dt>madt)
    				{	
    					madt = dt ; 
    					slma=1;
    				}		
    				else if(dt==madt)
    				{
    					slma++ ;
    				}
    			}
    			else 
    			{
    				dd1[{q[i].x,q[j].x}]=q[i].y;
    			}
    			if(dd2.find({q[i].x,q[j].x})!=dd2.end())
    			{
    				int g=dd2[{q[i].x,q[j].x}];
       				ll dt = (q[j].x-q[i].x)*(g-q[i].y);
    				if(dt<midt)
    				{	
    					midt = dt ; 
    					slmi=1;
    				}		
    				else if(dt==midt)
    				{
    					slmi++ ;
    				}
    			}
    			dd2[{q[i].x,q[j].x}]=q[i].y;
    			if(cnt.find({q[i].x,q[j].x})!=cnt.end())res+=cnt[{q[i].x,q[j].x}];
    			cnt[{q[i].x,q[j].x}]++;
    		}
    	}
    	++it;
    	q.clear();
    }
    cout<<res<<"\n";
    if(res==0)
    {
    	return ; 
    }
   	cout<<madt<<" "<<slma<<"\n"; 
   	cout<<midt<<" "<<slmi;
}

 main()
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