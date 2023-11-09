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
const int N =2e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
ll nt[N] ;
ll s1[N] ,s2[N] ;  
void snt()
{
	for(ll i =2 ;i<N;i++)
	{
		if(nt[i]==0)
		{
			nt[i] = i ;
			for(ll j =i*i;j<N;j+=i)
			{
				nt[j] = i  ;
			}
		}
	}
}

void tinh(ll val)
{
	ll ans1=1 ;
	ll ans2=1; 
	ll t= val;
	while(val>1)
	{
		// cout<<val<<endl;
		ll cnt =0  ;
		ll x= nt[val]; 
		// cout<<val<<endl;
		// cout<<x<<endl;
		ll tu = 1 ;
		while(val%x==0)
		{
			cnt++ ; 
			val/=x;
			tu*=x; 
		}
		ans2*=(tu*x-1)/(x-1);
		ans1*=(cnt+1);
	}
	s1[t] =s1[t-1]+ans1;
	s2[t] = s2[t-1]+ans2;
}
void init()
{

	for(ll i=1 ;i<N;i++)
	{
		tinh(i);	
	}
}
void input()
{
	int l  , r ;
	cin>>l>>r ; 
	cout<<s1[r]-s1[l-1]<<" "<<s2[r]-s2[l-1]<<"\n";
}
void output()
{
    
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("NATDIV.INP","r",stdin); 
    freopen("NATDIV.OUT","w",stdout); 
    snt() ;
    init();
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