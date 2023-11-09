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
ll f[N];
ll a[N] , b[N] ; 
ll res=0 ; 
int pre[N] ; 
void input()
{
    cin>> n; 
    for(int i=1 ;i<=n;i++)
    {
    	cin>>a[i]>>b[i] ; 
    }
}
void output()
{
	f[n] = a[n];   
	f[n+1]=0 ; 
   	for(int i=n-1;i>=1;i--)
   	{
   		f[i] =min(a[i]+f[i+1],b[i]+f[i+2]);
   	}
   	vector<int>res(n+5) ; 
   	int i = 1 ;
   	while(i<=n)
   	{
   		if(a[i]+f[i+1]==f[i])
   		{
   			res[i]=1;
   			i+=1;
   		}
   		else 
   		{
   			res[i]=2; 
   			i+=2;
   		}
   	}
   	cout<<f[1]<<"\n"; 
   	for(int i=1 ;i<=n;i++)
   	{
   		cout<<res[i]<<" ";
   	}
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