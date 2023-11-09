#include<bits/stdc++.h>

#define TASK "union"
const bool multitest = false; 

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));; 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
#define pii pair<int,int>
#define vi vector<int>
#define ve vector
#define str string  
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b)  a/gcd(a,b)*b 
using namespace std;

const int N =2e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct hcn
{
	ll A , B , C; 
	ll X, Y , Z; 
}H[N];
str cong(str a, str b )
{
	while(a.size()<b.size())a='0'+a; 
	while(b.size()<a.size())b='0'+b;
	string ans= "";  
	int nho  =0 ; 
	for(int i= b.size()-1;i>=0;i--)
	{
		int tmp = nho+ a[i]-'0'+b[i]-'0' ; 
		int c= tmp%10 ; 
		nho = tmp/10 ; 
		ans=(char)(c+'0')+ans; 
	}
	if(nho)ans='1'+ans;		 
	return ans; 
}
str tru(str a , str b)
{
	while(b.size()<a.size())b='0'+b;
	str ans="" ; 
	int thieu =0 ;
	FORD(i,b.size()-1,0)
	{
		int tmp = a[i]-b[i]-thieu ; 
		if(tmp<0)thieu = 1 , tmp+=10; 
		else thieu = 0 ;
		int c= tmp%10;
		ans=(char)(c+'0')+ans; 
	}
	while(ans.size()>1&&ans[0]=='0')ans.erase(0,1);
	return ans ; 
}
str mul(str a , int b)
{
	str ans="";
	int nho = 0 ;
	FORD(i,a.size()-1,0)
	{
		int tmp = (a[i]-'0')*b+nho ; 
		nho=tmp/10;  
		int c= tmp%10;
		ans=(char)(c+'0')+ans;  
	}
	if(nho)ans=(char)(nho+'0')+ans;
	return ans;  
}
str nhan(str a, str b)
{
	str ans=""; 
	str zero = "" ;
	FORD(i,b.size()-1,0)
	{
		str tmp = mul(a,b[i]-'0');
		tmp+=zero;  
		ans=cong(ans,tmp);
		zero+="0"; 
	}
	return ans; 
}
int n ;
ll res= 0 ;
void read()
{
    cin>> n; 
    FORN(i,0,n)
    {
    	ll A , B , C , X , Y ,Z ; 
    	cin>>A >> B >> C>>X>>Y>>Z ;  
    	H[i].A = min(A,X) ; 
    	H[i].B = min(B,Y) ; 
    	H[i].C = min(C,Z) ; 
    	H[i].X = max(A,X) ; 
    	H[i].Y = max(B,Y) ; 
    	H[i].Z = max(C,Z) ;
    }
}
void process()
{
	FORN(msk,1,(1<<n))
	{
		ll A = -inf ; 
		ll B = -inf ; 
		ll C = -inf ;
		ll X = inf ; 
		ll Y = inf ; 
		ll Z = inf ;  
		FORN(i,0,n)
		{
			if(msk>>i&1)
			{
				A =max(A,H[i].A) ; 
				B =max(B,H[i].B) ; 
				C =max(C,H[i].C) ; 
				X =min(X,H[i].X) ; 
				Y =min(Y,H[i].Y) ; 
				Z =min(Z,H[i].Z) ; 
			}
		}
		if(A<=X&&B<=Y&&C<=Z)
		{	
			if(btpc(msk)&1)res+=(X-A)*(Y-B)*(Z-C);
			else res-=(X-A)*(Y-B)*(Z-C);
		}
	}	
	cout<<res;
}		
void print()
{
    
}
signed main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout); 
    }
    int test = 1;  
    if(multitest)cin>>test; 
    while(test--)
    {
        read() ; 
        process();
        print() ; 
    }
    
}
