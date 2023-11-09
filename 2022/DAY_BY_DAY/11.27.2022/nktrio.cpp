#include<bits/stdc++.h>
using namespace std;

#define TASK "nktrio"

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

const int N=1e3+1,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ; 
bitset<N>a[N]  ; 
bitset<N>b[N] ;
void doc()
{
	cin>>n; 
	FOR(i,1,n)
	{
		FOR(j,1,n)
		{
			bool x; cin>>x;  
			if(i==j)
			{
				continue ;
			}
			if(x==1)
			{
				a[i].set(j);
				b[j].set(i);
			}
			else 
			{
				a[j].set(i); 
				b[i].set(j);
			}
		}
	} 
	FOR(i,1,n)
	{
		FOR(j,1,n)
		{
			if(a[i].test(j))
			{
				bitset<N>tmp = (b[i]&a[j]);
				if(tmp.any())
				{
					cout<<i<<" "<<j<<" ";
					FOR(t,1,n)
					{
						if(tmp.test(t))
						{
							cout<<t; 
							return ;
						}
					}
				}
			}
		}
	}
	cout<<-1<<" "<<-1<<" "<<-1;
}
void xuly()
{
    
}
int main()
{
    IOS();  
    doc(); 
 	xuly();
}