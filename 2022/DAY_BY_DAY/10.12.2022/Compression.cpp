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
const int N =3e4+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ,q ;  
int T[N*31][26] ; 
int node= 1; 
vector<int>a[N*31] ;  
int en[N*31] ; 
void up(string s,int id  )
{
	int r= 1;  
	for(int i=0;i<s.size();i++)
	{
		int j= s[i]-'a'; 
		if(T[r][j]==0)
		{
			T[r][j]=++node; 
		}
		r=T[r][j] ; 
		a[r].pb(id); 
	}
	en[r] =id ; 
}
int get(string s  )
{
	int r= 1 ; 
	int id =1;
	for(int i= 0 ;i<s.size();i++)
	{
		int j =s[i]-'a'; 
		if(T[r][j]==0)
		{
			id=-1; 
		}
		r=T[r][j];
	}
	if(en[r]&&id==1)
	{
		id=en[r] ; 
	}
	else 
	{
		id=-1 ;
	}
	if(id==-1)
	{
		int r= 1 ; 
		int ans =0  ; 
		for(int i= 0 ; i<s.size();i++)
		{
			int j = s[i]-'a';
			for(int t = 0 ;t<26;t++)
			{
				ans+=a[T[r][t]].size();
			}
			r=T[r][j]; 
			ans+=(en[r]>0);
		}
		for(int j= 0;j<26;j++)
		{
			ans+=a[T[r][j]].size();
		}
		return ans ; 
	}
	else 
	{
		int ans= 0 ; 
		int r =1 ; 
		for(int i= 0 ; i <s.size();i++)
		{
			int j =s[i]-'a';
			for(int t= 0 ; t<26;t++)
			{
				int u = T[r][t];
				if(a[u].size()==0)continue;
				ans+=(upper_bound(a[u].begin(),a[u].end(),id)-a[u].begin());
			}
			r=T[r][j];
			ans+=(en[r]!=0&&en[r]<=id);  
		}
		for(int i= 0 ;i<26;i++)
		{
			int u = T[r][i];
			if(a[u].size()==0)continue;
			ans+=(upper_bound(a[u].begin(),a[u].end(),id)-a[u].begin());
		}
		return ans;  
	}
}
void input()
{
	cin>> n ; 
	for(int i=1 ;i<=n;i++)
	{
		string s; cin>> s; up(s,i) ;  
	}
	cin>> q; 
	for(int i=1 ;i<=q;i++)
	{
		string s  ; cin>> s;  
		cout<<get(s)<<"\n";
	}
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