#include<bits/stdc++.h>
using namespace std;

#define TASK "sseq"
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
const int N =1e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

struct R 
{
	int l ; 
	int r ; 
	ll val  ; 
	int id ; 
	bool operator <(const R&a )const
	{
		return r<a.r;
	}
};
ll bit[N] ; 
int n ;
ll get(int idx)
{
	ll val = 0 ; 
	for(int i= idx;i;i-=i&-i)
	{
		val+=bit[i] ; 
	}
	return val ; 
};
void up(int idx , ll val)
{ 
	for(int i= idx;i<=n;i+=i&-i)
	{
		bit[i]+=val; 
	}
}
bool cmp(R a , R b)
{
	return a.l<b.l;
}
int pos[N] ; 
R a[N] ; 
R b[N] ;
int L[N] ;
vector<int>q;
bool ok1=-1 ;  
void doc()
{ 	
 	cin>> n ; 
 	FOR(i,1,n)cin>>a[i].l>>a[i].r>>a[i].val,a[i].id= i;
 	int tmp  = 0 ; 
 	FOR(i,1,n)
 	{
 		if(ok1==-1)
 		{
 			tmp=a[i].r-a[i].l;
 			ok1=1 ;
 		}
 		else  if(ok1==1)
 		{
 			if(a[i].r-a[i].l!=tmp)
 			{
 				ok1=0 ; 
 			}
 		}
 	} 
}
void sub12()
{
	sort(a+1,a+n+1,cmp);
 	FOR(i,1,n)
 	{
 		L[i] = a[i].l ;
 		pos[a[i].id] = i ; 
 	}
 	sort(a+1,a+n+1) ; 
 	FOR(i,1,n)
 	{
 		q.pb(a[i].r) ; 
 	} 
 	q.resize(unique(q.begin(),q.end())-q.begin());
 	int m = q.size() ; 
 	int it=  1;  
 	ll res = 0;
 	for(int value : q )
 	{
 		while(a[it].r==value&&it<=n)
 		{
 			up(pos[a[it].id],a[it].val);
 			++it;  
 		}
 		for(int i=1 ;i<=it-1;i++)
 		{	
 			int pos = lower_bound(L+1,L+n+1,a[i].l)-L;
 			// cout<<get(n)-get(pos-1)<<"\n";
 			res=max(res,get(n)-get(pos-1));
 		}
 	}
 	cout<<res;
}
void sub3()
{
	sort(a+1,a+n+1) ;
	FOR(i,1,n)
	{
		q.pb(a[i].r);
	}
	sort(q.begin(),q.end());
	q.resize(unique(q.begin(),q.end())-q.begin());
	ll res= 0; 
	ll tmp = 0; 
	int it = 1 ; 
	for(int value : q )
	{
		while(a[it].r==value&&it<=n)
		{
			tmp+=a[it].val; 
			++it;
		}
		if(tmp<0)
		{
			tmp = 0 ; 
		}
		else 
		{
			res=max(res,tmp) ;
		}
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
        if(ok1==0&&n<=9000)sub12();
        else if(ok1==1)sub3();
    }
    return 0;
}