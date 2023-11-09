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
int a[N] ; 
int b[N];
void input()
{
	cin>> n ; 
	for(int i =1 ;i<=n;i++)
	{
		cin>>a[i] ; 
	}

}
int  check(int k , int sodau , int socuoi )
{
	b[1] =sodau; 
	b[2] =socuoi;
	for(int i=3;i<=n;i++)
	{
		b[i]=b[i-1]+k;
	}
	int ans= 0;  
	for(int i=1 ;i<=n;i++)
	{
		if(abs(a[i]-b[i])>1)return oo ; 
		ans+=abs(a[i]-b[i]);  
	}
	return ans ; 
}
void output()
{
	int res= oo ; 
	for(int j= a[2]-a[1]-2;j<=a[2]-a[1]+2;j++)
	{
		for(int t = a[1]-1;t<=a[1]+1;t++)
		{
			res=min(res,check(j,t,t+j)); 
		} 
	}	
	cout<<(res==oo?-1:res)<<"\n";  
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}