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
int fac[N];
void input()
{
 	cin>> n;  
 	fac[0] = 1 ;
 	for(int i=1;i<=9;i++)
 	{
 		fac[i] =fac[i-1]*i ;
 	}
 	if(n==1)
 	{
 		cout<<0 ; 
 		return ; 
 	}
 	vector<int>ans; 
 	while(n) 
 	{
 		for(int j= 9 ;j>=0;j--)
 		{
 			if(n>=fac[j])
 			{
 				ans.pb(j) ; 
 				n-=fac[j];
 				break ; 
 			}
 		}
 	}
 	reverse(ans.begin(),ans.end());
 	for(int i = 0;i<ans.size();i++)cout<<ans[i];
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