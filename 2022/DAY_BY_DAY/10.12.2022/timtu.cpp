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
	ll x, y ; 
	bool operator<(const pt&a )const 
	{
		return y>a.y||(y==a.y&&x<a.x) ; 
	}
};	

int n ; 
pt a[N] ; 
struct bg 
{
	ll x, y , u , v;  
};	
struct cmp
{
	bool operator()(const bg& a, const bg& b )const
	{
		return a.x<b.x;
	}
};
set<bg,cmp>s; 
set<bg,cmp>ss;
ll dt(bg a, bg b )
{
	return abs(a.u-a.x)*abs(a.y-b.y);
}
void input()
{
 	cin>> n ; 
 	for(int i =1 ;i<=n;i++)
 	{
 		cin>>a[i].x>>a[i].y ; 
 	}   
 	sort(a+1,a+n+1) ; 
 	int it =1 ;
 	vector<pt>q;  
 	ll res=0  ;
 	while(it<=n)
 	{ 
 		q.pb(a[it]);
 		while(a[it].y==a[it+1].y)
 		{
 			++it; 
 			q.pb(a[it]);
 		} 
 		for(int i= 0 ; i<q.size()-1;i++)
 		{
 			pt a=  q[i] ; 
 			pt b= q[i+1] ; 
 			bg tmp ={q[i].x,q[i].y,q[i+1].x,q[i+1].y};
 			auto x=  s.lower_bound(tmp);
 			if(x==s.end())continue;
 			bg cur = *x ;
 			if(cur.x==tmp.x&&cur.u==tmp.u)
 			{
 				res=max(res,dt(cur,tmp));
 			} 
 		}
 		q.pb({inf,inf});
 		int j=  0 ; 	
 		for(auto i =s.begin();i!=s.end();i++)
 		{
 			auto g = *i; 
 			while(q[j].x<g.x&&j<q.size()-1)
 			{
 				j++;
 			}
 			if(g.u<q[j].x)
 			{
 				ss.insert(g);	
 			}
 		}
 		q.pk();
 		for(int i= 0 ;i<q.size()-1;i++)
 		{
 			bg tmp = {q[i].x,q[i].y,q[i+1].x,q[i+1].y};
 			ss.insert(tmp);
 		}
 		s.swap(ss);
 		ss.clear();
 		q.clear();
 		it++;
 	}
 	cout<<res<<endl;
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