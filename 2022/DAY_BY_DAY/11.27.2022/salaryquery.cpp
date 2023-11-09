#include<bits/stdc++.h>
using namespace std;

#define TASK "salaryquery"

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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct Q
{
	int t , pos , val,  l , r ; 
};
Q query[N];
int n , m  , q;
vector<int>value ;
unordered_map<int,int>pos;
int a[N]; 
int bit[60*N] ; 
void up(int idx , int val)
{
	for(int i=idx;i<=m;i+=i&-i)bit[i]+=val;
}
int get(int idx )
{
	int ans = 0 ; 
	for(int i=idx;i;i-=i&-i)ans+=bit[i] ;
	return ans ; 
}
void doc()
{
 	cin>>n>>q;  
 	FOR(i,1,n)cin>>a[i],value.pb(a[i]);
 	FOR(i,1,q)
 	{
 		char x ; 
        cin>>x ;
 		if(x=='!')
 		{
            query[i].t=1; 
            cin>>query[i].pos>>query[i].val;
 			value.pb(query[i].val); 
 		}
 		else 
 		{
            query[i].t = 0;
            cin>>query[i].l>>query[i].r;
 			value.pb(query[i].l) ; 
 			value.pb(query[i].r) ; 
 		}
 	}  
 	sort(value.begin(),value.end()); 
 	value.resize(unique(value.begin(),value.end())-value.begin()); 
    m=value.size();
 	FOR(i,1,value.size())
 	{
 		pos[value[i-1]]= i ;
 	}
 	FOR(i,1,q)
 	{
 	 	if(query[i].t==1)
 		{
 			query[i].val=pos[query[i].val] ; 
 		}
 		else 
 		{	
 			query[i].l=pos[query[i].l] ;
 			query[i].r=pos[query[i].r] ; 
 		}
 	}
 	FOR(i,1,n)
 	{
 		a[i] = pos[a[i]] ; 
 		up(a[i],1); 
 	}
 	FOR(i,1,q)
 	{
 		int t= query[i].t; 
 		if(t==1)
 		{
 			int pos= query[i].pos ; 
 			int val = query[i].val; 
 			up(a[pos],-1) ;
            a[pos]=val;
 			up(val,1); 
 		}
 		else 
 		{
 			cout<<get(query[i].r)-get(query[i].l-1)<<"\n";
 		}
	}
}
void xuly()
{
    
}
int main()
{
    IOS();  
    doc(); 
    // xuly();
    cerr<<endl<<clock()<<" ms"<<endl; 
}