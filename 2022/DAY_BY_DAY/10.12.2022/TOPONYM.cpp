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
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ;
int node=1 ; 
int T[N*20][25];
int f[N*20]; 
int res= 0 ;
void up(string s )
{
	int r= 1; 
	for(int i= 0 ;i<s.size();i++)
	{
		int j=  s[i]-'A' ; 
		if(T[r][j]==0)
		{
			T[r][j]=++node; 
		}
		r=T[r][j] ; 
		f[r]++ ; 
	}
}
void get(string s )
{
	int r= 1 ; 
	for(int i = 0 ;i<s.size();i++)
	{
		int j =s[i]-'A' ;
		r=T[r][j] ;  	
		res=max(res,f[r]*(i+1));
	}
}
void input()
{
    cin>> n ; 
    for(int i= 1;i<=n;i++)
    {
    	string s;
    	cin>>s ;    
    	up(s);
    	get(s);   
    }
    cout<<res;
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