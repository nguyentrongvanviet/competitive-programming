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

int a , b , c;  
void gcd(int a,int b , int&x , int&y)
{
	if(b==0)
	{
		x=1 ; 
		y =0 ;  
		return ; 
	}
	int x1 , y1 ; 
	gcd(b,a%b,x1,y1); 
	x=y1 ; 
	y=x1-a/b*y1;
}
void input()
{	
	int x ,y , u , v ;  
	cin>>x>>y>>u>> v; 
	u+=v;
	c =u-x ; 
	a = y ;
	b = v ; 
	int uc = __gcd(a,b) ;
	if(c%uc!=0)
	{
		cout<<"NO";
		return ;
	} 
	a/=uc; 
	b/=uc; 
	c/=uc;
	int x1 , y1 ; 
	gcd(a,b,x1,y1);
	x1*=uc ; 
	y1*=uc ; 
	
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