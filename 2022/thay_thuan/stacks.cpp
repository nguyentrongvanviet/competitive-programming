#include<bits/stdc++.h>
using namespace std;

#define TASK "stacks"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ; 
stack<int>st[N] ; 
queue<int>q[N] ; 
void doc()
{
	cin>> n; 
 	FOR(i,1,(1<<n))
 	{
 		int val  ; cin>>val  ; 
 		q[1].push(val) ; 
 	}
}

void solve(int l , int r , int pos  )
{
	if(pos==2*n+1)return ;
	if(pos&1)
	{
		int mid =(l+r)/2 ; 
		while(!q[pos].empty())
		{
			int u= q[pos].front() ; 
			q[pos].pop() ; 
			if(u<=mid)
			{
				cout<<pos<<" "<<pos+1<<" ";
				q[pos+2].push(u) ;
			}
			else
			{
				cout<<pos<<" ";
				st[pos+1].push(u) ; 
			}
		}
		solve(l,mid,pos+2) ;  
		solve(mid+1,r,pos+1) ;
	} 
	else
	{
		while(!st[pos].empty())
		{
			int u= st[pos].top() ; 
			st[pos].pop(); 
			q[pos+1].push(u) ; 
			cout<<pos<<" ";
		}
		solve(l,r,pos+1);
	}
}
void xuly()
{
    solve(1,(1<<n),1);
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}
