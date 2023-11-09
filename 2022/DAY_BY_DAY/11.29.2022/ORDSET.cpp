#include<bits/stdc++.h>
using namespace std;

#define TASK "ORDSET"

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
#define all(a) a.begin(),a.end()  
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

struct Q 
{
	char c; 
	int val;   
}; 
Q query[N] ;
int q; 
int st[4*N]; 
vector<int>value ;   
set<int>s;
map<int,int>pos ;
void up(int id , int l, int r , int pos , int val )
{
	if(l==r)
	{
		st[id]+=val; 
		return ; 
	}
	int mid =(l+r)/2 ;
	if(pos<=mid)
	{
		up(id*2,l,mid,pos,val) ; 
	}
	else 
	{
		up(id*2+1,mid+1,r,pos,val) ;
	}
	st[id]=st[id*2]+st[id*2+1] ;
}
int get(int id, int l, int r, int val)
{
	if(l==r)
	{
		return l ; 
	}
	int mid =(l+r)/2; 
	if(val<=st[id*2])
	{
		return get(id*2,l,mid,val) ; 
	}
	else
	{
		return get(id*2+1,mid+1,r,val-st[id*2]);
	}
}
int sum(int id , int l ,int r,int t ,int p )
{
	if(t<=l&&r<=p)
	{
		return st[id];  
	}
	if(r<t||p<l)return 0 ; 
	int mid =(l+r)/2; 
	return sum(id*2,l,mid,t,p)+sum(id*2+1,mid+1,r,t,p);
}
void doc()
{
	cin>>q;  
	FOR(i,1,q)
	{
		cin>>query[i].c>>query[i].val;  
		if(query[i].c=='I')
		{
			value.pb(query[i].val);
		}
	}
}
void xuly()
{
    sort(all(value));
	value.resize(unique(all(value))-value.begin());
	int n =value.size();
	FOR(i,1,value.size())
	{	
		pos[value[i-1]]= i ;
	}
	FOR(i,1,q)
	{
		int c= query[i].c; 
		int val = query[i].val; 
		if(c=='I')
		{
			if(s.find(val)==s.end())
			{
				s.insert(val);
				up(1,1,n,pos[val],1);  
			}
		}
		else if(c=='D')
		{
			if(s.find(val)!=s.end())
			{
				s.erase(val);
				up(1,1,n,pos[val],-1) ; 
			}
		}
		else if(c=='K') 
		{
			if(val>s.size()||s.size()==0)
			{
				cout<<"invalid"<<"\n";
			}
			else cout<<value[get(1,1,n,val)-1]<<"\n";
		}
		else if(c=='C')
		{
			int ans= -1; 
			int l =1  ; 
			int r = n ; 
			while(l<=r)
			{
				int mid =(l+r)/2;  
				if(value[mid-1]<val)
				{
					ans=mid; 
					l=mid+1; 
				}
				else 
				{
					r=mid-1; 
				}
			}
			if(ans==-1)
			{
				cout<<0<<"\n";
			}
			else 
			{
				cout<<sum(1,1,n,1,ans)<<"\n";
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