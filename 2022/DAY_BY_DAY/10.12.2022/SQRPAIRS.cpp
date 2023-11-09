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
const int N =1e7+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

ll n ; 
int dd[N] ; 
int cnt = 0 ; 
ll res =0 ; 
void input()
{
 	cin>> n;  
}
void output()
{
    for(int i= 1;i<=n;i++)
 	{
 		ll cnt = 0;  
 		if(dd[i]==0)
 		{
 			for(int j= 1;1LL*i*j*j<=n;j++)
 			{
 				dd[i*j*j]=1 ; 
 				cnt++ ; 
 			}
 			res+=cnt*(cnt-1)/2;
 		}
 	}   
 	cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("SQRPAIRS.INP","r",stdin); 
    freopen("SQRPAIRS.OUT","w",stdout); 
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