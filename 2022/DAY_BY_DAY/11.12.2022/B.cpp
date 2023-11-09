#include<bits/stdc++.h>
using namespace std;

#define TASK "B"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define int long long   
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second

#pragma CPP target("popcnt")
const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n ; 
vector<int>pos ; 
int la[20];
ll a[N] ;
ll s[N][10];
int tknp(int t , int p , int val,int pos)
{
	int l = t ; 
	int r = p ;
	int  ans = p+1;
	while(l<=r)
	{
		int mid =(l+r)/2;  
		int ma = 0 ;
		for(int i =0 ;i<=9;i++)
		{
			ma=max(ma,s[pos][i]-s[mid-1][i]);
		}
		if(ma>val)
		{
			l=mid+1; 
		}
		else 
		{
			ans= mid ; 
			r=mid-1;
		}
	}
	return p-ans+1;
}
void doc()
{
    cin>> n ; 
    FOR(i,1,n)
    {
    	char x ; cin>>x ; 
    	a[i]=x-'0';
    } 
    FOR(i,1,n)
    {
    	FOR( j,0,9)
    	{
    		s[i][j] = s[i-1][j] +(a[i]==j);
    	}
    }
    ll ans=  0 ;
    FOR(i,0,9)la[i] = 0 ;
    FOR(i,1,n)
    {
    	la[a[i]]= i ;
    	for(int j= 0 ;j<=9;j++)
    	{
    		if(la[j]!=0)pos.pb(la[j]);
    	}
    	sort(pos.begin(),pos.end(),greater<ll>());
    	for(int x = 0 ;x<(int)pos.size()-1;x++)
    	{	
    		ans+=tknp(pos[x+1]+1,pos[x],x+1,i);
    	}
    	ans+=tknp(1,pos[pos.size()-1],pos.size(),i);
    	pos.clear();
    }	
    cout<<ans<<"\n";
}

 main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    cin>>t;
    while(t--)
    {
        doc();
    }
}