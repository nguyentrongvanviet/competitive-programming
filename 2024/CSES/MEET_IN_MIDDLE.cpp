#include<bits/stdc++.h>
using namespace std;

#define TASK "MEET_IN_MIDDLE"

#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b) for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i = b;i>=a;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#define all(a) a.begin(),a.end()
const int N =20+5 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
int m ; 
int a[N]  ,b[N]; 
map<int,int>sl; 
void doc()
{
 	cin>> n >> m;
 	int mid =n/2; 
 	for(int i= 1;i<=n/2;i++)
 	{
 		cin>>a[i] ; 
 	}  
 	for(int i=1;i<=n-mid;i++)
 	{
 		cin>>b[i] ; 
 	}
	ll res = 0 ; 
 	sl[0] = 1; 
	int len = (1<<mid) ; 
	int s ; 
	for(int i= 1;i<len;i++)
 	{
 		s= 0  ;
		for(int msk = i ; msk;msk-=msk&-msk)
		{
			s+=a[__builtin_ctz(msk)+1];
			if(s>m)break;
		}
 		if(s<=m) sl[s]++;
 	}
	len = (1<<(n-mid)) ;
 	for(int i=0;i<len;i++)
 	{
		s= 0 ; 
		for(int msk=i;msk;msk-=msk&-msk)
		{
			s+=b[__builtin_ctz(msk)+1] ; 
			if(s>m)break;
		}
		if(s>m)continue;
		if(sl.find(m-s)!=sl.end()) 
		{
			res+=sl[m-s];
		}
 	}
 	cout<<res;
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
    }
    return 0;
}