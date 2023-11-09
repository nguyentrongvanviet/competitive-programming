#include<bits/stdc++.h>
using namespace std;

#define TASK "SPACE"

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
#define db double 
const db eps = 1e-9;  
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ; 

struct pt 
{
	db x , y , z; 
} ; 
int n ; 
pt a[N];
void doc()
{
 	cin>> n ; 
 	FOR(i,1,n)cin>>a[i].x>>a[i].y>>a[i].z;   
}
db dis(pt a, pt b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
db kc(db x , db y ,db z )
{
	db ans = 0 ;
	pt tmp={(db)x,(db)y,(db)z}; 
	FOR(i,1,n)
	{	
		ans+=dis(tmp,a[i]);
	}
	return ans ;
}
pair<db,db> searchz(db x , db y,db l, db r)
{
	while(r-l>eps)
	{
		db m1 = l+(r-l)/3 ; 
		db m2 = r-(r-l)/3 ; 
		db f1 = kc(x,y,m1);
		db f2= kc(x,y,m2);
		if(f1>f2)
		{
			l=m1; 
		}
		else 
		{
			r=m2;  
		}
	}
	return {kc(x,y,l),l};
}
pair<db,db>searchy(db x ,db l ,db r )
{	
	while(r-l>eps)
	{
		db m1 = l+(r-l)/3 ; 
		db m2 = r-(r-l)/3 ; 
		db f1 = searchz(x,m1,-1000,1000).fi;
		db f2= searchz(x,m2,-1000,1000).fi;
		if(f1>f2)
		{
			l=m1; 
		}
		else 
		{
			r=m2;  
		}
	}
	return {searchz(x,l,-1000,1000).fi,l};
}
pair<db,db>searchx(db l , db r )
{
	while(r-l>=eps)
	{
		db m1 = l+(r-l)/3 ; 
		db m2 = r-(r-l)/3 ; 
		db f1 = searchy(m1,-1000,1000).fi;
		db f2= searchy(m2,-1000,1000).fi;
		if(f1>f2)
		{
			l=m1; 
		}
		else 
		{
			r=m2;  
		}
	}
	return {searchy(l,-1000,1000).fi,l};
}
void xuly()
{
    pair<db,db> xx= searchx(-1000,1000); 
    db x= xx.se ; 
    pair<db,db>yy= searchy(x,-1000,1000);
    db y = yy.se;
    pair<db,db>zz= searchz(x,y,-1000,1000) ; 
    db z= zz.se;
    cout<<setprecision(4)<<fixed;
    cout<<x<<" "<<y<<" "<<z;
}	
int main()
{	
    IOS();  
    doc(); 
    xuly();
}