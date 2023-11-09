#include<bits/stdc++.h>
using namespace std;

#define TASK "happiness"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define all(a) a.begin(),a.end()
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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct DL
{
	ll x , y ; 
	bool operator  <(const DL&a)const
	{
		return x<a.x;
	}
};
bool cmp(DL a, DL b)
{
	return a.x>b.x;
}
int n ,m ; 
ll W ;
ll a[N] ,b[N] ;
unordered_map<ll,int>pos;
// map<int,int>pos;
void doc()
{
 	cin>>n >>W;
 	FOR(i,1,n)cin>>a[i] ; 
 	FOR(i,1,n)cin>>b[i] ;
}
vector<DL> create(int l ,int r )
{
	vector<DL>ans ; 
	ans.pb({0,0});
	FOR(i,l,r)
	{
		vector<DL>tmp ; 
		for(auto it: ans)
		{
			tmp.pb({it.x+a[i],it.y}) ;
			tmp.pb({it.x,it.y+b[i]}) ; 
			tmp.pb({it.x+a[i],it.y+b[i]}); 
		}
		ans=tmp ;
	}
	return ans; 
}
int bit[N] ; 
void up(int idx , int n , int val)
{
	for(int i= idx;i<=n;i+=i&-i){bit[i]+=val;}
}
int get(int idx,int n )
{
	int ans =0  ; 
	for(int i=idx;i;i-=i&-i)ans+=bit[i];
	return ans; 
}
void xuly()
{
    if(n==1)
    {
    	if(W==0)
    	{
    		cout<<3<<"\n"; 
    	}
    	else
    	{
    		cout<<(a[1]>=W&&b[1]>=W)<<"\n";
    	}
    	return ;
    }
    int mid =(1+n)/2; 
    vector<DL>A =create(1,mid) ; 
    vector<DL>B = create(mid+1,n) ;
   	sort(all(A));
   	sort(all(B),cmp);
   	vector<ll>value ; 
   	for(auto it : B)
   	{
   		value.pb(it.y) ; 
   	}
   	sort(all(value),greater<ll>()); 
   	value.resize(unique(all(value))-value.begin());
   	int m = value.size();
   	FOR(i,1,value.size())
   	{
   		pos[value[i-1]]=i;
   	}
   	FOR(i,1,m)bit[i] = 0 ;
   	int cur= 0 ; 
   	ll res= 0 ;
   	for(auto it : A)
   	{
   		while(cur<B.size()&&B[cur].x>=W-it.x)
   		{
   			up(pos[B[cur].y],m,1);
   			++cur;
   		}	
   		int ans = -1; 
   		int l =1 ; 
   		int r = m ; 
   		while(l<=r)
   		{
   			int mid =(l+r)/2 ; 
   			if(value[mid-1]>=W-it.y)
   			{
   				ans =mid-1; 
   				l=mid+1; 
   			}
   			else
   			{
   				r=mid-1;
   			}
   		}
   		if(ans!=-1)res+=get(pos[value[ans]],m); 
   	}
   	cout<<res<<"\n";
}	
int main()
{
    IOS();  
    int test ; 
    cin>>test ;
    while(test--)
    {
    	doc(); 
    	// cout<<"G";
    	xuly();
    }
    return 0 ;
}