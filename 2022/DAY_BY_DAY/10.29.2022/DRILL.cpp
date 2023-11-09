#include<bits/stdc++.h>
using namespace std;

#define TASK "DRILL"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =800+15 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n ; 
int a[N];
int ma= 0;
int f[N*2][2] ;
void doc()
{
	cin>> n; 
	ma= 0  ;
	for(int i =1 ;i<=n;i++)cin>>a[i],ma=max(ma,a[i])  ; 
}
bool check(int l )
{
	bool ok ;
	memset(f,0,sizeof(f)) ; 
	for(int i=1;i<=l;i++)
	{
		f[i][0]=1;  
	}
	for(int j= 1;j<=n;j++)
	{
		ok = 0 ;
		int jj=  (j&1); 
		for(int i=1 ;i<=l;i++)
		{
			f[i][jj]= 0;
			if(i-a[j]>=1)
			{
				f[i][jj]|=f[i-a[j]][1-jj] ;
			}
			if(i+a[j]<=l)
			{
				f[i][jj]|=f[i+a[j]][1-jj] ;
			}
			ok|= f[i][jj] ;
		}
		if(ok==0)return 0;
	}
	return 1 ; 
}
void get(int l )
{
	memset(f,0,sizeof(f)) ; 
	for(int i=1;i<=l;i++)
	{
		f[i][0]=1;  
	}
	int st ;
	for(int j= 1;j<=n;j++)
	{
		int jj=  (j&1); 
		for(int i=1 ;i<=l;i++)
		{
			f[i][jj]= 0;
			if(i-a[j]>=1)
			{
				f[i][jj]|=f[i-a[j]][1-jj] ;
			}
			if(i+a[j]<=l)
			{
				f[i][jj]|=f[i+a[j]][1-jj] ;
			}
			if(f[i][jj])
			{#include<bits/stdc++.h>
			using namespace std;
			
			#define TASK ""
			
			#define ll long long
			#define pb push_back
			#define pk pop_back
			#define FOR(i,a,b) for(int i= a;i<=b;i++)
			#define FORD(i,a,b) for(int i = b;i>=a;i--)
			#define pii pair<int,int>
			#define fi first 
			#define se second  
			#define all(a) a.begin(),a.end()
			const int N =2e5+5 ,  oo = 2e9 ;
			const ll sm = 1e9+7,cs=330 ,inf = 1e17;
			
			int n ; 
			void doc()
			{		
			    
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
				st=i;
			}
		}
	}
	string res="";
	for(int i=n;i>=1;i--)
	{
		int jj = (i&1) ;
		if(st-a[i]>0)
		{
			if(f[st-a[i]][1-jj])
			{
				st-=a[i];
				res+='R';
				continue ; 
			}
		}
		res+='L' ;
		st+=a[i] ; 
	}
	reverse(res.begin(),res.end());  
	cout<<res<<"\n";
}
void xuly()
{
	int l = ma; 
	int r = 2*ma+4; 
	int ans= 0 ; 
	while(l<=r)
	{
		int mid =(l+r)/2; 
		if(check(mid))
		{
			ans =mid ; 
			r=mid-1 ; 
		}
		else 
		{
			l=mid+1; 
		}
	}
	get(ans);
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
    cin>>t;
    while(t--)
    {
    	doc() ; 
    	xuly() ;
    }
    return 0;
}