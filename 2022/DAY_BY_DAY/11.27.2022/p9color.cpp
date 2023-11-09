#include<bits/stdc++.h>
using namespace std;

#define TASK "p9color"

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
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N = 2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct DL
{
	int sl , d ; 
	DL(){sl=oo;d=oo;}
	DL(int _sl , int _d){sl=_sl;d=_d;}
	bool operator <(const DL&a)const
	{
		return sl<a.sl||(sl==a.sl&&d<a.d); 
	}
};

int n ,k ; 
int a[N] ; 
DL f[N][3]; 
bool dd[N][3];
struct BG
{
	int id , c ; 
	DL x; 
} ; 
struct cmp
{
	bool operator()(BG a, BG b)
	{
		return b.x <a.x;
	}
};
void doc()
{	
    cin>>n>>k; 
    FOR(i,1,n)cin>>a[i] ; 
}
void xuly()
{
	priority_queue<BG,vector<BG>,cmp>q;
	if(a[1]==0)
	{
		f[1][1] ={1,1}; 
		f[1][2] ={1,1};
		q.push({1,1,f[1][1]});
		q.push({1,2,f[1][2]});
	}    
	else 
	{
		f[1][a[1]]={1,1}; 
		q.push({1,a[1],f[1][a[1]]});
	}
	while(!q.empty())
	{
		int id=  q.top().id;  
		int  c= q.top().c;
		q.pop(); 
		if(dd[id][c])continue;
		dd[id][c] =1 ; 
		DL tmp =f[id][c];
		int sl =tmp.sl; 
		int d= tmp.d; 
		// cout<<id<<" "<<c<<" "<<sl<<" "<<d<<endl;
		if(id==n)
		{
			cout<<sl<<"\n"; 
			return ; 
		}
		if(d==k)
		{
			if(a[id+1]==0)
			{
				if(DL{tmp.sl+1,1}<f[id+1][1])
				{
					f[id+1][1]={tmp.sl+1,1};
					q.push({id+1,1,f[id+1][1]});
				}
				if(DL{tmp.sl+1,1}<f[id+1][2])
				{
					f[id+1][2]={tmp.sl+1,1};
					q.push({id+1,2,f[id+1][2]});
				}
			}
			else 
			{
				if(DL{tmp.sl+1,1}<f[id+1][a[id+1]])
				{
					f[id+1][a[id+1]]={tmp.sl+1,1};
					q.push({id+1,a[id+1],f[id+1][a[id+1]]});
				}
			}
		}
		else 
		{
			if(a[id+1]==0||a[id+1]==c)
			{
				if(DL{tmp.sl,tmp.d+1}<f[id+1][c])
				{
					f[id+1][c]=DL{tmp.sl,tmp.d+1};
					q.push({id+1,c,f[id+1][c]});
				}
			}
			else 
			{
				int u = min(n,id+k-d);
				if(DL{tmp.sl+1,k-d}<f[u][a[id+1]])
				{
					f[u][a[id+1]]={tmp.sl+1,k-d};
					q.push({u,a[id+1],f[u][a[id+1]]});
				}
			}
		}
	}
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}