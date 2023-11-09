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
const int N =1e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

ll n , m , s; 
ll dd[N]; 
ll a[N]  ,b[N];
int f[N];
void input()
{
    cin>> m >> n>> s;   
    for(int i=1 ;i<=n;i++)
    {
    	cin>>a[i] >> b[i ];  
    }
}	
void output()
{
 	queue<int> q; 
 	q.push(s); 
 	f[s]= 0; 
 	while(!q.empty())
 	{
 		int u= q.front() ; 
 		q.pop()  ; 
 		for(int i= 1 ;i<=n;i++)
 		{
 			ll ns= (u*a[i]+ b[i])%m;
 			if(dd[ns])continue ; 
 			dd[ns]=1; 
 			f[ns]= f[u]+1;
 			q.push(ns) ; 
 			if(ns==0)
 			{
 				cout<<f[ns];
 				return ; 
 			}
 		}
 	}   
 	cout<<-1;
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