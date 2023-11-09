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
int nt[N] ; 
void snt()
{
	for(ll i=2;i<N;i++)
	{
		if(nt[i]==0)
		{
			nt[i]= i;
			for( ll j =i*i;j<N;j+=i)
			{
				nt[j]=i;
			}
		}
	}
}
int a, b  ;
void input()
{
	cin>>a>>b; 
}
bool check(int val)
{
	int sum = 0; 
	int x= val ; 
	while(x)
	{
		sum+=x%10 ; 
		x/=10;
	}
	int res =1;
	x= val ; 
	while(x>1)
	{
		int u = nt[x] ; 
		int cnt = 0 ; 
		while(x%u==0)
		{
			x/=u; 
			cnt++ ; 
		}
		res*=(cnt+1);
	}
	return (nt[sum]==sum&&res%2==0);
}
void output()
{
	ll res=0 ; 
    for(int i=a;i<=b;i++)
	{
		res+=check(i);
	}
	cout<<res;
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
    	snt();
        input();
        output(); 
    }
    return 0;
}