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

int n ; 
string s1 ; 
int f[N][30]; 
vector<pii>q;
int a[N] ; 
int m  ;
int dd[N]; 
void input()
{
 	cin>>s1;
 	n=s1.size();  
 	s1='$'+s1;   
 	cin>>m ; 
 	for(int i=1 ;i<=m;i++)
 	{
 		int l ,r ; 
 		cin>> l>>r ;
 		q.pb({l,r}) ;
 	}
 	for(int i=1 ;i<=n;i++)cin>>a[i] ; 
}
bool check(int val)
{
	for(int i =1 ;i<=n;i++)
	{
		dd[i] = 1 ; 
	}
	for(int i=1 ;i<=val;i++)
	{
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
		
		int n ; 
		
		void input()
		{
		    
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
		dd[a[i]]=0; 
	}
	for(int i= 1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
		{
			f[i][j] =f[i-1][j] ; 
			if(dd[i])
			{
				f[i][j]+=(s1[i]==j+'a'); 
			}
		}
	}
	for(int i= 0 ;i<q.size();i++)
	{
		int l =q[i].fi ; 
		int r=  q[i].se ; 
		for(int j=0  ;j<26;j++)
		{
			if(f[r][j]-f[l-1][j]>1)
			{
				return 0 ; 
			}
		}
	}
	return 1 ; 
}	
void np1()
{
	int l = 0 ; 
	int r = n; 
	int ans= 0  ;  
	while(l<=r)
	{
		int mid =(l+r)/2; 
		if(check(mid))
		{
			ans= mid ;
			r=mid-1 ; 
		}
		else 
		{
			l=mid+1; 
		}
	}
	cout<<ans;  
}
void output()
{
 	np1();   
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