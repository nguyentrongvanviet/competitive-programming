#include<bits/stdc++.h>
using namespace std;

#define TASK "DEGREE"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =30+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

ll C[N][N]; 
int n ;
ll x, y , k  ,b ; 
void doc()
{
 	cin>>x>>y>>k>>b; 
}
void init()
{
	C[0][0] =1 ; 
	for(int i= 1;i<=30;i++)
	{
		C[i][0] = 1; 
		for(int j = 1 ;j<=i;j++)
		{
			C[i][j] =C[i-1][j] +C[i-1][j-1];
		}
	}
}
ll sl(ll x  )
{
	ll ans= 0 ;    
	ll value = 0 ;
	for(int i= k;i>=1;i--)
	{
		for(int j =i-1;j<=30;j++)
		{
			ll val =  0;  
			int ok =1;  
			for(int t =j-i+1;t<=j;t++)
			{
				val+=pow(b,t); 
				if(value+val>x) 
				{
					ok = 0 ; 
					break ; 
				}
			}		
			if(ok==1)
			{
				ans+=C[j][i-1];		
			}
			else 
			{
				value+=pow(b,j);
				break;  
			}
		}
	}
	return ans; 
}
void xuly()
{
	cout<<sl(y)-sl(x-1); 
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
        init();
        xuly();
    }
    return 0;
}