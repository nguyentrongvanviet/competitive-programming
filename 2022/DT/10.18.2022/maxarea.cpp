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

struct bg 
{
	int x , y  ;  	
};
bool cmp1(bg a , bg b)
{
	return a.x<b.x||(a.x==b.x&&a.y==b.y);
}
bool cmp2(bg a , bg b )
{
	return a.y<b.y||(a.y==b.y&&a.x<b.x);
}
bool cmp2
int n ; 
void input()
{
 	cin>> n; 
 	for(int  i=1 ;i<=n;i++)
 	{
 		cin>>a[i].x>>a[i].y;  
 	}   
 	sort(a+1,a+n+1,cmp1);
 	for(int i=1 ;i<=n;i++)
 	{
 		
 	}
 	sort(a+1,a+n+1,cmp2);
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