#include<bits/stdc++.h>
using namespace std;

#define TASK "PAIR"
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
const int N =2e3+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

struct DL 
{
	int l , r , val ; 
	bool operator <(const DL& a)const
	{
		if(val==a.val)
		{
			if(l==a.l)
			{
				return r>a.r ; 
			}
			return l<a.l;
		}
		return val<a.val ; 
	}
};
int n  ,d ; 
int a[N] ; 
vector<DL>q ; 
int res = 0 ;
bool cmp(DL a ,DL b )
{
	return a.l<b.l||(a.l==b.l&&a.r>b.r);
}
void solve(vector<DL>q)
{
	int  l =0 ; 
	int r =  n +1;  
	int ans =0  ;
	sort(q.begin(),q.end(),cmp);
	FOR(i,0,q.size()-1)
	{		
		if(l<q[i].l&&q[i].r<r) 
		{
			++ans ; 
			l =q[i].l ; 
			r=q[i].r ; 
		}
	}
	res=max(res,ans); 
}
int tknp(int val)
{
	int l = 0 ; 
	int r =q.size()-1 ; 
	int ans=  q.size() ; 
	while(l<=r)
	{
		int mid =(l+r)/2; 
		if(q[mid].val>=val)
		{
			ans= mid; 
			r=mid-1; 
		}
		else 
		{
			l=mid+1; 
		}
	}
	return ans;  
}
void doc()
{
 	cin>> n >>d; 
 	FOR(i,1,n)cin>>a[i];
 	sort(a+1,a+n+1);  
 	vector<int>value ; 
 	FOR(i,1,n)
 	{
 		FOR(j,i+1,n)
 		{
 			q.pb({i,j,a[i]+a[j]});
 			value.pb(a[i]+a[j]); 
 		}
 	}   
 	sort(value.begin() ,value.end())  ; 
 	value.resize(unique(value.begin(),value.end())-value.begin());
 	sort(q.begin(),q.end());
 	for(int i= 0 ;i<value.size();i++)
 	{
 		int val = value[i] ; 
 		int it =tknp(val) ; 
 		if(it==q.size()||abs(q[it].val-val)>d)continue ; 
 		vector<DL>tmp; 
 		while(abs(q[it].val-val)<=d)
 		{
 			tmp.pb(q[it]) ; 
 			++it;  
 		} 	
 		solve(tmp);
 	}
 	cout<<res;
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