#include<bits/stdc++.h>
using namespace std;

#define TASK "PAINT"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

#pragma CPP target("popcnt")
const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

struct pt
{
	ll x  , y;
    pt operator - (const pt& a )const
    {
        return pt{x-a.x,y-a.y};  
    }
    ll operator * (const pt& a )const
    {
        return x*a.y-y*a.x; 
    }
};
struct DG 
{
	vector<pt>point ; 
    ll area ; 
    bool operator<(const DG& a)const
    {
        return area<a.area;
    }
};
ll ccw(pt a,  pt b ,pt c)
{
    return (b-a)*(c-a);
}
ll w , h  ; 
int n , m ,q ;  
DG a[N] ;
ll totalarea=0 ; 
ll dtDG(vector<pt> p)
{
	ll area =0 ;  
	pt O={0,0} ;
	FOR(i,0,p.size()-2)
	{
		area+=ccw(O,p[i],p[i+1]);
	}
    return abs(area); 
} 
bool inside(pt x , int id )
{
    ll area= 0 ; 
    FOR(i,0,a[id].point.size()-2)
    {
        pt u = a[id].point[i] ; 
        pt v = a[id].point[i+1];
        area+=abs(ccw(x,u,v));
    }
    return area==a[id].area;
}
bool check_inside(int x , int y  )
{
    FOR(i,0,a[x].point.size()-1)
    {
        pt tmp = a[x].point[i];
        if(inside(tmp,y)==0)
        {
            return 0 ; 
        }
    }
    return 1; 
}
ll areain[N] ; 
int chua[N] ;
ll solve(pt x  )
{
    FOR(i,1,n+1)
    {
        if(inside(x,i))
        {
            return a[i].area-areain[i];
        }
    }
}
void doc()
{
    cin>>w>>h>>n>>m>>q; 
    FOR(i,1,n)
    {
    	FOR( j,1,m)
    	{
    		int x, y; cin>>x >>y;  
    		a[i].point.pb({x,y});  
    	}
        a[i].point.pb(a[i].point[0]);
        a[i].area =dtDG(a[i].point); 
    }   
    sort(a+1,a+n+1);
    a[n+1].point = {{0,0},{0,h},{w,h},{w,0},{0,0}};
    a[n+1].area=2*w*h;
    FOR(i,1,n+1)
    {
        FOR(j,1,i-1)
        {
            if(chua[j])continue ;
            if(check_inside(j,i))
            {
                areain[i]+=a[j].area;
                chua[j]++; 
            }
        }
    }
    while(q--)
    {
        pt tmp  ; 
        cin>>tmp.x>>tmp.y ; 
        // cout<<tmp.x<< " "<<tmp.y<<endl;
        // if(inside(tmp,n+1))cout<<"G";
        ll res=solve(tmp) ; 
        if(res&1)
        {
            cout<<res/2<<".5"<<"\n";
        }
        else
        {
            cout<<res/2<<".0"<<"\n";
        }
    }
}

int main()
{
    fast 
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