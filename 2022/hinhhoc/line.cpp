#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
const ll N = 2e5+5 ,inf = 1e9  , INF =1e17  , cs = 330    ,mod = 1e9+7 ;
struct pt 
{
	int x ,y ;
	pt operator -( const pt& a)const 
	{
		return pt{x-a.x,y-a.y}; 
	} 	

};	
struct line
{
	int a,  b , c;
	bool operator==(const line &y )const 
	{
		return (a==y.a&&b==y.b&&c==y.c);
	}	 
};	

int n ,  m ;
pt a[N] , b[N] ; 
line makeline(pt a, pt b )
{
	// Ax+By+C = 0 ; 
	int A =a.y-b.y; 
	int B =b.x-a.x; 
	int C = -A*a.x-B*a.y; 
	int t = __gcd(__gcd(A,B),C) ; 
	A/=t; 
	B/=t;
	C/=t;
	if(A==0)
	{
		if(B>0)
		{
			return {A,B,C}; 
		}
		else 
		{
			return {-A,-B,-C} ;
		}
	}
	if(A<0)return{-A,-B,-C};
	return {A,B,C}; 
} 
void inp()
{
	pt a  , b,c, d   ; 
	a ={1,1} ; 
	b = {2,2} ; 
	c ={3,3} ; 
	d={4,5} ;
	line y = makeline(a,b) ;
	line z= makeline(c,d) ;
	cout<<y.a<<" "<<y.b<<" "<<y.c<<endl;   
	cout<<z.a<<" "<<z.b<<" "<<z.c<<endl;
	if(y==z)
	{
		cout<<"A";	
	}
//	cin>> n>> m ;
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
   freopen("i.txt","r",stdin) ;
   freopen("o.txt","w",stdout) ;
    inp();
}
