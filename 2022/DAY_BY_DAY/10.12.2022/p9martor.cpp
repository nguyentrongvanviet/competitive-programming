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
const int N =1e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=311,inf = 1e17;

int n ; 
ll mu[N] ; 
ll ha[N]  ,h[N] ;
int le[N]; 

unordered_map<ll,int>cnt[N];
void input()
{
 	cin>>n ;
 	string x ;  
 	for(int i =1;i<=n;i++)
 	{
 		cin>>x ; 
 		le[i] = (int)x.size();
 		for(int j= 0 ;j<le[i];j++)
 		{
 			ha[i] = (ha[i]*cs%sm+x[j])%sm;
 		} 
 		cnt[le[i]][ha[i]]++;
  	}   
}
void init()
{
	mu[0]=1;  
	for(int i=1;i<N;i++)
	{
		mu[i]=mu[i-1]*cs%sm;
	}
}
ll gets(int l , int r )
{
	return (h[r]-h[l-1]*mu[r-l+1]%sm+sm*sm)%sm;
}
ll f[N];
void output()
{
    string s ; 
    cin>> s  ;
    int m =s.size();
   	for(int i=0 ;i<m;i++)
   	{
   		h[i+1]=(h[i]*cs%sm+s[i])%sm;
   	}
   	f[0] = 1; 
   	for(int i=1 ;i<=m;i++)
   	{
   		for(int j=i;j>=max(1,i-100+1);j--)
   		{
   			ll x= gets(j,i);
   			if(cnt[i-j+1].find(x)==cnt[i-j+1].end())continue;
   			f[i]=(f[i]+cnt[i-j+1][x]*f[j-1]%sm)%sm;
   		}
   	}
   	cout<<f[m];
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
        init();
        output(); 
    }
    return 0;
}