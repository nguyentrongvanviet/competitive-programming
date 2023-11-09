#include<bits/stdc++.h>
using namespace std;

#define TASK "coder"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =3e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

struct bg
{
	int x , y ;  
	int id ; 
	bool operator<(const bg&a)
	{
		return x<a.x||(x==a.x&&y<a.y)||(x==a.x&&y==a.y&&id<a.id);  	
	}
}; 
bool cmp(bg a, bg b )
{
	return a.y<b.y||(a.y==b.y&&a.x<b.x)||(a.x==b.x&&a.y==b.y&&a.id<b.id);
}
int n ; 
bg a[N ]; 
map<pii,int>sl; 
int bit[N]; 
int pos[N];
int f[N];
void up(int idx,int val)
{
	for(int  i= idx;i<=n;i+=i&-i)
	{
		bit[i]+=val ; 
	}
}
int get(int idx)
{
	int ans  = 0 ;
	for(int i= idx;i;i-=i&-i)
	{
		ans+=bit[i] ; 
	}
	return ans;  
}
void doc()
{
 	cin>> n ; 
 	for(int i=1 ;i<=n;i++)cin>>a[i].x>>a[i].y, a[i].id = i,sl[{a[i].x,a[i].y}]=0;
 	sort(a+1,a+n+1,cmp);
 	for(int i=1 ;i<=n;i++)
 	{
 		pos[a[i].id]=i;
 	}
 	sort(a+1,a+n+1) ; 
 	for(int i= 1;i<=n;i++)
 	{	

 		f[a[i].id] =get(pos[a[i].id]);
 		f[a[i].id]-=sl[{a[i].x,a[i].y}];
 		up(pos[a[i].id],1);
 		sl[{a[i].x,a[i].y}]++;
 	}  			
 	for(int i=1 ;i<=n;i++)
 	{	
 		cout<<f[i]<<"\n";
 	}
}	

int main()
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