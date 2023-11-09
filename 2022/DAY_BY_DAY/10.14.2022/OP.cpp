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
const int N =5e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

struct query
{
	int l , r ,id ; 
};
int n , m ; 
query a[N] ;
unordered_map<int,int>dd;
vector<int>q;
void input()
{
 	cin>> n>> m;  
 	for(int i= 1 ;i<=m;i++)
 	{
 		cin>>a[i].l>>a[i].r ; 
 		string x ; 
 		cin>>x;  
 		a[i].id=(x=="even");
 	}
}
int pa[N]  ; 
int goc(int u)
{
	return pa[u]==u?u:pa[u]=goc(pa[u]) ; 
}
void hop(int u, int v )
{
	int chau = goc(u); 
	int chav = goc(v); 
	if(chau==chav)return ; 
	pa[chau]=chav; 
}
bool check(int idx)
{
	for(int i= 0;i<=5*n;i++)
	{
		pa[i] = i ; 
	}
	for(int i=1;i<=idx;i++)
	{
		if(a[i].id==1)
		{
			hop(dd[a[i].l]-1,dd[a[i].r]) ; 
		}
	}
	for(int i= 1;i<=idx;i++)
	{
		if(a[i].id==0)
		{
			int u = goc(dd[a[i].l]-1); 
			int v =	goc(dd[a[i].r]) ;
			if(pa[u]==pa[v])return 0 ; 
		}
	}
	return 1 ;
}
void output()
{
	n = 0;
	for(int i=1 ;i<=m;i++)
	{
		if(dd[a[i].l]==0)
		{
			n++;
			dd[a[i].l]=1 ; 
			q.pb(a[i].l) ; 
		}
		if(dd[a[i].r]==0)
		{
			n++;
			dd[a[i].r]=1; 
			q.pb(a[i].r);
		}
	}
	sort(q.begin(),q.end());
	dd[q[0]]=2;
	for(int i=1;i<q.size();i++)
	{
		if(q[i-1]+1==q[i])
		{
			dd[q[i]]=dd[q[i-1]]+1; 
		}
		else 
		{
			if(dd[q[i]]==dd[i-1]+2)
			{
				dd[q[i]]=dd[q[i-1]]+2;
			}
			else 
			{
				dd[q[i]]=dd[q[i-1]]+3;
			}
		}
	}
    int l =1 ;
    int r =m; 
    int ans ; 
    while(l<=r)
    {
    	int mid =(l+r)/2; 
    	if(check(mid))
    	{
    		ans=mid; 
    		l=mid+1; 
    	}
    	else 
    	{
    		r=mid-1 ; 
    	}
    } 
   	cout<<ans;  
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