#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back 
#define pk pop_back 
#define pii pair<int,int>  

const  int N = 2e5+5 , oo =1e9 ; 
const ll inf = 1e17 , cs = 330 , sm = 1e9+7 ; 
#define sz(a) (int)a.size()
struct pt 
{
	ll x, y ; 
	pt operator -(const pt& a )const 
	{
		return pt{x-a.x,y-a.y} ; 
	}
	ll operator *(const pt& a)const 
	{
		return x*a.y-y*a.x; 
	}
};

ll sq(ll a )
{
	return a*a ; 
}
pt p[N] ; 
ll n;
ll dis(pt a ,pt b)
{
	return sq(a.x-b.x)+sq(a.y-b.y) ;  
}  
ll ccw(pt a, pt b , pt c )
{
	return (b-a)*(c-b);
}
bool cmp1(pt a, pt b )
{
	return a.y<b.y||(a.y==b.y&&a.x<b.x) ; 
}
bool cmp2(pt a, pt b )
{
	if(ccw(p[1],a,b)==0)
	{
		return a.x<b.x;
	}
	return ccw(p[1],a,b)>0 ;  
} 
void inp()
{
	cin>> n ; 
	for(int i=1 ;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y; 
	}
	int res= 0; 
	vector<pt>q;
	vector<pt>cl ;   
	while(1)
	{
		if(n<3)break ; 
		sort(p+1,p+n+1,cmp1) ; 
		sort(p+2,p+n+1,cmp2) ;
		q.pb(p[1]) ; 
		p[n+1]=p[1];
		for(int i=2;i<=n+1;i++)
		{
			while(q.size()>=2&ccw(q[q.size()-2],q[q.size()-1],p[i])<0)
			{
				cl.pb(q.back());
				q.pk() ; 
			}
			q.pb(p[i]); 
		} 
		q.pk();
		if(q.size()<3)break; 
		for(int i =0 ;i<sz(cl);i++)
		{	
			p[i+1] =cl[i];
		}	
		n=cl.size(); 
		int ok = 0 ; 
		for(int i= 2 ;i<q.size();i++)
		{
			if(ccw(q[i-2],q[i-1],q[i])>0)ok=1; 
		}
		if(ok==0)break ; 
		res++ ;
		q.clear(); 
		cl.clear();
	}
	cout<<res; 
}
int main()
{
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	freopen("i.txt","r",stdin) ;  
	freopen("o.txt","w",stdout) ; 
	inp() ; 

}